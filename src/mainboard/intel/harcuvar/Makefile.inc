## SPDX-License-Identifier: GPL-2.0-only

subdirs-$(CONFIG_ENABLE_FSP_MEMORY_DOWN) += spd

romstage-y += boardid.c
romstage-y += hsio.c

ramstage-y += ramstage.c
ramstage-y += boardid.c
ramstage-y += hsio.c
ramstage-$(CONFIG_HAVE_ACPI_TABLES) += fadt.c

CPPFLAGS_common += -Isrc/mainboard/$(MAINBOARDDIR)/
