#include <Arduino.h>

// Pin Definitions
#define IR_TX_PIN PIN_PA1
#define IR_RX_PIN PIN_PA2

// configs
#define IR_USE_AVR_TIMER_TCB1 

// Ext Libraries
#include <IRremote.hpp>

bool sentPwrCmd = false;

void setup() {
	Serial.begin(115200); // serial is on usb-c
	IrSender.begin(IR_TX_PIN);
	IrReceiver.begin(IR_RX_PIN, ENABLE_LED_FEEDBACK); 
}

void loop() {

	if (!sentPwrCmd) {
		uint16_t address = 0x00; // standard device address
		uint8_t command = 0x45;  // standard power command
		IrSender.sendNEC(address, command, 0);
		sentPwrCmd = true;
		Serial.println("=== power command was sent!! ===");
	}

	if (IrReceiver.decode()) {
		Serial.println("-------------------------");
		Serial.println("\tbegin decode():");
        Serial.print("Protocol: ");
        Serial.println(getProtocolString(IrReceiver.decodedIRData.protocol));
        Serial.print("Command (Hex): 0x");
        Serial.println(IrReceiver.decodedIRData.command, HEX);
        Serial.print("Address (Hex): 0x");
        Serial.println(IrReceiver.decodedIRData.address, HEX);
        Serial.println("-------------------------\n");
        IrReceiver.resume(); 
    }

}
