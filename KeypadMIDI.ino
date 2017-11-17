#include "Keyboard.h"

void setup() {
    delay(3000);
    Serial.begin(9600);
    Keyboard.begin();
}

void loop() {
    if (Serial.available() > 0) {
        byte tag = Serial.read();

        if (tag == 0xFF)
            Keyboard.press(Serial.read());
        else if (tag == 0x00)
            Keyboard.release(Serial.read());
    }
}
