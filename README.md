# VGA output for the Raspberry Pico in the Arduino IDE

A modified version of this great library:VGA output by Hunter Adams (https://github.com/vha3/Hunter-Adams-RP2040-Demos/tree/master/VGA_Graphics) adapted for the Arduino IDE

This version has a buffer of 640x240 instead of the original 640x480.
The advantage is that it in lowering half the resolution, it has enough RAM memory to have double buffer (two frames). Then you can write graphics on the next frame instead of directly drawing on the screen buffer, is more effective for drawing moving simple graphics (ie: there is no need of drawing black in order to draw again)

The new scanline method was based on this great tutorial: http://www.breatharian.eu/hw/picoqvga/index_en.html#pioprogram

# Usage:
open "VGA_graphics_tarci_library_arduino.ino" file with Arduino IDE, connect the pins as directed and watch the example.
