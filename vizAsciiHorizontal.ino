//ejemplo original (https://play.ertdfgcvb.xyz/#/src/basics/rendering_to_canvas)
//by @andreasgysin (https://twitter.com/andreasgysin)

const int cols = 62;        // Número de columnas de celdas
const int rows = 22;        // Número de filas de celdas
const int cellWidth = 11;   // Ancho de cada celda
const int cellHeight = 20;  // Alto de cada celda
const byte textSize = 2;
const byte textColor = RED;
const byte scrollTime = 4;

String chars PROGMEM = "ABCDEFGHIJKLMNOPQRSTUVWXYZ.:!?";  // Caracteres disponibles

void asciiHorizontal() {
  for (int i = -1; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      char character;

      if (i % 2 == 1) {
        int index = (i + j + currentFrame / scrollTime) % chars.length();  // Calcula el índice del carácter
        character = chars.charAt(index);                          // Obtiene el carácter correspondiente
      } else {
        int index = (i + cols - j + currentFrame / scrollTime) % chars.length();  // Calcula el índice del carácter
        character = chars.charAt(index);                                 // Obtiene el carácter correspondiente
      }

      //setTextColor(RED);
      //setTextSize(2);  // Establece el tamaño del texto
      //setTextCursor(j * cellWidth + cellWidth/2,  i * cellHeight + cellHeight/2);
      //textAlign(CENTER, CENTER);               // Alinea el texto en el centro de la celda
      const short int x = (j * cellWidth + cellWidth / 2)+5;
      const short int y = i * cellHeight + cellHeight / 2;
      drawChar(x,y, character,textColor,BLACK,textSize);  // Muestra el carácter en la celda correspondiente
    }
  }
}