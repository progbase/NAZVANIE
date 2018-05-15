#pragma once

#include <Servo.h>

static const int ANGLE[] = {71, 106, 86, 123, 93, 106, 120, 95};

class MyServo : public Servo {
    bool isAttached = false;
    unsigned long lastPlay = 0;
    int pin;

  public:
    MyServo(int _pin) : Servo() { pin = _pin; }

    void play() {
        attach(pin);
        write(ANGLE[pin - 3]);
        delay(100);
        write(ANGLE[pin - 3] - 25);
        lastPlay = millis();
    }

    int getPin() { return pin; }
    unsigned long getLastPlay() { return lastPlay; }
};
