CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m3 -mthumb -Wall -g
LDFLAGS=-T linker_script.ld

all: firmware.elf

firmware.elf: main.c
	$(CC) $(CFLAGS) -o firmware.elf main.c $(LDFLAGS)

clean:
	rm -f firmware.elf
