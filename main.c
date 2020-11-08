//Atmega128 implementation

#include <avr/io.h>
#include <stdint.h>

// Assume LEDs are connected to pins A4 - A7

// initialize the LEDs
void initLeds() {
	DDRD |= 0xF0;  // 1111 0000 = 0xF0
}

// turn one selected LED on
void turnLedOn(uint8_t selection) {
	PORTD |= 1 << selection;
}

// turn one selected LED off
void turnLedOff(uint8_t selection) {
	PORTD &= ~(1 << selection);
}

// toggle selected LED
void toggleLed(uint8_t selection) {
	PORTD ^= (1 << selection);
}

// set a value to the LED
void setLed(uint8_t value) { 
	PORTD = (PORTD & 0x0F) | (value & 0xF0);
}
