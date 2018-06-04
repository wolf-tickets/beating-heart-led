#include "LedControl.h"

// Arguments: (Data pin, clock pin, CS pin, number of led arrays)
LedControl lc = LedControl(11, 9, 10, 1);

static void heart() {
  byte heart[8] = {byte(0x00), byte(0x6c), byte(0xfe), byte(0xfe), byte(0xfe), byte(0x7c), byte(0x38), byte(0x10)};

  lc.setRow(0, 0, heart[0]);
  lc.setRow(0, 1, heart[1]);
  lc.setRow(0, 2, heart[2]);
  lc.setRow(0, 3, heart[3]);
  lc.setRow(0, 4, heart[4]);
  lc.setRow(0, 5, heart[5]);
  lc.setRow(0, 6, heart[6]);
  lc.setRow(0, 7, heart[7]);
  return;
}

void setup() {
  /*
    The MAX72XX is in power-saving mode on startup,
    we have to do a wakeup call
  */
  lc.shutdown(0, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 1);
  /* and clear the display */
  lc.clearDisplay(0);




}
void loop() {
  heart();
  for (int i = 5; i < 16; i++) {
    lc.setIntensity(0, i);
    delay(250 / (2 * i));
  }

  for (int i = 15; i > 6; i = i - 2) {
    lc.setIntensity(0, i);
    delay(250 / i);
  }

  for (int i = 7; i < 16; i++) {
    lc.setIntensity(0, i);
    delay(250 / i);
  }

  for (int i = 15; i > 0; i--) {
    lc.setIntensity(0, i);
    delay(350 / (2 * i));
  }
  lc.clearDisplay(0);
  delay(25);
  heart();


}




