/*
 * Copyright (c) 2022, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __SYS_REGS_H__
#define __SYS_REGS_H__

#include <rz_soc_def.h>						/* Get the System base address */

#define SYS_MSTACCCTL0						(SYS_BASE + 0x00000000)
#define SYS_MSTACCCTL1						(SYS_BASE + 0x00000004)
#define SYS_MSTACCCTL2						(SYS_BASE + 0x00000008)
#define SYS_MSTACCCTL6						(SYS_BASE + 0x00000018)

#define SYS_SLVACCCTL0						(SYS_BASE + 0x00000100)
#define SYS_SLVACCCTL2						(SYS_BASE + 0x00000108)
#define SYS_SLVACCCTL3						(SYS_BASE + 0x0000010C)
#define SYS_SLVACCCTL4						(SYS_BASE + 0x00000110)
#define SYS_SLVACCCTL5						(SYS_BASE + 0x00000114)
#define SYS_SLVACCCTL6						(SYS_BASE + 0x00000118)
#define SYS_SLVACCCTL7						(SYS_BASE + 0x0000011C)
#define SYS_SLVACCCTL8						(SYS_BASE + 0x00000120)
#define SYS_SLVACCCTL9						(SYS_BASE + 0x00000124)
#define SYS_SLVACCCTL10						(SYS_BASE + 0x00000128)
#define SYS_SLVACCCTL11						(SYS_BASE + 0x0000012C)
#define SYS_SLVACCCTL12						(SYS_BASE + 0x00000130)
#define SYS_SLVACCCTL14						(SYS_BASE + 0x00000138)
#define SYS_SLVACCCTL16						(SYS_BASE + 0x00000140)
#define SYS_SLVACCCTL17						(SYS_BASE + 0x00000144)
#define SYS_SLVACCCTL18						(SYS_BASE + 0x00000148)
#define SYS_SLVACCCTL20						(SYS_BASE + 0x00000150)

#define SYS_RAM0_ECC						(SYS_BASE + 0x00000200)
#define SYS_RAM0_EN							(SYS_BASE + 0x00000204)
#define SYS_RAM1_ECC						(SYS_BASE + 0x00000210)
#define SYS_RAM1_EN							(SYS_BASE + 0x00000214)
#define SYS_RAM2_ECC						(SYS_BASE + 0x00000220)
#define SYS_RAM2_EN							(SYS_BASE + 0x00000224)
#define SYS_RAM3_ECC						(SYS_BASE + 0x00000230)
#define SYS_RAM3_EN							(SYS_BASE + 0x00000234)

#define SYS_WDT0_CTRL						(SYS_BASE + 0x00000250)
#define SYS_WDT1_CTRL						(SYS_BASE + 0x00000260)
#define SYS_WDT2_CTRL						(SYS_BASE + 0x00000270)

#define SYS_DDR_CFG							(SYS_BASE + 0x00000300)
#define SYS_DDR_MCAR_CTRL					(SYS_BASE + 0x00000304)
#define SYS_DDR_MCAR_SRCTL0					(SYS_BASE + 0x00000314)

#define SYS_XSPI_MAP_STAADD_CS0				(SYS_BASE + 0x00000348)
#define SYS_XSPI_MAP_ENDADD_CS0				(SYS_BASE + 0x0000034C)
#define SYS_XSPI_MAP_STAADD_CS1				(SYS_BASE + 0x00000350)
#define SYS_XSPI_MAP_ENDADD_CS1				(SYS_BASE + 0x00000354)

#define SYS_GETH0_CFG						(SYS_BASE + 0x00000380)
#define SYS_GETH1_CFG						(SYS_BASE + 0x00000390)

#define SYS_I2C0_CFG						(SYS_BASE + 0x00000400)
#define SYS_I2C1_CFG						(SYS_BASE + 0x00000410)
#define SYS_I2C2_CFG						(SYS_BASE + 0x00000420)
#define SYS_I2C3_CFG						(SYS_BASE + 0x00000430)

#define SYS_I3C_CFG							(SYS_BASE + 0x00000440)

#define SYS_CA55_CFG_RVAL0					(SYS_BASE + 0x00000818)
#define SYS_CA55_CFG_RVAH0					(SYS_BASE + 0x0000081C)

#define SYS_CM33_CFG0						(SYS_BASE + 0x00000844)
#define SYS_CM33_CFG1						(SYS_BASE + 0x00000848)
#define SYS_CM33_CFG2						(SYS_BASE + 0x0000084C)
#define SYS_CM33_CFG3						(SYS_BASE + 0x00000850)
#define SYS_CM33_LOCK						(SYS_BASE + 0x00000854)

#define SYS_CM33FPU_CFG0					(SYS_BASE + 0x00000884)
#define SYS_CM33FPU_CFG1					(SYS_BASE + 0x00000888)
#define SYS_CM33FPU_CFG2					(SYS_BASE + 0x0000088C)
#define SYS_CM33FPU_CFG3					(SYS_BASE + 0x00000890)
#define SYS_CM33FPU_LOCK					(SYS_BASE + 0x00000894)

