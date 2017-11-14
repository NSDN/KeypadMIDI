#include "Keyboard.h"

void setup() {
    delay(3000);
    Serial.begin(9600);
    Keyboard.begin();
}

void loop() {
    if (Serial.available() > 0) {
        char key = Serial.read();

        if ((key & 0x80) == 0)
            Keyboard.press(key & 0x7F);
        else
            Keyboard.release(key & 0x7F);
    }
}
