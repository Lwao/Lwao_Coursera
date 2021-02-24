#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

# General variables
TARGET = c1m2
GFLAGS = -Wall \
		 -Werror \
		 -g \
		 -O0\
		 -std=c99 \



ifeq ($(PLATFORM), MSP432)
	# Architectures Specific Flags
	LINKER_FILE = -T msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	ADDITIONAL = -mthumb \
				 -mfloat-abi=hard \
				 -mfpu=fpv4-sp-d16

	# Compiler Flags and Defines
	CC = arm-none-eabi-gcc
	LD =  arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET).map -T -L ../ $(LINKER_FILE) 
	CFLAGS = $(GFLAGS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) $(ADDITIONAL)
	CPPFLAGs = -DMSP432 $(INCLUDES)
	SIZE = arm-none-eabi-size

	SOURCE = main.c \
			 memory.c \
			 interrupts_msp432p401r_gcc.c \
		 	 startup_msp432p401r_gcc.c \
		 	 system_msp432p401r.c	
	
else
	 # Compiler Flags and Defines
	CC = gcc
	LDFLAGS = -Wl,-Map=$(TARGET).map
	CFLAGS = $(GFLAGS) 
	CPPFLAGs = -DHOST $(INCLUDES)
	SIZE = size
endif

IPPS = $(SRCS:.c=.i)   # PREP
ASMS = $(SRCS:.c=.asm) # ASMS
OBJS = $(SRCS:.c=.o)   # OBJS
LDS  = $(SRCS:.c=.d)   # DEPS

%.i: %.c
	$(CC) -E $< $(CPPFLAGs) -o $@

%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGs) -o $@

%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGs) -o $@

%.d: %.c
	$(CC) -E -M $< $(CPPFLAGs) -o $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONE: Build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: Clean
clean: 
	rm -f $(IPPS) $(ASMS) $(OBJS) $(LDS) $(TARGET).out $(TARGET).map 