#define SYS_LSI_MODE						(SYS_BASE + 0x00000A00)
#define SYS_LSI_DEVID						(SYS_BASE + 0x00000A04)
#define SYS_LSI_PRR							(SYS_BASE + 0x00000A08)

#define SYS_AOF0							(SYS_BASE + 0x00000C00)
#define SYS_AOF1							(SYS_BASE + 0x00000C04)
#define SYS_AOF2							(SYS_BASE + 0x00000C08)
#define SYS_AOF3							(SYS_BASE + 0x00000C0C)
#define SYS_AOF6							(SYS_BASE + 0x00000C18)
#define SYS_AOF9							(SYS_BASE + 0x00000C24)

#define SYS_LP_CTL2							(SYS_BASE + 0x00000D08)
#define SYS_LP_CTL6							(SYS_BASE + 0x00000D18)

#define SYS_PD_ISO_CTRL						(SYS_BASE + 0x00000D60)
#define PWRDN_DDRPHY_CTRL					(SYS_BASE + 0x00000D68)
#define ISO_IOBUF_SE18_CTRL					(SYS_BASE + 0x00000D6C)
#define SYS_USB_PWRRDY						(SYS_BASE + 0x00000D70)
#define SYS_PCIE_RST_RSM_B					(SYS_BASE + 0x00000D74)

#define SYS_GPREG_0							(SYS_BASE + 0x00000E00)
#define SYS_GPREG_1							(SYS_BASE + 0x00000E04)
#define SYS_GPREG_2							(SYS_BASE + 0x00000E08)
#define SYS_GPREG_3							(SYS_BASE + 0x00000E0C)

#define SYS_IPCONT_SEL_SPI_OCTA				(SYS_BASE + 0x00000E20)
#define SYS_IPCONT_IDAUZERONS				(SYS_BASE + 0x00000E24)
#define SYS_IPCONT_IDAUZERONS_FPU			(SYS_BASE + 0x00000E28)

#define MSTACCCTL0_DMAC0_AWPU				(1 << 0)
#define MSTACCCTL0_DMAC0_AWNS				(1 << 1)
#define MSTACCCTL0_DMAC0_AWSEL				(1 << 3)
#define MSTACCCTL0_DMAC0_ARPU				(1 << 4)
#define MSTACCCTL0_DMAC0_ARNS				(1 << 5)
#define MSTACCCTL0_DMAC0_ARSEL				(1 << 7)
#define MSTACCCTL0_DMAC1_AWPU				(1 << 8)
#define MSTACCCTL0_DMAC1_AWNS				(1 << 9)
#define MSTACCCTL0_DMAC1_AWSEL				(1 << 11)
#define MSTACCCTL0_DMAC1_ARPU				(1 << 12)
#define MSTACCCTL0_DMAC1_ARNS				(1 << 13)
#define MSTACCCTL0_DMAC1_ARSEL				(1 << 15)

#define MSTACCCTL1_SDHI0_AWPU				(1 << 0)
#define MSTACCCTL1_SDHI0_AWNS				(1 << 1)
#define MSTACCCTL1_SDHI0_AWSEL				(1 << 3)
#define MSTACCCTL1_SDHI0_ARPU				(1 << 4)
#define MSTACCCTL1_SDHI0_ARNS				(1 << 5)
#define MSTACCCTL1_SDHI0_ARSEL				(1 << 7)
#define MSTACCCTL1_SDHI1_AWPU				(1 << 8)
#define MSTACCCTL1_SDHI1_AWNS				(1 << 9)
#define MSTACCCTL1_SDHI1_AWSEL				(1 << 11)
#define MSTACCCTL1_SDHI1_ARPU				(1 << 12)
#define MSTACCCTL1_SDHI1_ARNS				(1 << 13)
#define MSTACCCTL1_SDHI1_ARSEL				(1 << 15)
#define MSTACCCTL1_GEther0_AWPU				(1 << 16)
#define MSTACCCTL1_GEther0_AWNS				(1 << 17)
#define MSTACCCTL1_GEther0_AWSEL			(1 << 19)
#define MSTACCCTL1_GEther0_ARPU				(1 << 20)
#define MSTACCCTL1_GEther0_ARNS				(1 << 21)
#define MSTACCCTL1_GEther0_ARSEL			(1 << 23)
#define MSTACCCTL1_GEther1_AWPU				(1 << 24)
#define MSTACCCTL1_GEther1_AWNS				(1 << 25)
#define MSTACCCTL1_GEther1_AWSEL			(1 << 27)
#define MSTACCCTL1_GEther1_ARPU				(1 << 28)
#define MSTACCCTL1_GEther1_ARNS				(1 << 29)
#define MSTACCCTL1_GEther1_ARSEL			(1 << 31)
#define MSTACCCTL2_USB2_0H_AWPU				(1 << 0)
#define MSTACCCTL2_USB2_0H_AWNS				(1 << 1)
#define MSTACCCTL2_USB2_0H_AWSEL			(1 << 3)
#define MSTACCCTL2_USB2_0H_ARPU				(1 << 4)
#define MSTACCCTL2_USB2_0H_ARNS				(1 << 5)
#define MSTACCCTL2_USB2_0H_ARSEL			(1 << 7)
#define MSTACCCTL2_USB2_0D_AWPU				(1 << 8)
#define MSTACCCTL2_USB2_0D_AWNS				(1 << 9)
#define MSTACCCTL2_USB2_0D_AWSEL			(1 << 11)
#define MSTACCCTL2_USB2_0D_ARPU				(1 << 12)
#define MSTACCCTL2_USB2_0D_ARNS				(1 << 13)
#define MSTACCCTL2_USB2_0D_ARSEL			(1 << 15)
#define MSTACCCTL2_USB2_1H_AWPU				(1 << 16)
#define MSTACCCTL2_USB2_1H_AWNS				(1 << 17)
#define MSTACCCTL2_USB2_1H_AWSEL			(1 << 19)
#define MSTACCCTL2_USB2_1H_ARPU				(1 << 20)
#define MSTACCCTL2_USB2_1H_ARNS				(1 << 21)
#define MSTACCCTL2_USB2_1H_ARSEL			(1 << 23)
#define MSTACCCTL6_SDHI2_AWPU				(1 << 0)
#define MSTACCCTL6_SDHI2_AWNS				(1 << 1)
#define MSTACCCTL6_SDHI2_AWSEL				(1 << 3)
#define MSTACCCTL6_SDHI2_ARPU				(1 << 4)
#define MSTACCCTL6_SDHI2_ARNS				(1 << 5)
#define MSTACCCTL6_SDHI2_ARSEL				(1 << 7)
#define MSTACCCTL6_PCIE_AWPU				(1 << 8)
#define MSTACCCTL6_PCIE_AWNS				(1 << 9)
#define MSTACCCTL6_PCIE_AWSEL				(1 << 11)
#define MSTACCCTL6_PCIE_ARPU				(1 << 12)
#define MSTACCCTL6_PCIE_ARNS				(1 << 13)
#define MSTACCCTL6_PCIE_ARSEL				(1 << 15)

