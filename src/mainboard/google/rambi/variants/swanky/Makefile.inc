## SPDX-License-Identifier: GPL-2.0-only

SPD_BIN = $(obj)/spd.bin

# Order matters for SPD sources. The following indices
# define the SPD data to use.
# 0b000 - 2GiB total - 1 x 2GiB Samsung K4B4G1646Q-HYK0 1600MHz
# 0b001 - 2GiB total - 1 x 2GiB Hynix  H5TC4G63AFR-PBA 1600MHz
# 0b010 - 4GiB total - 2 x 2GiB Samsung K4B4G1646Q-HYK0 1600MHz
# 0b011 - 4GiB total - 2 x 2GiB Hynix  H5TC4G63AFR-PBA 1600MHz
SPD_SOURCES  = samsung_2GiB_dimm_K4B4G1646Q-HYK0
SPD_SOURCES += hynix_2GiB_dimm_H5TC4G63AFR-PBA
SPD_SOURCES += samsung_2GiB_dimm_K4B4G1646Q-HYK0
SPD_SOURCES += hynix_2GiB_dimm_H5TC4G63AFR-PBA

SPD_DEPS := $(foreach f, $(SPD_SOURCES), src/mainboard/$(MAINBOARDDIR)/spd/$(f).spd.hex)

# Include spd ROM data
$(SPD_BIN): $(SPD_DEPS)
	for f in $+; \
	  do for c in $$(cat $$f | grep -v ^#); \
	    do printf $$(printf '\%o' 0x$$c); \
	  done; \
	done > $@

cbfs-files-y += spd.bin
spd.bin-file := $(SPD_BIN)
spd.bin-type := spd
