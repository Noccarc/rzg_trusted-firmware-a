/*
 * Copyright (c) 2020, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <string.h>

#include <libfdt.h>

#include <platform_def.h>

#include <arch_helpers.h>
#include <bl1/bl1.h>
#include <common/bl_common.h>
#include <common/debug.h>
#include <common/desc_image_load.h>
#include <drivers/console.h>
#include <lib/mmio.h>
#include <lib/xlat_tables/xlat_tables_defs.h>
#include <plat/common/platform.h>

#include "boot_init_dram.h"
#include "cpg_registers.h"
#include "board.h"
#include "emmc_def.h"
#include "emmc_hal.h"
#include "emmc_std.h"

#if PMIC_ROHM_BD9571 && RZG_SYSTEM_RESET_KEEPON_DDR
#include "iic_dvfs.h"
#endif

#include "io_common.h"
#include "qos_init.h"
#include "rzg_def.h"
#include "rzg_private.h"
#include "rzg_version.h"
#include "rom_api.h"

#if RZG_BL2_DCACHE == 1
/*
 * Following symbols are only used during plat_arch_setup() only
 * when RZG_BL2_DCACHE is enabled.
 */
#define BL2_RO_BASE		BL_CODE_BASE
#define BL2_RO_LIMIT		BL_CODE_END

#if USE_COHERENT_MEM
#define BL2_COHERENT_RAM_BASE	BL_COHERENT_RAM_BASE
#define BL2_COHERENT_RAM_LIMIT	BL_COHERENT_RAM_END
#endif

#endif

extern void plat_rzg_gic_driver_init(void);
extern void plat_rzg_gic_init(void);
extern void bl2_enter_bl31(const struct entry_point_info *bl_ep_info);
extern void bl2_system_cpg_init(void);
extern void bl2_secure_setting(void);
extern void bl2_cpg_init(void);
extern void rzg_io_emmc_setup(void);
extern void rzg_io_setup(void);
extern void rzg_swdt_release(void);
extern void rzg_swdt_init(void);
extern void rzg_rpc_init(void);
extern void rzg_pfc_init(void);
extern void rzg_dma_init(void);
extern void bl2_ecc_init(uint32_t major, uint32_t minor);

static void bl2_init_generic_timer(void);

/* RZ/G Gen2 product check */
#if RZG_LSI == RZG_G2H
#define TARGET_PRODUCT			PRR_PRODUCT_G2H
#define TARGET_NAME			"RZ/G2H"
#elif RZG_LSI == RZG_G2M
#define TARGET_PRODUCT			PRR_PRODUCT_G2M
#define TARGET_NAME			"RZ/G2M"
#elif RZG_LSI == RZG_G2N
#define TARGET_PRODUCT			PRR_PRODUCT_G2N
#define TARGET_NAME			"RZ/G2N"
#elif RZG_LSI == RZG_G2E
#define TARGET_PRODUCT			PRR_PRODUCT_G2E
#define TARGET_NAME			"RZ/G2E"
#elif RZG_LSI == RZG_AUTO
#define TARGET_NAME			"RZ/G2M/N/H"
#endif

#if (RZG_LSI != RZG_G2E)
#define GPIO_INDT			(GPIO_INDT1)
#define GPIO_BKUP_TRG_SHIFT		((uint32_t)1U<<8U)
#endif

CASSERT((PARAMS_BASE + sizeof(bl2_to_bl31_params_mem_t) + 0x100)
	 < (RZG_SHARED_MEM_BASE + RZG_SHARED_MEM_SIZE),
	assert_bl31_params_do_not_fit_in_shared_memory);

static meminfo_t bl2_tzram_layout __aligned(CACHE_WRITEBACK_GRANULE);

/* FDT with DRAM configuration */
uint64_t fdt_blob[PAGE_SIZE_4KB / sizeof(uint64_t)];
static void *fdt = (void *)fdt_blob;

static void unsigned_num_print(unsigned long long int unum, unsigned int radix,
				char *string)
{
	/* Just need enough space to store 64 bit decimal integer */
	char num_buf[20];
	int i = 0;
	unsigned int rem;

	do {
		rem = unum % radix;
		if (rem < 0xa)
			num_buf[i] = '0' + rem;
		else
			num_buf[i] = 'a' + (rem - 0xa);
		i++;
		unum /= radix;
	} while (unum > 0U);

	while (--i >= 0)
		*string++ = num_buf[i];
}

