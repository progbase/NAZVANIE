#pragma once

#include "defines.h"
#include "notes.h"

class Song {
  protected:
    int currentCommand = 0;
    int length;

  public:
    Song() {}
    virtual double getCurrentTime() = 0;
    virtual int getCurrentNote() = 0;
    virtual bool nextCommand() = 0;
};

class JingleBells : protected Song {

  public:
    JingleBells() : Song() { length = ARRAY_LEN(jingleBells); }
    double getCurrentTime() { return jingleBells[currentCommand][0]; }
    int getCurrentNote() { return jingleBells[currentCommand][1]; }
    bool nextCommand() {
        if (currentCommand == length - 1) {
          currentCommand = 0;
          return false;
        }
        currentCommand++;
        return true;
    }
};

class McDonald : protected Song {

public:
    McDonald() : Song() { length = ARRAY_LEN(macdonald); }
    double getCurrentTime() { return macdonald[currentCommand][0]; }
    int getCurrentNote() { return macdonald[currentCommand][1]; }
    bool nextCommand() {
        if (currentCommand == length - 1) {
          currentCommand = 0;
          return false;
        }
        currentCommand++;
        return true;
    }
};

class Cucaracha : protected Song {

public:
    Cucaracha() : Song() { length = ARRAY_LEN(cucaracha); }
    double getCurrentTime() { return cucaracha[currentCommand][0]; }
    int getCurrentNote() { return cucaracha[currentCommand][1]; }
    bool nextCommand() {
        if (currentCommand == length - 1) {
          currentCommand = 0;
          return false;
        }
        currentCommand++;
        return true;
    }
};
