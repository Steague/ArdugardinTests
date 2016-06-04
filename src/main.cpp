/**
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"

int Relay1 = 8;
int Relay2 = 9;
int Relay3 = 10;
int Relay4 = 11;
int Relay5 = 12;
int Relay6 = 13;
int i;

int Relays[] = {Relay1, Relay2, Relay3, Relay4, Relay5, Relay6};
int numRelays = (sizeof(Relays)/sizeof(int));

void setup()
{
    Serial.begin(9600);
    Serial.print("# of Relays: ");
    Serial.println(numRelays);
    Serial.println("Initializing:");
    for (i = 0; i < numRelays; i++) {
        Serial.print("  > Relay ");
        Serial.println(i+1);
        pinMode(Relays[i], OUTPUT);
    }
}

void loop()
{
    for (i = 0; i < numRelays; i++) {
        digitalWrite(Relays[i], HIGH);
        delay(250);
        digitalWrite(Relays[i], LOW);
    }

    for (i = numRelays-1; i > 0+1; i--) {
        digitalWrite(Relays[i-1], HIGH);
        delay(250);
        digitalWrite(Relays[i-1], LOW);
    }
}