#if (RZG_LOSSY_ENABLE == 1)
typedef struct bl2_lossy_info {
	uint32_t magic;
	uint32_t a0;
	uint32_t b0;
} bl2_lossy_info_t;

static void bl2_lossy_gen_fdt(uint32_t no, uint64_t start_addr,
			      uint64_t end_addr, uint32_t format,
			      uint32_t enable, int fcnlnode)
{
	const uint64_t fcnlsize = cpu_to_fdt64(end_addr - start_addr);
	char nodename[40] = { 0 };
	int ret, node;

	/* Ignore undefined addresses */
	if (start_addr == 0 && end_addr == 0)
		return;

	snprintf(nodename, sizeof(nodename), "lossy-decompression@");
	unsigned_num_print(start_addr, 16, nodename + strlen(nodename));

	node = ret = fdt_add_subnode(fdt, fcnlnode, nodename);
	if (ret < 0) {
		NOTICE("BL2: Cannot create FCNL node (ret=%i)\n", ret);
		panic();
	}

	ret = fdt_setprop_string(fdt, node, "compatible",
				 "renesas,lossy-decompression");
	if (ret < 0) {
		NOTICE("BL2: Cannot add FCNL compat string (ret=%i)\n", ret);
		panic();
	}

	ret = fdt_appendprop_string(fdt, node, "compatible",
				    "shared-dma-pool");
	if (ret < 0) {
		NOTICE("BL2: Cannot append FCNL compat string (ret=%i)\n", ret);
		panic();
	}

	ret = fdt_setprop_u64(fdt, node, "reg", start_addr);
	if (ret < 0) {
		NOTICE("BL2: Cannot add FCNL reg prop (ret=%i)\n", ret);
		panic();
	}

	ret = fdt_appendprop(fdt, node, "reg", &fcnlsize, sizeof(fcnlsize));
	if (ret < 0) {
		NOTICE("BL2: Cannot append FCNL reg size prop (ret=%i)\n", ret);
		panic();
	}

	ret = fdt_setprop(fdt, node, "no-map", NULL, 0);
	if (ret < 0) {
		NOTICE("BL2: Cannot add FCNL no-map prop (ret=%i)\n", ret);
		panic();
	}

	ret = fdt_setprop_u32(fdt, node, "renesas,formats", format);
	if (ret < 0) {
		NOTICE("BL2: Cannot add FCNL formats prop (ret=%i)\n", ret);
		panic();
	}
}

static void bl2_lossy_setting(uint32_t no, uint64_t start_addr,
			      uint64_t end_addr, uint32_t format,
			      uint32_t enable, int fcnlnode)
{
	bl2_lossy_info_t info;
	uint32_t reg;

	bl2_lossy_gen_fdt(no, start_addr, end_addr, format, enable, fcnlnode);

	reg = format | (start_addr >> 20);
	mmio_write_32(AXI_DCMPAREACRA0 + 0x8 * no, reg);
	mmio_write_32(AXI_DCMPAREACRB0 + 0x8 * no, end_addr >> 20);
	mmio_write_32(AXI_DCMPAREACRA0 + 0x8 * no, reg | enable);

	info.magic = 0x12345678U;
	info.a0 = mmio_read_32(AXI_DCMPAREACRA0 + 0x8 * no);
	info.b0 = mmio_read_32(AXI_DCMPAREACRB0 + 0x8 * no);

	mmio_write_32(LOSSY_PARAMS_BASE + sizeof(info) * no, info.magic);
	mmio_write_32(LOSSY_PARAMS_BASE + sizeof(info) * no + 0x4, info.a0);
	mmio_write_32(LOSSY_PARAMS_BASE + sizeof(info) * no + 0x8, info.b0);

	NOTICE("     Entry %d: DCMPAREACRAx:0x%x DCMPAREACRBx:0x%x\n", no,
	       mmio_read_32(AXI_DCMPAREACRA0 + 0x8 * no),
	       mmio_read_32(AXI_DCMPAREACRB0 + 0x8 * no));
}
#endif