#define SLVACCCTL0_SRAM0_SL_00				(0 << 0)
#define SLVACCCTL0_SRAM0_SL_01				(1 << 0)
#define SLVACCCTL0_SRAM0_SL_10				(2 << 0)
#define SLVACCCTL0_SRAM0_SL_11				(3 << 0)
#define SLVACCCTL0_SRAM1_SL_00				(0 << 2)
#define SLVACCCTL0_SRAM1_SL_01				(1 << 2)
#define SLVACCCTL0_SRAM1_SL_10				(2 << 2)
#define SLVACCCTL0_SRAM1_SL_11				(3 << 2)
#define SLVACCCTL0_SRAM2_SL_00				(0 << 4)
#define SLVACCCTL0_SRAM2_SL_01				(1 << 4)
#define SLVACCCTL0_SRAM2_SL_10				(2 << 4)
#define SLVACCCTL0_SRAM2_SL_11				(3 << 4)
#define SLVACCCTL0_SRAM3_SL_00				(0 << 6)
#define SLVACCCTL0_SRAM3_SL_01				(1 << 6)
#define SLVACCCTL0_SRAM3_SL_10				(2 << 6)
#define SLVACCCTL0_SRAM3_SL_11				(3 << 6)
#define SLVACCCTL2_TZC0_SL_10				(2 << 0)
#define SLVACCCTL2_TZC0_SL_11				(3 << 0)
#define SLVACCCTL2_TZC1_SL_10				(2 << 2)
#define SLVACCCTL2_TZC1_SL_11				(3 << 2)
#define SLVACCCTL2_TZC2_SL_10				(2 << 4)
#define SLVACCCTL2_TZC2_SL_11				(3 << 4)
#define SLVACCCTL2_TZC3_SL_10				(2 << 6)
#define SLVACCCTL2_TZC3_SL_11				(3 << 6)
#define SLVACCCTL2_TZC5_SL_10				(2 << 10)
#define SLVACCCTL2_TZC5_SL_11				(3 << 10)
#define SLVACCCTL2_TZC6_SL_10				(2 << 12)
#define SLVACCCTL2_TZC6_SL_11				(3 << 12)
#define SLVACCCTL3_CST_SL_00				(0 << 0)
#define SLVACCCTL3_CST_SL_01				(1 << 0)
#define SLVACCCTL3_CST_SL_10				(2 << 0)
#define SLVACCCTL3_CST_SL_11				(3 << 0)
#define SLVACCCTL3_CPG_SL_00				(0 << 2)
#define SLVACCCTL3_CPG_SL_01				(1 << 2)
#define SLVACCCTL3_CPG_SL_10				(2 << 2)
#define SLVACCCTL3_CPG_SL_11				(3 << 2)
#define SLVACCCTL3_SYSC_SL_00				(0 << 4)
#define SLVACCCTL3_SYSC_SL_01				(1 << 4)
#define SLVACCCTL3_SYSC_SL_10				(2 << 4)
#define SLVACCCTL3_SYSC_SL_11				(3 << 4)
#define SLVACCCTL3_SYC_SL_00				(0 << 6)
#define SLVACCCTL3_SYC_SL_01				(1 << 6)
#define SLVACCCTL3_SYC_SL_10				(2 << 6)
#define SLVACCCTL3_SYC_SL_11				(3 << 6)
#define SLVACCCTL3_GIC_SL_00				(0 << 8)
#define SLVACCCTL3_GIC_SL_01				(1 << 8)
#define SLVACCCTL3_GIC_SL_10				(2 << 8)
#define SLVACCCTL3_GIC_SL_11				(3 << 8)
#define SLVACCCTL3_IA55_IM33_SL_00			(0 << 10)
#define SLVACCCTL3_IA55_IM33_SL_01			(1 << 10)
#define SLVACCCTL3_IA55_IM33_SL_10			(2 << 10)
#define SLVACCCTL3_IA55_IM33_SL_11			(3 << 10)
#define SLVACCCTL3_GPIO_SL_00				(0 << 12)
#define SLVACCCTL3_GPIO_SL_01				(1 << 12)
#define SLVACCCTL3_GPIO_SL_10				(2 << 12)
#define SLVACCCTL3_GPIO_SL_11				(3 << 12)
#define SLVACCCTL3_MHU_SL_00				(0 << 14)
#define SLVACCCTL3_MHU_SL_01				(1 << 14)
#define SLVACCCTL3_MHU_SL_10				(2 << 14)
#define SLVACCCTL3_MHU_SL_11				(3 << 14)
#define SLVACCCTL4_DMAC0_SL_00				(0 << 0)
#define SLVACCCTL4_DMAC0_SL_01				(1 << 0)
#define SLVACCCTL4_DMAC0_SL_10				(2 << 0)
#define SLVACCCTL4_DMAC0_SL_11				(3 << 0)
#define SLVACCCTL4_DMAC1_SL_00				(0 << 2)
#define SLVACCCTL4_DMAC1_SL_01				(1 << 2)
#define SLVACCCTL4_DMAC1_SL_10				(2 << 2)
#define SLVACCCTL4_DMAC1_SL_11				(3 << 2)
#define SLVACCCTL4_OSTM0_SL_00				(0 << 4)
#define SLVACCCTL4_OSTM0_SL_01				(1 << 4)
#define SLVACCCTL4_OSTM0_SL_10				(2 << 4)
#define SLVACCCTL4_OSTM0_SL_11				(3 << 4)
#define SLVACCCTL4_OSTM1_SL_00				(0 << 6)
#define SLVACCCTL4_OSTM1_SL_01				(1 << 6)
#define SLVACCCTL4_OSTM1_SL_10				(2 << 6)
#define SLVACCCTL4_OSTM1_SL_11				(3 << 6)
#define SLVACCCTL4_OSTM2_SL_00				(0 << 8)
#define SLVACCCTL4_OSTM2_SL_01				(1 << 8)
#define SLVACCCTL4_OSTM2_SL_10				(2 << 8)
#define SLVACCCTL4_OSTM2_SL_11				(3 << 8)
#define SLVACCCTL4_OSTM3_SL_00				(0 << 10)
#define SLVACCCTL4_OSTM3_SL_01				(1 << 10)
#define SLVACCCTL4_OSTM3_SL_10				(2 << 10)
#define SLVACCCTL4_OSTM3_SL_11				(3 << 10)
#define SLVACCCTL4_OSTM4_SL_00				(0 << 12)
#define SLVACCCTL4_OSTM4_SL_01				(1 << 12)
#define SLVACCCTL4_OSTM4_SL_10				(2 << 12)
#define SLVACCCTL4_OSTM4_SL_11				(3 << 12)
#define SLVACCCTL4_OSTM5_SL_00				(0 << 14)
#define SLVACCCTL4_OSTM5_SL_01				(1 << 14)
#define SLVACCCTL4_OSTM5_SL_10				(2 << 14)
#define SLVACCCTL4_OSTM5_SL_11				(3 << 14)
#define SLVACCCTL4_OSTM6_SL_00				(0 << 16)
#define SLVACCCTL4_OSTM6_SL_01				(1 << 16)
#define SLVACCCTL4_OSTM6_SL_10				(2 << 16)
#define SLVACCCTL4_OSTM6_SL_11				(3 << 16)
#define SLVACCCTL4_OSTM7_SL_00				(0 << 18)
#define SLVACCCTL4_OSTM7_SL_01				(1 << 18)
#define SLVACCCTL4_OSTM7_SL_10				(2 << 18)
#define SLVACCCTL4_OSTM7_SL_11				(3 << 18)
#define SLVACCCTL4_WDT0_SL_00				(0 << 20)
#define SLVACCCTL4_WDT0_SL_01				(1 << 20)
#define SLVACCCTL4_WDT0_SL_10				(2 << 20)
#define SLVACCCTL4_WDT0_SL_11				(3 << 20)
#define SLVACCCTL4_WDT1_SL_00				(0 << 22)
#define SLVACCCTL4_WDT1_SL_01				(1 << 22)
#define SLVACCCTL4_WDT1_SL_10				(2 << 22)
#define SLVACCCTL4_WDT1_SL_11				(3 << 22)
#define SLVACCCTL4_WDT2_SL_00				(0 << 24)
#define SLVACCCTL4_WDT2_SL_01				(1 << 24)
#define SLVACCCTL4_WDT2_SL_10				(2 << 24)
#define SLVACCCTL4_WDT2_SL_11				(3 << 24)
#define SLVACCCTL4_RTC_SL_00				(0 << 28)
#define SLVACCCTL4_RTC_SL_01				(1 << 28)
#define SLVACCCTL4_RTC_SL_10				(2 << 28)
#define SLVACCCTL4_RTC_SL_11				(3 << 28)
#define SLVACCCTL5_MTU3A_SL_00				(0 << 0)
#define SLVACCCTL5_MTU3A_SL_01				(1 << 0)
#define SLVACCCTL5_MTU3A_SL_10				(2 << 0)
#define SLVACCCTL5_MTU3A_SL_11				(3 << 0)
#define SLVACCCTL5_POE3_SL_00				(0 << 2)
#define SLVACCCTL5_POE3_SL_01				(1 << 2)
#define SLVACCCTL5_POE3_SL_10				(2 << 2)
#define SLVACCCTL5_POE3_SL_11				(3 << 2)
#define SLVACCCTL5_GPT_SL_00				(0 << 4)
#define SLVACCCTL5_GPT_SL_01				(1 << 4)
#define SLVACCCTL5_GPT_SL_10				(2 << 4)
#define SLVACCCTL5_GPT_SL_11				(3 << 4)
#define SLVACCCTL5_POEG_SL_00				(0 << 6)
#define SLVACCCTL5_POEG_SL_01				(1 << 6)
#define SLVACCCTL5_POEG_SL_10				(2 << 6)
#define SLVACCCTL5_POEG_SL_11				(3 << 6)
#define SLVACCCTL5_DDR_SL_00				(0 << 8)
#define SLVACCCTL5_DDR_SL_01				(1 << 8)
#define SLVACCCTL5_DDR_SL_10				(2 << 8)
#define SLVACCCTL5_DDR_SL_11				(3 << 8)
#define SLVACCCTL5_XSPI_SL_00				(0 << 10)
#define SLVACCCTL5_XSPI_SL_01				(1 << 10)
#define SLVACCCTL5_XSPI_SL_10				(2 << 10)
#define SLVACCCTL5_XSPI_SL_11				(3 << 10)
#define SLVACCCTL5_OCTA_SL_00				(0 << 12)
#define SLVACCCTL5_OCTA_SL_01				(1 << 12)
#define SLVACCCTL5_OCTA_SL_10				(2 << 12)
#define SLVACCCTL5_OCTA_SL_11				(3 << 12)
#define SLVACCCTL6_USBT_SL_00				(0 << 0)
#define SLVACCCTL6_USBT_SL_01				(1 << 0)
#define SLVACCCTL6_USBT_SL_10				(2 << 0)
#define SLVACCCTL6_USBT_SL_11				(3 << 0)
#define SLVACCCTL6_USB20_SL_00				(0 << 2)
#define SLVACCCTL6_USB20_SL_01				(1 << 2)
#define SLVACCCTL6_USB20_SL_10				(2 << 2)
#define SLVACCCTL6_USB20_SL_11				(3 << 2)
#define SLVACCCTL6_USB21_SL_00				(0 << 4)
#define SLVACCCTL6_USB21_SL_01				(1 << 4)
#define SLVACCCTL6_USB21_SL_10				(2 << 4)
#define SLVACCCTL6_USB21_SL_11				(3 << 4)
#define SLVACCCTL6_SDHI0_SL_00				(0 << 6)
#define SLVACCCTL6_SDHI0_SL_01				(1 << 6)
#define SLVACCCTL6_SDHI0_SL_10				(2 << 6)
#define SLVACCCTL6_SDHI0_SL_11				(3 << 6)
#define SLVACCCTL6_SDHI1_SL_00				(0 << 8)
#define SLVACCCTL6_SDHI1_SL_01				(1 << 8)
#define SLVACCCTL6_SDHI1_SL_10				(2 << 8)
#define SLVACCCTL6_SDHI1_SL_11				(3 << 8)
#define SLVACCCTL6_SDHI2_SL_00				(0 << 10)
#define SLVACCCTL6_SDHI2_SL_01				(1 << 10)
#define SLVACCCTL6_SDHI2_SL_10				(2 << 10)
#define SLVACCCTL6_SDHI2_SL_11				(3 << 10)
#define SLVACCCTL6_ETH0_SL_00				(0 << 12)
#define SLVACCCTL6_ETH0_SL_01				(1 << 12)
#define SLVACCCTL6_ETH0_SL_10				(2 << 12)
#define SLVACCCTL6_ETH0_SL_11				(3 << 12)
#define SLVACCCTL6_ETH1_SL_00				(0 << 14)
#define SLVACCCTL6_ETH1_SL_01				(1 << 14)
#define SLVACCCTL6_ETH1_SL_10				(2 << 14)
#define SLVACCCTL6_ETH1_SL_11				(3 << 14)
#define SLVACCCTL6_PCIE_SL_00				(0 << 16)
#define SLVACCCTL6_PCIE_SL_01				(1 << 16)
#define SLVACCCTL6_PCIE_SL_10				(2 << 16)
#define SLVACCCTL6_PCIE_SL_11				(3 << 16)
#define SLVACCCTL7_I2C0_SL_00				(0 << 0)
#define SLVACCCTL7_I2C0_SL_01				(1 << 0)
#define SLVACCCTL7_I2C0_SL_10				(2 << 0)
#define SLVACCCTL7_I2C0_SL_11				(3 << 0)
#define SLVACCCTL7_I2C1_SL_00				(0 << 2)
#define SLVACCCTL7_I2C1_SL_01				(1 << 2)
#define SLVACCCTL7_I2C1_SL_10				(2 << 2)
#define SLVACCCTL7_I2C1_SL_11				(3 << 2)
#define SLVACCCTL7_I2C2_SL_00				(0 << 4)
#define SLVACCCTL7_I2C2_SL_01				(1 << 4)
#define SLVACCCTL7_I2C2_SL_10				(2 << 4)
#define SLVACCCTL7_I2C2_SL_11				(3 << 4)
#define SLVACCCTL7_I2C3_SL_00				(0 << 6)
#define SLVACCCTL7_I2C3_SL_01				(1 << 6)
#define SLVACCCTL7_I2C3_SL_10				(2 << 6)
#define SLVACCCTL7_I2C3_SL_11				(3 << 6)
#define SLVACCCTL7_I3C_SL_00				(0 << 8)
#define SLVACCCTL7_I3C_SL_01				(1 << 8)
#define SLVACCCTL7_I3C_SL_10				(2 << 8)
#define SLVACCCTL7_I3C_SL_11				(3 << 8)
#define SLVACCCTL7_CANFD_SL_00				(0 << 10)
#define SLVACCCTL7_CANFD_SL_01				(1 << 10)
#define SLVACCCTL7_CANFD_SL_10				(2 << 10)
#define SLVACCCTL7_CANFD_SL_11				(3 << 10)
#define SLVACCCTL7_RSPI0_SL_00				(0 << 12)
#define SLVACCCTL7_RSPI0_SL_01				(1 << 12)
#define SLVACCCTL7_RSPI0_SL_10				(2 << 12)
#define SLVACCCTL7_RSPI0_SL_11				(3 << 12)
#define SLVACCCTL7_RSPI1_SL_00				(0 << 14)
#define SLVACCCTL7_RSPI1_SL_01				(1 << 14)
#define SLVACCCTL7_RSPI1_SL_10				(2 << 14)
#define SLVACCCTL7_RSPI1_SL_11				(3 << 14)
#define SLVACCCTL7_RSPI2_SL_00				(0 << 16)
#define SLVACCCTL7_RSPI2_SL_01				(1 << 16)
#define SLVACCCTL7_RSPI2_SL_10				(2 << 16)
#define SLVACCCTL7_RSPI2_SL_11				(3 << 16)
#define SLVACCCTL7_RSPI3_SL_00				(0 << 18)
#define SLVACCCTL7_RSPI3_SL_01				(1 << 18)
#define SLVACCCTL7_RSPI3_SL_10				(2 << 18)
#define SLVACCCTL7_RSPI3_SL_11				(3 << 18)
#define SLVACCCTL7_RSPI4_SL_00				(0 << 20)
#define SLVACCCTL7_RSPI4_SL_01				(1 << 20)
#define SLVACCCTL7_RSPI4_SL_10				(2 << 20)
#define SLVACCCTL7_RSPI4_SL_11				(3 << 20)
#define SLVACCCTL8_SCIF0_SL_00				(0 << 0)
#define SLVACCCTL8_SCIF0_SL_01				(1 << 0)
#define SLVACCCTL8_SCIF0_SL_10				(2 << 0)
#define SLVACCCTL8_SCIF0_SL_11				(3 << 0)
#define SLVACCCTL8_SCIF1_SL_00				(0 << 2)
#define SLVACCCTL8_SCIF1_SL_01				(1 << 2)
#define SLVACCCTL8_SCIF1_SL_10				(2 << 2)
#define SLVACCCTL8_SCIF1_SL_11				(3 << 2)
#define SLVACCCTL8_SCIF2_SL_00				(0 << 4)
#define SLVACCCTL8_SCIF2_SL_01				(1 << 4)
#define SLVACCCTL8_SCIF2_SL_10				(2 << 4)
#define SLVACCCTL8_SCIF2_SL_11				(3 << 4)
#define SLVACCCTL8_SCIF3_SL_00				(0 << 6)
#define SLVACCCTL8_SCIF3_SL_01				(1 << 6)
#define SLVACCCTL8_SCIF3_SL_10				(2 << 6)
#define SLVACCCTL8_SCIF3_SL_11				(3 << 6)
#define SLVACCCTL8_SCIF4_SL_00				(0 << 8)
#define SLVACCCTL8_SCIF4_SL_01				(1 << 8)
#define SLVACCCTL8_SCIF4_SL_10				(2 << 8)
#define SLVACCCTL8_SCIF4_SL_11				(3 << 8)
#define SLVACCCTL8_SCIF5_SL_00				(0 << 10)
#define SLVACCCTL8_SCIF5_SL_01				(1 << 10)
#define SLVACCCTL8_SCIF5_SL_10				(2 << 10)
#define SLVACCCTL8_SCIF5_SL_11				(3 << 10)
#define SLVACCCTL8_SCI0_SL_00				(0 << 12)
#define SLVACCCTL8_SCI0_SL_01				(1 << 12)
#define SLVACCCTL8_SCI0_SL_10				(2 << 12)
#define SLVACCCTL8_SCI0_SL_11				(3 << 12)
#define SLVACCCTL8_SCI1_SL_00				(0 << 14)
#define SLVACCCTL8_SCI1_SL_01				(1 << 14)
#define SLVACCCTL8_SCI1_SL_10				(2 << 14)
#define SLVACCCTL8_SCI1_SL_11				(3 << 14)
#define SLVACCCTL8_IRDA_SL_00				(0 << 16)
#define SLVACCCTL8_IRDA_SL_01				(1 << 16)
#define SLVACCCTL8_IRDA_SL_10				(2 << 16)
#define SLVACCCTL8_IRDA_SL_11				(3 << 16)
#define SLVACCCTL9_SSIF0_SL_00				(0 << 0)
#define SLVACCCTL9_SSIF0_SL_01				(1 << 0)
#define SLVACCCTL9_SSIF0_SL_10				(2 << 0)
#define SLVACCCTL9_SSIF0_SL_11				(3 << 0)
#define SLVACCCTL9_SSIF1_SL_00				(0 << 2)
#define SLVACCCTL9_SSIF1_SL_01				(1 << 2)
#define SLVACCCTL9_SSIF1_SL_10				(2 << 2)
#define SLVACCCTL9_SSIF1_SL_11				(3 << 2)
#define SLVACCCTL9_SSIF2_SL_00				(0 << 4)
#define SLVACCCTL9_SSIF2_SL_01				(1 << 4)
#define SLVACCCTL9_SSIF2_SL_10				(2 << 4)
#define SLVACCCTL9_SSIF2_SL_11				(3 << 4)
#define SLVACCCTL9_SSIF3_SL_00				(0 << 6)
#define SLVACCCTL9_SSIF3_SL_01				(1 << 6)
#define SLVACCCTL9_SSIF3_SL_10				(2 << 6)
#define SLVACCCTL9_SSIF3_SL_11				(3 << 6)
#define SLVACCCTL9_SRC_SL_00				(0 << 8)
#define SLVACCCTL9_SRC_SL_01				(1 << 8)
#define SLVACCCTL9_SRC_SL_10				(2 << 8)
#define SLVACCCTL9_SRC_SL_11				(3 << 8)
#define SLVACCCTL9_SPDIF_SL_00				(0 << 10)
#define SLVACCCTL9_SPDIF_SL_01				(1 << 10)
#define SLVACCCTL9_SPDIF_SL_10				(2 << 10)
#define SLVACCCTL9_SPDIF_SL_11				(3 << 10)
#define SLVACCCTL9_PDM_SL_00				(0 << 12)
#define SLVACCCTL9_PDM_SL_01				(1 << 12)
#define SLVACCCTL9_PDM_SL_10				(2 << 12)
#define SLVACCCTL9_PDM_SL_11				(3 << 12)

