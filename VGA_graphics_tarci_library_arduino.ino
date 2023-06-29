/**
   CODIGO ORIGINAL BY Hunter Adams (vha3@cornell.edu)
   Modificado by San Tarcisio (https://www.instagram.com/san_tarcisio/)
   
   vvvvvvvvvvvvvvvvvvvvv

   HARDWARE CONNECTIONS
    - GPIO 16 ---> VGA Hsync
    - GPIO 17 ---> VGA Vsync
    - GPIO 18 ---> 330 ohm resistor ---> VGA Red
    - GPIO 19 ---> 330 ohm resistor ---> VGA Green
    - GPIO 20 ---> 330 ohm resistor ---> VGA Blue
    - RP2040 GND ---> VGA GND

   RESOURCES USED
    - PIO state machines 0, 1, and 2 on PIO instance 0
    - DMA channels 0, 1, 2, and 3
    - 153.6 kBytes of RAM (for pixel color data)

*/

#include "vga_graphics.h"  // VGA graphics library


//TIMER
const byte frameRate = 20;
const unsigned long FRAME_INTERVAL = 1000 / frameRate;  // Intervalo de tiempo para cada frame
unsigned long previousFrameTime = 0;                    // Tiempo previo para el inicio de cada ciclo
unsigned long currentTime;

void setup() {
  initVGA();
  Serial.begin(115200);
  initTunnel();
}

void loop() {
  //CODE HERE RUNS AT CPU SPEED

  currentTime = millis();  // Obtener el tiempo actual
  // Ejecutar draw() una sola vez al comienzo de cada ciclo
  if (currentTime - previousFrameTime >= FRAME_INTERVAL) {
    previousFrameTime = currentTime;
    draw();
  }
}

void draw() {
  //CODE HERE RUNS AT FRAMERATE
  static bool programa;

  if (currentTime % 5000 <= 50) {
    programa = !programa; //changes the example program
  }

  if (programa == 1) {
    tunnel();           //example
  } else {
    asciiHorizontal(); //example
  }
  escribir();         //example

  nextFrame(); //copies temporary buffer to the vga output buffer
  clearScreen(); //deletes temporary buffer, then next frame will be black
}

void escribir() {
  setTextColor2(RED, BLUE);
  setTextCursor(100, 100);
  setTextSize(2);

  char statusTemp[4];
  itoa(currentFrame, statusTemp, 10);
  writeString(statusTemp);
}