void bl2_plat_flush_bl31_params(void)
{
	uint32_t product_cut, product, cut;
	uint32_t boot_dev, boot_cpu;
	uint32_t reg;

	reg = mmio_read_32(RZG_MODEMR);
	boot_dev = reg & MODEMR_BOOT_DEV_MASK;

	if (boot_dev == MODEMR_BOOT_DEV_EMMC_25X1 ||
	    boot_dev == MODEMR_BOOT_DEV_EMMC_50X8)
		emmc_terminate();

	if ((reg & MODEMR_BOOT_CPU_MASK) != MODEMR_BOOT_CPU_CR7)
		bl2_secure_setting();

	reg = mmio_read_32(RZG_PRR);
	product_cut = reg & (PRR_PRODUCT_MASK | PRR_CUT_MASK);
	product = reg & PRR_PRODUCT_MASK;
	cut = reg & PRR_CUT_MASK;

	if (product == PRR_PRODUCT_G2M && PRR_PRODUCT_30 > cut)
		goto tlb;

	/* Disable MFIS write protection */
	mmio_write_32(MFISWPCNTR, MFISWPCNTR_PASSWORD | 1);

tlb:
	reg = mmio_read_32(RZG_MODEMR);
	boot_cpu = reg & MODEMR_BOOT_CPU_MASK;
	if (boot_cpu != MODEMR_BOOT_CPU_CA57 &&
	    boot_cpu != MODEMR_BOOT_CPU_CA53)
		goto mmu;

	if (product == PRR_PRODUCT_G2N) {
		mmio_write_32(IPMMUVI0_IMSCTLR, IMSCTLR_DISCACHE);
		mmio_write_32(IPMMUPV0_IMSCTLR, IMSCTLR_DISCACHE);
	} else if ((product_cut == (PRR_PRODUCT_G2E | PRR_PRODUCT_10)) ||
		   (product_cut == (PRR_PRODUCT_G2E | PRR_PRODUCT_11))) {
		mmio_write_32(IPMMUVI0_IMSCTLR, IMSCTLR_DISCACHE);
		mmio_write_32(IPMMUVP0_IMSCTLR, IMSCTLR_DISCACHE);
		mmio_write_32(IPMMUPV0_IMSCTLR, IMSCTLR_DISCACHE);
	}

	if ((product == PRR_PRODUCT_G2N) ||
	    (product_cut == (PRR_PRODUCT_G2E | PRR_PRODUCT_10))) {
		mmio_write_32(IPMMUHC_IMSCTLR, IMSCTLR_DISCACHE);
		mmio_write_32(IPMMURT_IMSCTLR, IMSCTLR_DISCACHE);
		mmio_write_32(IPMMUMP_IMSCTLR, IMSCTLR_DISCACHE);

		mmio_write_32(IPMMUDS0_IMSCTLR, IMSCTLR_DISCACHE);
		mmio_write_32(IPMMUDS1_IMSCTLR, IMSCTLR_DISCACHE);
	}

mmu:
	mmio_write_32(IPMMUMM_IMSCTLR, IPMMUMM_IMSCTLR_ENABLE);
	mmio_write_32(IPMMUMM_IMAUXCTLR, IPMMUMM_IMAUXCTLR_NMERGE40_BIT);

	rzg_swdt_release();
	bl2_system_cpg_init();

#if RZG_BL2_DCACHE == 1
	/* Disable data cache (clean and invalidate) */
	disable_mmu_el3();
#endif
}

static uint32_t is_ddr_backup_mode(void)
{
#if RZG_SYSTEM_SUSPEND
	static uint32_t reason = RZG_COLD_BOOT;
	static uint32_t once;

#if PMIC_ROHM_BD9571 && RZG_SYSTEM_RESET_KEEPON_DDR
	uint8_t data;
#endif
	if (once)
		return reason;

	once = 1;
	if ((mmio_read_32(GPIO_INDT) & GPIO_BKUP_TRG_SHIFT) == 0)
		return reason;

#if PMIC_ROHM_BD9571 && RZG_SYSTEM_RESET_KEEPON_DDR
	if (rzg_iic_dvfs_receive(PMIC, REG_KEEP10, &data)) {
		ERROR("BL2: REG Keep10 READ ERROR.\n");
		panic();
	}

	if (KEEP10_MAGIC != data)
		reason = RZG_WARM_BOOT;
#else
	reason = RZG_WARM_BOOT;
#endif
	return reason;
#else
	return RZG_COLD_BOOT;
#endif
}

