// Arduboy2 library Sprites class drawCompressed() test

/*
To the extent possible under law, Scott Allen has waived all copyright and
related or neighboring rights to this program.
*/

/***************************************
Usage:
  B      Select sprite
  D-pad  Move sprite 1 pixel
 Hold A +
  B      Toggle 1 pixel border
  D-pad  Move sprite with repeat
***************************************/

#include <Arduboy2.h>
#include "images.h"

const uint8_t* image[] = {
  i1x8a,
  i3x8a,
  i16x16a,
  i17x16a,
  i18x16a,
  i19x16a,
  i20x16a,
  i21x16a,
  i22x16a,
  i23x16a,
  i128x64a
};
#define NUM_IMAGES 11

Arduboy2 arduboy;
Sprites sprites;

byte imgNum = 0;

int xPos = 0;
int yPos = 0;

boolean drawBorder = false;

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(60);
}

void loop() {
  if (!arduboy.nextFrame()) {
    return;
  }

  arduboy.pollButtons();

  if (arduboy.justPressed(B_BUTTON)) {
    if (arduboy.pressed(A_BUTTON)) {
      drawBorder = !drawBorder;
    }
    else {
      if (imgNum == NUM_IMAGES - 1) {
        imgNum = 0;
      }
      else {
        imgNum++;
      }
    }
  }

  if (arduboy.justPressed(UP_BUTTON) ||
      arduboy.pressed(UP_BUTTON + A_BUTTON)) {
    yPos--;
  }
  if (arduboy.justPressed(DOWN_BUTTON) ||
      arduboy.pressed(DOWN_BUTTON + A_BUTTON)) {
    yPos++;
  }
  if (arduboy.justPressed(LEFT_BUTTON) ||
      arduboy.pressed(LEFT_BUTTON + A_BUTTON)) {
    xPos--;
  }
  if (arduboy.justPressed(RIGHT_BUTTON) ||
      arduboy.pressed(RIGHT_BUTTON + A_BUTTON)) {
    xPos++;
  }

  arduboy.clear();

  arduboy.setCursor(50, 20);
  arduboy.print("IMG=");
  arduboy.print(imgNum);
  arduboy.setCursor(50, 28);
  arduboy.print("X=");
  arduboy.print(xPos);
  arduboy.setCursor(50, 36);
  arduboy.print("Y=");
  arduboy.print(yPos);

  if (drawBorder) {
    arduboy.drawRect(0, 0, 128, 64);
  }
  
  sprites.drawPlusMask(xPos, yPos, image[imgNum], 0);

  arduboy.display();
}

