#include "xylophone.h"
#include "songs.h"

Xylophone xyl;
JingleBells bells;
McDonald donald;
Cucaracha cukaracha;

int index = 0;

void setup() {}

void loop() {
    if (index == 0) {
      if (!xyl.play(bells)) 
        changeIndex();
    } else if (index == 1) {
      if (!xyl.play(donald))
        changeIndex();
    } else if (!xyl.play(cukaracha))
      changeIndex();
}

void changeIndex() {
    if (index == 2) {
      index = 0;
    } else index++;
}