int bl2_plat_handle_pre_image_load(unsigned int image_id)
{
	u_register_t *boot_kind = (void *) BOOT_KIND_BASE;
	bl_mem_params_node_t *bl_mem_params;

	if (image_id != BL31_IMAGE_ID)
		return 0;

	bl_mem_params = get_bl_mem_params_node(image_id);

	if (is_ddr_backup_mode() == RZG_COLD_BOOT)
		goto cold_boot;

	*boot_kind  = RZG_WARM_BOOT;
	flush_dcache_range(BOOT_KIND_BASE, sizeof(*boot_kind));

	console_flush();
	bl2_plat_flush_bl31_params();

	/* will not return */
	bl2_enter_bl31(&bl_mem_params->ep_info);

cold_boot:
	*boot_kind  = RZG_COLD_BOOT;
	flush_dcache_range(BOOT_KIND_BASE, sizeof(*boot_kind));

	return 0;
}

int bl2_plat_handle_post_image_load(unsigned int image_id)
{
	static bl2_to_bl31_params_mem_t *params;
	bl_mem_params_node_t *bl_mem_params;

	if (!params) {
		params = (bl2_to_bl31_params_mem_t *) PARAMS_BASE;
		memset((void *)PARAMS_BASE, 0, sizeof(*params));
	}

	bl_mem_params = get_bl_mem_params_node(image_id);

	switch (image_id) {
	case BL31_IMAGE_ID:
		break;
	case BL32_IMAGE_ID:
		memcpy(&params->bl32_ep_info, &bl_mem_params->ep_info,
			sizeof(entry_point_info_t));
		break;
	case BL33_IMAGE_ID:
		memcpy(&params->bl33_ep_info, &bl_mem_params->ep_info,
			sizeof(entry_point_info_t));
		break;
	}

	return 0;
}

struct meminfo *bl2_plat_sec_mem_layout(void)
{
	return &bl2_tzram_layout;
}

static void bl2_populate_compatible_string(void *dt)
{
	uint32_t board_type;
	uint32_t board_rev;
	uint32_t reg;
	int ret;

	fdt_setprop_u32(fdt, 0, "#address-cells", 2);
	fdt_setprop_u32(fdt, 0, "#size-cells", 2);

	/* Populate compatible string */
	rzg_get_board_type(&board_type, &board_rev);
	switch (board_type) {
	case BOARD_HIHOPE_RZG2H:
	case BOARD_HIHOPE_RZG2M:
	case BOARD_HIHOPE_RZG2N:
		ret = fdt_setprop_string(fdt, 0, "compatible",
					 "renesas,hihope");
		break;
	case BOARD_EK874:
		ret = fdt_setprop_string(fdt, 0, "compatible",
					 "renesas,ek874");
		break;
	default:
		NOTICE("BL2: Cannot set compatible string, board unsupported\n");
		panic();
	}

	if (ret < 0) {
		NOTICE("BL2: Cannot set compatible string (ret=%i)\n", ret);
		panic();
	}

	reg = mmio_read_32(RZG_PRR);
	switch (reg & PRR_PRODUCT_MASK) {
	case PRR_PRODUCT_G2H:
		ret = fdt_appendprop_string(fdt, 0, "compatible",
					    "renesas,r8a774e1");
		break;
	case PRR_PRODUCT_G2M:
		ret = fdt_appendprop_string(fdt, 0, "compatible",
					    "renesas,r8a774a1");
		break;
	case PRR_PRODUCT_G2N:
		ret = fdt_appendprop_string(fdt, 0, "compatible",
					    "renesas,r8a774b1");
		break;
	case PRR_PRODUCT_G2E:
		ret = fdt_appendprop_string(fdt, 0, "compatible",
					    "renesas,r8a774c0");
		break;
	default:
		NOTICE("BL2: Cannot set compatible string, SoC unsupported\n");
		panic();
	}

	if (ret < 0) {
		NOTICE("BL2: Cannot set compatible string (ret=%i)\n", ret);
		panic();
	}
}

