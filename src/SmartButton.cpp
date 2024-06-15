#include <Arduino.h>
#include <NanitLib.h>

class SmartButton
{
private:
    uint16_t v_min, v_max;
    uint8_t v_pin;
    bool stateDown = false;

    bool inRange(int value) {
        return (value >= v_min && value < v_max);
    }

    bool btnDown() {
        int value = analogRead(v_pin);
        if (inRange(value)) {
            stateDown = true;
        }
        return stateDown;
    }

public:
    SmartButton(uint16_t min, uint16_t max, uint8_t pin): v_min(min), v_max(max), v_pin(pin){}

    bool isPressed() {
        if (btnDown() && !inRange(analogRead(v_pin))) {
            stateDown = false;
            return true;
        }
        return false;
    }

};
