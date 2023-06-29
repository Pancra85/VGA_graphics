const int numRectangles = 40;             // Número de rectángulos
static float scaleFactors[numRectangles];  // Factores de escala de los rectángulos
static float scaleSpeed = 0.2;            // Velocidad de cambio de escala
static float maxScale = 2;               // Escala máxima
static float finalX = screenWidth / 2;
static float finalY = screenHeight / 2;
//float transparencies[numRectangles];  // Transparencia de los rectángulos
//byte colors[numRectangles];          // Colores aleatorios de los rectángulos

void initTunnel() {
  // Asignar valores iniciales a los factores de escala y transparencias
  for (int i = 0; i < numRectangles; i++) {
    scaleFactors[i] = maxScale / numRectangles * i;
    //transparencies[i] = 255;
  }

  //  // Generar colores aleatorios para los rectángulos
  //  for (int i = 0; i < numRectangles; i++) {
  //    colors[i] = color(random(255), random(255), random(255));
  //  }
}

void tunnel() {
  // Calcular la posición inicial en función del tiempo
  float time = millis() * 0.001;  // Tiempo en segundos
  int initialX = screenWidth / 2 + cos(time) * 100;
  int initialY = screenHeight / 2 + sin(time) * 100;

  // Actualizar y dibujar los rectángulos
  for (int i = 0; i < numRectangles; i++) {
    // Incrementar el factor de escala
    scaleFactors[i] = scaleFactors[i] + scaleSpeed / 10;
//    Serial.print("sc fact:");
//    Serial.println(scaleFactors[i]);
    // Verificar si se alcanzó el límite máximo
    if (scaleFactors[i] > maxScale) {
      scaleFactors[i] = 0;  // Restablecer el factor de escala a cero
      //Serial.println(scaleFactors[i]);
    }

    // Calcular la posición del rectángulo en función del factor de escala
    float x = initialX * (1 - scaleFactors[i]) + finalX * scaleFactors[i];
    float y = initialY * (1 - scaleFactors[i]) + finalY * scaleFactors[i];

    // Calcular el tamaño del rectángulo en función del factor de escala
    int rectSize = 100 * scaleFactors[i] * scaleFactors[i] * scaleFactors[i];
    //Serial.println(rectSize);

    // // Calcular la transparencia en función de la posición del mouse
    // if (i == 0) {
    //   transparencies[i] = map(mouseX, 0, width, 0, 255);
    //   fill(colors[i], transparencies[i]);
    // } else {
    //   transparencies[i] = 255;
    //   noFill();
    // }

    // stroke(255);
    drawRectCenter(x, y, rectSize, rectSize, RED);
    //    Serial.print("x:");
    //    Serial.println(x);
    //    Serial.print("y:");
    //    Serial.println(y);
    //    Serial.print("size:");
    //    Serial.println(rectSize);
  }
}