static void bl2_advertise_dram_entries(uint64_t dram_config[8])
{
	char nodename[32] = { 0 };
	uint64_t start, size;
	uint64_t fdtsize;
	int ret, node, chan;

	for (chan = 0; chan < 4; chan++) {
		start = dram_config[2 * chan];
		size = dram_config[2 * chan + 1];
		if (!size)
			continue;

		NOTICE("BL2: CH%d: %llx - %llx, %lld %siB\n",
			chan, start, start + size - 1,
			(size >> 30) ? : size >> 20,
			(size >> 30) ? "G" : "M");
	}

	/*
	 * We add the DT nodes in reverse order here. The fdt_add_subnode()
	 * adds the DT node before the first existing DT node, so we have
	 * to add them in reverse order to get nodes sorted by address in
	 * the resulting DT.
	 */
	for (chan = 3; chan >= 0; chan--) {
		start = dram_config[2 * chan];
		size = dram_config[2 * chan + 1];
		if (!size)
			continue;

		/*
		 * Channel 0 is mapped in 32bit space and the first
		 * 128 MiB are reserved
		 */
		if (chan == 0) {
			if (size > 0x80000000) {
				start = dram_config[2 * chan] + 0x80000000;
				size -= 0x80000000;
				fdtsize = cpu_to_fdt64(size);

				snprintf(nodename, sizeof(nodename), "memory@");
				unsigned_num_print(start, 16, nodename + strlen(nodename));
				node = ret = fdt_add_subnode(fdt, 0, nodename);
				if (ret < 0)
					goto err;

				ret = fdt_setprop_string(fdt, node, "device_type", "memory");
				if (ret < 0)
					goto err;

				ret = fdt_setprop_u64(fdt, node, "reg", start);
				if (ret < 0)
					goto err;

				ret = fdt_appendprop(fdt, node, "reg", &fdtsize,
				sizeof(fdtsize));
				if (ret < 0)
					goto err;
				}

			start = 0x48000000;
			size -= 0x8000000;
		}

		fdtsize = cpu_to_fdt64(size);

		snprintf(nodename, sizeof(nodename), "memory@");
		unsigned_num_print(start, 16, nodename + strlen(nodename));
		node = ret = fdt_add_subnode(fdt, 0, nodename);
		if (ret < 0)
			goto err;

		ret = fdt_setprop_string(fdt, node, "device_type", "memory");
		if (ret < 0)
			goto err;

		ret = fdt_setprop_u64(fdt, node, "reg", start);
		if (ret < 0)
			goto err;

		ret = fdt_appendprop(fdt, node, "reg", &fdtsize,
					 sizeof(fdtsize));
		if (ret < 0)
			goto err;
	}

	return;
err:
	NOTICE("BL2: Cannot add memory node to FDT (ret=%i)\n", ret);
	panic();
}

static void bl2_advertise_dram_size(uint32_t product)
{
	uint64_t dram_config[8] = {
		[0] = 0x400000000ULL,
		[2] = 0x500000000ULL,
		[4] = 0x600000000ULL,
		[6] = 0x700000000ULL,
	};

	switch (product) {
	case PRR_PRODUCT_G2H:
#if (RZG_DRAM_LPDDR4_MEMCONF == 0)
		/* 4GB(1GBx4) */
		dram_config[1] = 0x40000000ULL;
		dram_config[3] = 0x40000000ULL;
		dram_config[5] = 0x40000000ULL;
		dram_config[7] = 0x40000000ULL;
#elif (RZG_DRAM_LPDDR4_MEMCONF == 1) && \
      (RZG_DRAM_CHANNEL        == 5) && \
      (RZG_DRAM_SPLIT          == 2)
		/* 4GB(2GBx2 2ch split) */
		dram_config[1] = 0x80000000ULL;
		dram_config[3] = 0x80000000ULL;
#elif (RZG_DRAM_LPDDR4_MEMCONF == 1) && (RZG_DRAM_CHANNEL == 15)
		/* 8GB(2GBx4: default) */
		dram_config[1] = 0x80000000ULL;
		dram_config[3] = 0x80000000ULL;
		dram_config[5] = 0x80000000ULL;
		dram_config[7] = 0x80000000ULL;
#endif /* RZG_DRAM_LPDDR4_MEMCONF == 0 */
		break;

	case PRR_PRODUCT_G2M:
		/* 4GB(2GBx2 2ch split) */
		dram_config[1] = 0x80000000ULL;
		dram_config[5] = 0x80000000ULL;
		break;

	case PRR_PRODUCT_G2N:
		/* 4GB(2GBx2) */
		dram_config[1] = 0x100000000ULL;
		break;

	case PRR_PRODUCT_G2E:
#if (RZG_DRAM_DDR3L_MEMCONF == 0)
		/* 1GB(512MBx2) */
		dram_config[1] = 0x40000000ULL;
#elif (RZG_DRAM_DDR3L_MEMCONF == 1)
		/* 2GB(512MBx4) */
		dram_config[1] = 0x80000000ULL;
#elif (RZG_DRAM_DDR3L_MEMCONF == 2)
		/* 4GB(1GBx4) */
		dram_config[1] = 0x100000000ULL;
#endif /* RZG_DRAM_DDR3L_MEMCONF == 0 */
		break;

	}

	bl2_advertise_dram_entries(dram_config);
}

