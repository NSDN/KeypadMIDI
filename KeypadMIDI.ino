#include "Keyboard.h"

void setup() {
    delay(3000);
    Serial.begin(9600);
    Keyboard.begin();
}

void loop() {
    if (Serial.available() > 0) {
        byte tag = Serial.read();
        byte key = 0;

        if (tag == 0xFF) {
            key = Serial.read();
            if (key >= 0x41 && key <= 0x5A)
                key += 0x20;
            Keyboard.press(key);
        } else if (tag == 0x00) {
            key = Serial.read();
            if (key >= 0x41 && key <= 0x5A)
                key += 0x20;
            Keyboard.release(key);
        }
    }
}
