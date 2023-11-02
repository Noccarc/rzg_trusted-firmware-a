#
# Copyright (c) 2021-2023, Renesas Electronics Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

PLAT_SOC_RZG2L					:= 1
BL2_AT_EL3						:= 1
COLD_BOOT_SINGLE_CPU			:= 1
PROGRAMMABLE_RESET_ADDRESS		:= 1
WARMBOOT_ENABLE_DCACHE_EARLY	:= 1
GICV3_SUPPORT_GIC600			:= 1
HW_ASSISTED_COHERENCY			:= 1
USE_COHERENT_MEM				:= 0
TRUSTED_BOARD_BOOT				:= 0
PROTECTED_CHIPID				:= 1
DEBUG_FPGA						:= 0
PLAT_EMMC_WRITE_ENABLE			:= 0

$(eval $(call add_define,PLAT_SOC_RZG2L))
$(eval $(call add_define,PROTECTED_CHIPID))
$(eval $(call add_define,DEBUG_FPGA))

WA_RZG2L_GIC64BIT				:= 1
$(eval $(call add_define,WA_RZG2L_GIC64BIT))

# This option gets enabled automatically if the TRUSTED_BOARD_BOOT
# is set via root Makefile, but Renesas support Trusted-Boot without
# Crypto module.
override CRYPTO_SUPPORT			:= 0

# Enable workarounds for selected Cortex-A55 erratas.
ERRATA_A55_1530923				:= 1

ifndef SPI_FLASH
  SPI_FLASH = MT25QU512ABB
endif

PLAT_INCLUDES			:=	-Iplat/renesas/rz/common/include						\
							-Iplat/renesas/rz/common/drivers/emmc					\
							-Iplat/renesas/rz/common/drivers/io						\
							-Idrivers/renesas/common/io								\
							-Iplat/renesas/rz/common/include/drivers/spi_multi		\
							-Iplat/renesas/rz/common/include/drivers/spi_multi/${SPI_FLASH} \
							-Iplat/renesas/rz/common/drivers/sd

RZ_TIMER_SOURCES		:=	drivers/delay_timer/generic_delay_timer.c				\
							drivers/delay_timer/delay_timer.c

DDR_SOURCES				:=	plat/renesas/rz/common/drivers/ddr/ddr.c

EMMC_SOURCES			:=	plat/renesas/rz/common/drivers/emmc/emmc_interrupt.c	\
							plat/renesas/rz/common/drivers/emmc/emmc_utility.c		\
							plat/renesas/rz/common/drivers/emmc/emmc_mount.c		\
							plat/renesas/rz/common/drivers/emmc/emmc_init.c			\
							plat/renesas/rz/common/drivers/emmc/emmc_read.c			\
							plat/renesas/rz/common/drivers/emmc/emmc_cmd.c			\
							plat/renesas/rz/common/drivers/emmc/emmc_write.c

SPI_MULTI_SOURCE 		:=	plat/renesas/rz/common/drivers/spi_multi/spi_multi.c	\
							plat/renesas/rz/common/drivers/spi_multi/${SPI_FLASH}/spi_multi_device.c

SD_SOURCES				:=	plat/renesas/rz/common/drivers/sd/sd_init.c				\
							plat/renesas/rz/common/drivers/sd/sd_mount.c			\
							plat/renesas/rz/common/drivers/sd/sd_util.c				\
							plat/renesas/rz/common/drivers/sd/sd_cd.c				\
							plat/renesas/rz/common/drivers/sd/sd_cmd.c				\
							plat/renesas/rz/common/drivers/sd/sd_int.c				\
							plat/renesas/rz/common/drivers/sd/sd_trns.c				\
							plat/renesas/rz/common/drivers/sd/sd_read.c				\
							plat/renesas/rz/common/drivers/sd/sd_write.c			\
							plat/renesas/rz/common/drivers/sd/sd_dev_low.c

BL_COMMON_SOURCES		+=	lib/cpus/aarch64/cortex_a55.S							\
							drivers/arm/tzc/tzc400.c

include lib/xlat_tables_v2/xlat_tables.mk
PLAT_BL_COMMON_SOURCES	:=	${XLAT_TABLES_LIB_SRCS}									\
							plat/renesas/rz/common/aarch64/plat_helpers.S			\
							plat/renesas/rz/common/drivers/scifa.S					\
							plat/renesas/rz/common/drivers/syc.c					\
							plat/renesas/rz/common/drivers/sys.c					\
							plat/renesas/rz/common/drivers/cpg.c					\
							plat/renesas/rz/common/plat_rz_common.c					\
							plat/renesas/rz/common/plat_security.c

ifneq (${ENABLE_STACK_PROTECTOR},0)
PLAT_BL_COMMON_SOURCES	+=	plat/renesas/rz/common/rz_stack_protector.c
endif

BL2_SOURCES				+=	common/desc_image_load.c								\
							drivers/io/io_storage.c									\
							drivers/io/io_memmap.c									\
							drivers/io/io_fip.c										\
							plat/renesas/rz/common/drivers/io/io_emmcdrv.c			\
							plat/renesas/rz/common/drivers/io/io_sddrv.c			\
							plat/renesas/rz/common/bl2_plat_setup.c					\
							plat/renesas/rz/common/bl2_plat_mem_params_desc.c		\
							plat/renesas/rz/common/plat_image_load.c				\
							plat/renesas/rz/common/plat_storage.c					\
							plat/renesas/rz/common/drivers/pfc.c					\
							${RZ_TIMER_SOURCES}										\
							${EMMC_SOURCES}											\
							${SPI_MULTI_SOURCE}										\
							${SD_SOURCES}

# Include GICv3 driver files
include drivers/arm/gic/v3/gicv3.mk

BL31_SOURCES			+=	plat/common/plat_gicv3.c								\
							plat/common/plat_psci_common.c							\
							plat/renesas/rz/common/bl31_plat_setup.c				\
							plat/renesas/rz/common/plat_pm.c						\
							plat/renesas/rz/common/plat_topology.c					\
							plat/renesas/rz/common/plat_gic.c						\
							plat/renesas/rz/common/rz_plat_sip_handler.c			\
							plat/renesas/rz/common/rz_sip_svc.c						\
							${GICV3_SOURCES}

ifneq (${TRUSTED_BOARD_BOOT},0)

	# Include common TBB sources
	AUTH_SOURCES		:=	drivers/auth/img_parser_mod.c

	# Include the selected chain of trust sources.
	ifeq (${COT},tbbr)
		AUTH_SOURCES	+=	plat/renesas/rz/common/drivers/auth/tbbr/tbbr_cot.c
	else
		$(error Unknown chain of trust ${COT})
	endif

	# Include RZ TBB sources
	AUTH_SOURCES		+=	plat/renesas/rz/common/drivers/auth/auth_mod.c				\
							plat/renesas/rz/common/drivers/auth/sblib/crypto_sblib.c	\
							plat/renesas/rz/common/drivers/auth/sblib/sblib_parser.c


	BL2_SOURCES			+=	${AUTH_SOURCES}

endif