void bl2_el3_early_platform_setup(u_register_t arg1, u_register_t arg2,
				  u_register_t arg3, u_register_t arg4)
{
	uint32_t reg, midr, lcs, boot_dev, boot_cpu, sscg, type, rev;
	uint32_t product, major, minor;
	int32_t ret;
	const char *str;
	const char *unknown = "unknown";
	const char *cpu_ca57 = "CA57";
	const char *cpu_ca53 = "CA53";
	const char *product_g2h = "G2H";
	const char *product_g2m = "G2M";
	const char *product_g2n = "G2N";
	const char *product_g2e = "G2E";
	const char *lcs_secure = "SE";
	const char *lcs_cm = "CM";
	const char *lcs_dm = "DM";
	const char *lcs_sd = "SD";
	const char *lcs_fa = "FA";
	const char *sscg_off = "PLL1 nonSSCG Clock select";
	const char *sscg_on = "PLL1 SSCG Clock select";
	const char *boot_hyper80 = "HyperFlash(80MHz)";
	const char *boot_qspi40 = "QSPI Flash(40MHz)";
	const char *boot_qspi80 = "QSPI Flash(80MHz)";
	const char *boot_emmc25x1 = "eMMC(25MHz x1)";
	const char *boot_emmc50x8 = "eMMC(50MHz x8)";
#if (RZG_LSI == RZG_G2E)
	const char *boot_hyper160 = "HyperFlash(150MHz)";
#else
	const char *boot_hyper160 = "HyperFlash(160MHz)";
#endif
#if (RZG_LOSSY_ENABLE == 1)
	int fcnlnode;
#endif

	bl2_init_generic_timer();

	reg = mmio_read_32(RZG_MODEMR);
	boot_dev = reg & MODEMR_BOOT_DEV_MASK;
	boot_cpu = reg & MODEMR_BOOT_CPU_MASK;

	bl2_cpg_init();

	if (boot_cpu == MODEMR_BOOT_CPU_CA57 ||
	    boot_cpu == MODEMR_BOOT_CPU_CA53) {
		rzg_pfc_init();
		rzg_console_boot_init();
	}

	plat_rzg_gic_driver_init();
	plat_rzg_gic_init();
	rzg_swdt_init();

	/* FIQ interrupts are taken to EL3 */
	write_scr_el3(read_scr_el3() | SCR_FIQ_BIT);

	write_daifclr(DAIF_FIQ_BIT);

	reg = read_midr();
	midr = reg & (MIDR_PN_MASK << MIDR_PN_SHIFT);
	switch (midr) {
	case MIDR_CA57:
		str = cpu_ca57;
		break;
	case MIDR_CA53:
		str = cpu_ca53;
		break;
	default:
		str = unknown;
		break;
	}

	NOTICE("BL2: RZ/G Initial Program Loader(%s) Rev.%s\n", str,
	       version_of_renesas);

	reg = mmio_read_32(RZG_PRR);
	product = reg & PRR_PRODUCT_MASK;

	switch (product) {
	case PRR_PRODUCT_G2H:
		str = product_g2h;
		break;
	case PRR_PRODUCT_G2M:
		str = product_g2m;
		break;
	case PRR_PRODUCT_G2N:
		str = product_g2n;
		break;
	case PRR_PRODUCT_G2E:
		str = product_g2e;
		break;
	default:
		str = unknown;
		break;
	}

	major = 0;
	minor = 0;

	if ((PRR_PRODUCT_G2M == product) &&
	    (PRR_PRODUCT_20 == (reg & RZG_MAJOR_MASK))) {
		if (RZG_G2M_CUT_VER11 == (reg & PRR_CUT_MASK)) {
			/* G2M Ver.1.1 or Ver.1.2 */
			NOTICE("BL2: PRR is RZG %s Ver.1.1 / Ver.1.2\n",
				str);
		} else {
			NOTICE("BL2: PRR is RZG %s Ver.1.%d\n",
				str,
				(reg & RZG_MINOR_MASK) + RZG_G2M_MINOR_OFFSET);
		}
	} else {
		major = (reg & RZG_MAJOR_MASK) >> RZG_MAJOR_SHIFT;
		major = major + RZG_MAJOR_OFFSET;
		minor = reg & RZG_MINOR_MASK;
		NOTICE("BL2: PRR is RZG %s Ver.%d.%d\n", str, major, minor);
	}

	if (product == PRR_PRODUCT_G2E) {
		reg = mmio_read_32(RZG_MODEMR);
		sscg = reg & RZG_SSCG_MASK;
		str = sscg == RZG_SSCG_ENABLE ? sscg_on : sscg_off;
		NOTICE("BL2: %s\n", str);
	}

	rzg_get_board_type(&type, &rev);

	switch (type) {
	case BOARD_HIHOPE_RZG2H:
	case BOARD_HIHOPE_RZG2M:
	case BOARD_HIHOPE_RZG2N:
	case BOARD_EK874:
		break;
	default:
		type = BOARD_UNKNOWN;
		break;
	}

	if (type == BOARD_UNKNOWN || rev == BOARD_REV_UNKNOWN)
		NOTICE("BL2: Board is %s Rev.---\n", GET_BOARD_NAME(type));
	else {
		NOTICE("BL2: Board is %s Rev.%d.%d\n",
		       GET_BOARD_NAME(type),
		       GET_BOARD_MAJOR(rev), GET_BOARD_MINOR(rev));
	}

#if (RZG_LSI != RZG_AUTO)
	if (product != TARGET_PRODUCT) {
		ERROR("BL2: IPL was been built for the %s.\n", TARGET_NAME);
		ERROR("BL2: Please write the correct IPL to flash memory.\n");
		panic();
	}
#endif
	switch (boot_dev) {
	case MODEMR_BOOT_DEV_HYPERFLASH160:
		str = boot_hyper160;
		break;
	case MODEMR_BOOT_DEV_HYPERFLASH80:
		str = boot_hyper80;
		break;
	case MODEMR_BOOT_DEV_QSPI_FLASH40:
		str = boot_qspi40;
		break;
	case MODEMR_BOOT_DEV_QSPI_FLASH80:
		str = boot_qspi80;
		break;
	case MODEMR_BOOT_DEV_EMMC_25X1:
		str = boot_emmc25x1;
		break;
	case MODEMR_BOOT_DEV_EMMC_50X8:
		str = boot_emmc50x8;
		break;
	default:
		str = unknown;
		break;
	}
	NOTICE("BL2: Boot device is %s\n", str);

	reg = rzg_rom_get_lcs(&lcs);
	if (reg) {
		str = unknown;
		goto lcm_state;
	}

	switch (lcs) {
	case LCS_CM:
		str = lcs_cm;
		break;
	case LCS_DM:
		str = lcs_dm;
		break;
	case LCS_SD:
		str = lcs_sd;
		break;
	case LCS_SE:
		str = lcs_secure;
		break;
	case LCS_FA:
		str = lcs_fa;
		break;
	default:
		str = unknown;
		break;
	}

lcm_state:
	NOTICE("BL2: LCM state is %s\n", str);

	is_ddr_backup_mode();

	bl2_tzram_layout.total_base = BL31_BASE;
	bl2_tzram_layout.total_size = BL31_LIMIT - BL31_BASE;

	if (boot_cpu == MODEMR_BOOT_CPU_CA57 ||
	    boot_cpu == MODEMR_BOOT_CPU_CA53) {
		ret = rzg_dram_init();
		if (ret) {
			NOTICE("BL2: Failed to DRAM initialize (%d).\n", ret);
			panic();
		}
		rzg_qos_init();
	}

	bl2_ecc_init(major, minor);

	/* Set up FDT */
	ret = fdt_create_empty_tree(fdt, sizeof(fdt_blob));
	if (ret) {
		NOTICE("BL2: Cannot allocate FDT for U-Boot (ret=%i)\n", ret);
		panic();
	}

	/* Add platform compatible string */
	bl2_populate_compatible_string(fdt);

	/* Print DRAM layout */
	bl2_advertise_dram_size(product);

	if (boot_dev == MODEMR_BOOT_DEV_EMMC_25X1 ||
	    boot_dev == MODEMR_BOOT_DEV_EMMC_50X8) {
		if (rzg_emmc_init() != EMMC_SUCCESS) {
			NOTICE("BL2: Failed to eMMC driver initialize.\n");
			panic();
		}
		rzg_emmc_memcard_power(EMMC_POWER_ON);
		if (rzg_emmc_mount() != EMMC_SUCCESS) {
			NOTICE("BL2: Failed to eMMC mount operation.\n");
			panic();
		}
	} else {
		rzg_rpc_init();
		rzg_dma_init();
	}

	reg = mmio_read_32(RST_WDTRSTCR);
	reg &= ~WDTRSTCR_RWDT_RSTMSK;
	reg |= WDTRSTCR_PASSWORD;
	mmio_write_32(RST_WDTRSTCR, reg);

	mmio_write_32(CPG_CPGWPR, CPGWPR_PASSWORD);
	mmio_write_32(CPG_CPGWPCR, CPGWPCR_PASSWORD);

	reg = mmio_read_32(RZG_PRR);
	if ((reg & RZG_CPU_MASK_CA57) == RZG_CPU_HAVE_CA57)
		mmio_write_32(CPG_CA57DBGRCR,
			      DBGCPUPREN | mmio_read_32(CPG_CA57DBGRCR));

	if ((reg & RZG_CPU_MASK_CA53) == RZG_CPU_HAVE_CA53)
		mmio_write_32(CPG_CA53DBGRCR,
			      DBGCPUPREN | mmio_read_32(CPG_CA53DBGRCR));

#if (RZG_LOSSY_ENABLE == 1)
	NOTICE("BL2: Lossy Decomp areas\n");

	fcnlnode = fdt_add_subnode(fdt, 0, "reserved-memory");
	if (fcnlnode < 0) {
		NOTICE("BL2: Cannot create reserved mem node (ret=%i)\n",
			fcnlnode);
		panic();
	}

	bl2_lossy_setting(0, LOSSY_ST_ADDR0, LOSSY_END_ADDR0,
			  LOSSY_FMT0, LOSSY_ENA_DIS0, fcnlnode);
	bl2_lossy_setting(1, LOSSY_ST_ADDR1, LOSSY_END_ADDR1,
			  LOSSY_FMT1, LOSSY_ENA_DIS1, fcnlnode);
	bl2_lossy_setting(2, LOSSY_ST_ADDR2, LOSSY_END_ADDR2,
			  LOSSY_FMT2, LOSSY_ENA_DIS2, fcnlnode);
#endif

	fdt_pack(fdt);
	NOTICE("BL2: FDT at %p\n", fdt);

	if (boot_dev == MODEMR_BOOT_DEV_EMMC_25X1 ||
	    boot_dev == MODEMR_BOOT_DEV_EMMC_50X8)
		rzg_io_emmc_setup();
	else
		rzg_io_setup();
}

