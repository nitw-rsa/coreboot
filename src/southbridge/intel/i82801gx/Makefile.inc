## SPDX-License-Identifier: GPL-2.0-only

ifeq ($(CONFIG_SOUTHBRIDGE_INTEL_I82801GX),y)

bootblock-y += early_init.c
bootblock-y += bootblock.c

ramstage-y += i82801gx.c
ramstage-y += ac97.c
ramstage-y += azalia.c
ramstage-y += ide.c
ramstage-y += lpc.c
ramstage-y += nic.c
ramstage-y += pci.c
ramstage-y += pcie.c
ramstage-y += sata.c
ramstage-y += smbus.c
ramstage-y += usb.c
ramstage-y += usb_ehci.c

ramstage-srcs += src/mainboard/$(MAINBOARDDIR)/hda_verb.c

smm-y += smihandler.c

romstage-y += early_init.c
romstage-y += early_smbus.c
romstage-y += early_cir.c

endif
