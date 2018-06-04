# beating-heart-led

This is a short arduino loop that uses Eberhard Fahle's excellent LedControl.h library and a MAX7219 IC chip to drive an 8x8 LED matrix.

The MAX7219 is essentially a multiplexer which can extend the Arduino's limited output pins. This loop displays a single image of a heart on a matrix of red LEDs, and "beats" by varying the brightness via pulse-width modulation of the input voltage (the arduino isn't capable of true analog voltage variation). 

This little guy sits in my workshop on top of the bench power supply, and "beats" on power-up when all is well (the power supply is a "vintage" Radio Shack linear variable DC unit which may give out any day).
