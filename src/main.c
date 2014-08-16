#include <arch/antares.h>
#include <avr/boot.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ANTARES_INITCALL_LOW(io_init) {
	// Set up all the pins.

}

ANTARES_INITCALL_HIGH(bc127_init) {
	// do_bc127_init();
}

ANTARES_APP(cochlea_mainloop) {
	while (1) { // Main loop
	}
}