#define SLVACCCTL10_ADC_SL_00				(0 << 0)
#define SLVACCCTL10_ADC_SL_01				(1 << 0)
#define SLVACCCTL10_ADC_SL_10				(2 << 0)
#define SLVACCCTL10_ADC_SL_11				(3 << 0)
#define SLVACCCTL10_TSU_SL_00				(0 << 2)
#define SLVACCCTL10_TSU_SL_01				(1 << 2)
#define SLVACCCTL10_TSU_SL_10				(2 << 2)
#define SLVACCCTL10_TSU_SL_11				(3 << 2)
#define SLVACCCTL11_OTP_SL_00				(0 << 2)
#define SLVACCCTL11_OTP_SL_01				(1 << 2)
#define SLVACCCTL11_OTP_SL_10				(2 << 2)
#define SLVACCCTL11_OTP_SL_11				(3 << 2)
#define SLVACCCTL11_VBATT_SL_00				(0 << 10)
#define SLVACCCTL11_VBATT_SL_01				(1 << 10)
#define SLVACCCTL11_VBATT_SL_10				(2 << 10)
#define SLVACCCTL11_VBATT_SL_11				(3 << 10)
#define SLVACCCTL12_CA55_SL_00				(0 << 0)
#define SLVACCCTL12_CA55_SL_01				(1 << 0)
#define SLVACCCTL12_CA55_SL_10				(2 << 0)
#define SLVACCCTL12_CA55_SL_11				(3 << 0)
#define SLVACCCTL12_CM33_SL_00				(0 << 2)
#define SLVACCCTL12_CM33_SL_01				(1 << 2)
#define SLVACCCTL12_CM33_SL_10				(2 << 2)
#define SLVACCCTL12_CM33_SL_11				(3 << 2)
#define SLVACCCTL12_CM33FPU_SL_00			(0 << 4)
#define SLVACCCTL12_CM33FPU_SL_01			(1 << 4)
#define SLVACCCTL12_CM33FPU_SL_10			(2 << 4)
#define SLVACCCTL12_CM33FPU_SL_11			(3 << 4)
#define SLVACCCTL14_LSI_SL_00				(0 << 0)
#define SLVACCCTL14_LSI_SL_01				(1 << 0)
#define SLVACCCTL14_LSI_SL_10				(2 << 0)
#define SLVACCCTL14_LSI_SL_11				(3 << 0)
#define SLVACCCTL16_AOF_SL_00				(0 << 0)
#define SLVACCCTL16_AOF_SL_01				(1 << 0)
#define SLVACCCTL16_AOF_SL_10				(2 << 0)
#define SLVACCCTL16_AOF_SL_11				(3 << 0)
#define SLVACCCTL17_LP_SL_00				(0 << 0)
#define SLVACCCTL17_LP_SL_01				(1 << 0)
#define SLVACCCTL17_LP_SL_10				(2 << 0)
#define SLVACCCTL17_LP_SL_11				(3 << 0)
#define SLVACCCTL18_GPREG_SL_00				(0 << 0)
#define SLVACCCTL18_GPREG_SL_01				(1 << 0)
#define SLVACCCTL18_GPREG_SL_10				(2 << 0)
#define SLVACCCTL18_GPREG_SL_11				(3 << 0)
#define SLVACCCTL20_IPCONT_SL_00			(0 << 0)
#define SLVACCCTL20_IPCONT_SL_01			(1 << 0)
#define SLVACCCTL20_IPCONT_SL_10			(2 << 0)
#define SLVACCCTL20_IPCONT_SL_11			(3 << 0)


