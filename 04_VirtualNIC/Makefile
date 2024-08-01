ifneq ($(KERNELRELEASE),)
	obj-m := 04_VirtualNIC.o
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

.PHONY:clean

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

endif