void bl2_el3_plat_arch_setup(void)
{
#if RZG_BL2_DCACHE == 1
	NOTICE("BL2: D-Cache enable\n");
	rzg_configure_mmu_el3(BL2_BASE,
			       BL2_END - BL2_BASE,
			       BL2_RO_BASE, BL2_RO_LIMIT
#if USE_COHERENT_MEM
			       , BL2_COHERENT_RAM_BASE, BL2_COHERENT_RAM_LIMIT
#endif
	    );
#endif
}

void bl2_platform_setup(void)
{

}

static void bl2_init_generic_timer(void)
{
#if (RZG_LSI == RZG_G2E)
	uint32_t reg_cntfid = EXTAL_EK874;
#else /* RZG_LSI == RZG_G2E */
	uint32_t reg_cntfid;
	uint32_t modemr;
	uint32_t modemr_pll;
	uint32_t pll_table[] = {
		EXTAL_MD14_MD13_TYPE_0,	/* MD14/MD13 : 0b00 */
		EXTAL_MD14_MD13_TYPE_1,	/* MD14/MD13 : 0b01 */
		EXTAL_MD14_MD13_TYPE_2,	/* MD14/MD13 : 0b10 */
		EXTAL_MD14_MD13_TYPE_3	/* MD14/MD13 : 0b11 */
	};

	modemr = mmio_read_32(RZG_MODEMR);
	modemr_pll = (modemr & MODEMR_BOOT_PLL_MASK);

	/* Set frequency data in CNTFID0 */
	reg_cntfid = pll_table[modemr_pll >> MODEMR_BOOT_PLL_SHIFT];
#endif /* RZG_LSI == RZG_G2E */
	/* Update memory mapped and register based freqency */
	write_cntfrq_el0((u_register_t )reg_cntfid);
	mmio_write_32(ARM_SYS_CNTCTL_BASE + (uintptr_t)CNTFID_OFF, reg_cntfid);
	/* Enable counter */
	mmio_setbits_32(RZG_CNTC_BASE + (uintptr_t)CNTCR_OFF,
			(uint32_t)CNTCR_EN);
}
