/**
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"

int i;

int Relay1 = 8;
int Relay2 = 9;
int Relay3 = 10;
int Relay4 = 11;
int Relay5 = 12;
int Relay6 = 13;

int Relays[] = {Relay1, Relay2, Relay3, Relay4, Relay5, Relay6};
int numRelays = (sizeof(Relays)/sizeof(int));

int DigitalInput1 = 2;
int DigitalInput2 = 3;
int DigitalInput3 = 4;
int DigitalInput4 = 5;
int DigitalInput5 = 6;
int DigitalInput6 = 7;

int DigitalInputs[] = {DigitalInput1, DigitalInput2, DigitalInput3, DigitalInput4, DigitalInput5, DigitalInput6};
int numDigitalInputs = (sizeof(DigitalInputs)/sizeof(int));

int AnalogInput1 = A0;
int AnalogInput2 = A1;
int AnalogInput3 = A2;
int AnalogInput4 = A3;
int AnalogInput5 = A4;
int AnalogInput6 = A5;

int AnalogInputs[] = {AnalogInput1, AnalogInput2, AnalogInput3, AnalogInput4, AnalogInput5, AnalogInput6};
int numAnalogInputs = (sizeof(AnalogInputs)/sizeof(int));

void enableRelays() {
    Serial.print("# of Relays: ");
    Serial.println(numRelays);
    Serial.println("Initializing:");
    for (i = 0; i < numRelays; i++) {
        Serial.print("  > Relay ");
        Serial.println(i+1);
        pinMode(Relays[i], OUTPUT);
    }
    Serial.println();
}

void enableDigitalInputs() {
    Serial.print("# of Digital Inputs: ");
    Serial.println(numDigitalInputs);
    Serial.println("Initializing:");
    for (i = 0; i < numDigitalInputs; i++) {
        Serial.print("  > Digital Input ");
        Serial.println(i+1);
        pinMode(DigitalInputs[i], INPUT);
    }
    Serial.println();
}

void enableAnalogInputs() {
    Serial.print("# of Analog Inputs: ");
    Serial.println(numAnalogInputs);
    Serial.println("Initializing:");
    for (i = 0; i < numAnalogInputs; i++) {
        Serial.print("  > Analog Input ");
        Serial.println(i+1);
        pinMode(AnalogInputs[i], INPUT);
    }
    Serial.println();
}

void setup()
{
    Serial.begin(9600);

    enableRelays();
    enableDigitalInputs();
    enableAnalogInputs();
}

void loop()
{
    // for (i = 0; i < numRelays; i++) {
    //     digitalWrite(Relays[i], HIGH);
    //     delay(250);
    //     digitalWrite(Relays[i], LOW);
    // }
    //
    // for (i = numRelays-1; i > 0+1; i--) {
    //     digitalWrite(Relays[i-1], HIGH);
    //     delay(250);
    //     digitalWrite(Relays[i-1], LOW);
    // }

    // Read from digital inputs and send to serial the state change
    int digitalInputReadState;
    for (i = 0; i < numDigitalInputs; i++) {
        // if (digitalRead(DigitalInputs[i]) ==
        digitalInputReadState = digitalRead(DigitalInputs[i]);

        switch (i) {
            case 0:
                if (digitalInputReadState == 0) {
                    digitalWrite(Relays[5], HIGH);
                } else {
                    digitalWrite(Relays[5], LOW);
                }

                Serial.print(digitalInputReadState);
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            default:
                Serial.print(digitalInputReadState);
                break;
        }
    }

    Serial.print(" ");
    // Serial.println();

    int analogInputReadState;
    for (i = 0; i < numAnalogInputs; i++) {
        // if (digitalRead(DigitalInputs[i]) ==
        analogInputReadState = analogRead(AnalogInputs[i]);

        switch (i) {
            case 0:
                //pot reading
                analogInputReadState = map(analogInputReadState, 0, 987, 0, 100);
                Serial.print(analogInputReadState);
                Serial.print("%");

                if (analogInputReadState <= 50) {
                    digitalWrite(Relays[0], HIGH);
                } else {
                    digitalWrite(Relays[0], LOW);
                }
                break;
            case 1:
                //temp reading
                Serial.print("Temp: ");
                Serial.print((float(analogInputReadState) / 1023) * 500);
                Serial.print("C");
                break;
            case 2:
            case 3:
            case 4:
            case 5:
            default:
                Serial.print(analogInputReadState);
                break;
        }

        Serial.print(" ");
    }
    Serial.println();

    delay(100);
}