#define RAM0_ECC_VECCEN						(1 << 0)
#define RAM0_EN_VCEN						(1 << 0)
#define RAM0_EN_VLWEN						(1 << 1)
#define RAM1_ECC_VECCEN						(1 << 0)
#define RAM1_EN_VCEN						(1 << 0)
#define RAM1_EN_VLWEN						(1 << 1)
#define RAM2_ECC_VECCEN						(1 << 0)
#define RAM2_EN_VCEN						(1 << 0)
#define RAM2_EN_VLWEN						(1 << 1)
#define RAM3_ECC_VECCEN						(1 << 0)
#define RAM3_EN_VCEN						(1 << 0)
#define RAM3_EN_VLWEN						(1 << 1)
#define WDT0_CTRL_WDTSTOP					(1 << 0)
#define WDT0_CTRL_WDTSTOPMASK				(1 << 16)
#define WDT1_CTRL_WDTSTOP					(1 << 0)
#define WDT1_CTRL_WDTSTOPMASK				(1 << 16)
#define WDT2_CTRL_WDTSTOP					(1 << 0)
#define WDT2_CTRL_WDTSTOPMASK				(1 << 16)

#define GETH0_CFG_FEC_GIGA_ENABLE			(1 << 24)
#define GETH1_CFG_FEC_GIGA_ENABLE			(1 << 24)
#define I2C0_CFG_af_bypass					(1 << 0)
#define I2C1_CFG_af_bypass					(1 << 0)
#define I2C2_CFG_af_bypass					(1 << 0)
#define I2C3_CFG_af_bypass					(1 << 0)
#define I3C_CFG_af_bypass					(1 << 0)
#define CM33_LOCK_LOCKSVTAIRCR				(1 << 0)
#define CM33_LOCK_LOCKNSVTOR				(1 << 1)
#define CM33FPU_LOCK_LOCKSVTAIRCR			(1 << 0)
#define CM33FPU_LOCK_LOCKNSVTOR				(1 << 1)

