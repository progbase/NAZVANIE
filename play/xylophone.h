#pragma once

#include "StandardCplusplus.h"
#include <iterator>
#include <vector>
#include "myservo.h"
#include "songs.h"

class Xylophone {
    std::vector<MyServo> servos;
    bool exit = false;
    unsigned long lastButtonPressed = 0;
  public:
    Xylophone() {
        servos.push_back(MyServo(C_PIN));
        servos.push_back(MyServo(D_PIN));
        servos.push_back(MyServo(E_PIN));
        servos.push_back(MyServo(F_PIN));
        servos.push_back(MyServo(G_PIN));
        servos.push_back(MyServo(A_PIN));
        servos.push_back(MyServo(B_PIN));
        servos.push_back(MyServo(_C_PIN));
    }

    bool play(JingleBells & song) {
        lastSongChangeTime = millis();
        Serial.begin(9600);
        pinMode(LISTEN_BTN_PIN, INPUT);
        unsigned long startPlaying = millis();
        unsigned long now = 0;
        lastButtonPressed = millis();
        while (true) {
            if (endPlaying()) return false;
            now = millis();
            if (now - startPlaying > song.getCurrentTime() * 1000) {
                int note = song.getCurrentNote();
                int index = noteToIndex(note);
                servos[index].play();
                if (!song.nextCommand()) break;
            }
            detachOdd();
        }
        detachOdd();
        return true;
    }

    bool play(McDonald & song) {
        Serial.begin(9600);
        pinMode(LISTEN_BTN_PIN, INPUT);
        unsigned long startPlaying = millis();
        unsigned long now = 0;
        lastButtonPressed = millis();
        while (true) {
            if (endPlaying()) return false;
            now = millis();
            if (now - startPlaying > song.getCurrentTime() * 1000) {
                int note = song.getCurrentNote();
                int index = noteToIndex(note);
                servos[index].play();
                if (!song.nextCommand()) break;
            }
            detachOdd();
        }
        detachOdd();
        return true;
    }

    bool play(Cucaracha & song) {
        Serial.begin(9600);
        pinMode(LISTEN_BTN_PIN, INPUT);
        unsigned long startPlaying = millis();
        unsigned long now = 0;
        lastButtonPressed = millis();
        while (true) {
            if (endPlaying()) return false;
            now = millis();
            if (now - startPlaying > song.getCurrentTime() * 1000) {
                int note = song.getCurrentNote();
                int index = noteToIndex(note);
                servos[index].play();
                if (!song.nextCommand()) break;
            }
            detachOdd();
        }
        detachOdd();
        return true;
    }

  private:

    bool endPlaying() {
        int buttonValue = analogRead(LISTEN_BTN_PIN);
        Serial.println(buttonValue);
        if (buttonValue < 1020) {
          exit = false;
          return false;
        }
        unsigned long now = millis();
        if (now - lastSongChangeTime < 1000) return false;
        if (exit && now - lastButtonPressed > 50) return true;
        exit = true;
        lastButtonPressed = now;
        return false;
    }
  
    int noteToIndex(int note) {
        switch (note) {
        case C_PIN: return 0;
        case D_PIN: return 1;
        case E_PIN: return 2;
        case F_PIN: return 3;
        case G_PIN: return 4;
        case A_PIN: return 5;
        case B_PIN: return 6;
        case _C_PIN: return 7;
        default: return -1;
        }
    }

    void detachOdd() {
        unsigned long now = millis();
        for (auto & servo : servos) {
            if (servo.attached() && now - servo.getLastPlay() > 0.1 * 1000) {
                servo.detach();
            }
        }
    }
};
