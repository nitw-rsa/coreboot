/* SPDX-License-Identifier: GPL-2.0-or-later */

/*
 * NOTE: The layout of the global_nvs_t structure below must match the layout
 * in soc/intel/apollolake/acpi/globalnvs.asl !!!
 *
 */

#ifndef _SOC_APOLLOLAKE_NVS_H_
#define _SOC_APOLLOLAKE_NVS_H_

#include <commonlib/helpers.h>
#include <vendorcode/google/chromeos/gnvs.h>

typedef struct global_nvs_t {
	/* Miscellaneous */
	uint8_t		pcnt; /* 0x00 - Processor Count */
	uint8_t		ppcm; /* 0x01 - Max PPC State */
	uint8_t		lids; /* 0x02 - LID State */
	uint8_t		pwrs; /* 0x03 - AC Power State */
	uint8_t		dpte; /* 0x04 - Enable DPTF */
	uint32_t	cbmc; /* 0x05 - 0x08 - coreboot Memory Console */
	uint64_t	pm1i; /* 0x09 - 0x10 - System Wake Source - PM1 Index */
	uint64_t	gpei; /* 0x11 - 0x18 - GPE Wake Source */
	uint64_t	nhla; /* 0x19 - 0x20 - NHLT Address */
	uint32_t	nhll; /* 0x21 - 0x24 - NHLT Length */
	uint32_t	prt0; /* 0x25 - 0x28 - PERST_0 Address */
	uint8_t		scdp; /* 0x29 - SD_CD GPIO portid */
	uint8_t		scdo; /* 0x2A - GPIO pad offset relative to the community */
	uint8_t		uior; /* 0x2B - UART debug controller init on S3
					 resume */
	uint8_t		ecps; /* 0x2C - SGX Enabled status */
	uint64_t	emna; /* 0x2D - 0x34 EPC base address */
	uint64_t	elng; /* 0x35 - 0x3C EPC Length */
	uint64_t	a4gb; /* 0x3D - 0x44 Base of above 4GB MMIO Resource */
	uint64_t	a4gs; /* 0x45 - 0x4C Length of above 4GB MMIO Resource */
	uint8_t		unused[179];

	/* ChromeOS specific (0x100 - 0xfff) */
	chromeos_acpi_t chromeos;
} __packed global_nvs_t;
check_member(global_nvs_t, chromeos, GNVS_CHROMEOS_ACPI_OFFSET);

#endif	/* _SOC_APOLLOLAKE_NVS_H_ */