#define LSI_MODE_STAT_BOOTCPUSEL			(1 << 0)
#define LSI_MODE_STAT_DEBUGEN				(1 << 9)
#define LSI_MODE_STAT_MD_CLKS				(1 << 12)
#define LSI_MODE_STAT_MD_BYPASS				(1 << 13)

#define SYS_LSI_MODE_ESD					(0x0)
#define SYS_LSI_MODE_EMMC					(0x1)
#define SYS_LSI_MODE_SFLASH					(0x2)
#define SYS_LSI_MODE_SCIF					(0x3)
#define SYS_LSI_MODE_VOL_1_8				(0x0)
#define SYS_LSI_MODE_VOL_3_3				(0x4)
#define SYS_LSI_MODE_MASK					(0x7)
#define SYS_LSI_MODE_SHIFT					(0x4)

#define PD_ISO_CTRL_PD_ISOVCC_ISOEN			(1 << 0)
#define ISO_IOBUF_SE18_CTRL_ISO_IOBUF_SE18	(1 << 0)
#define USB_PWRRDY_PWRRDY_N					(1 << 0)
#define PCIE_RST_RSM_B_PCIE_RST_RSM_B		(1 << 0)
#define IPCONT_SEL_SPI_OCTA_SEL_SPI_OCTA	(1 << 0)
#define IPCONT_IDAUZERONS_IDAUZERONS		(1 << 0)
#define IPCONT_IDAUZERONS_FPU_IDAUZERONS_FPU	(1 << 0)

#endif	/* __SYS_REGS_H__ */
