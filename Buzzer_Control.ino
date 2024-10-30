// bibliotecas necesarias
#include <SoftwareSerial.h>  // Biblioteca para comunicación serial con el módulo GSM

// Configuración de pines
#define LASER_PIN D1          // Pin donde está conectado el láser (opcional si el láser siempre está encendido)
#define PHOTO_DETECTOR_PIN D2 // Pin donde está conectado el fotodetector
#define GSM_RX_PIN D5         // Pin RX del ESP8266 conectado al TX del módulo GSM
#define GSM_TX_PIN D6         // Pin TX del ESP8266 conectado al RX del módulo GSM

// Configuración de SoftwareSerial para el módulo GSM
SoftwareSerial gsmSerial(GSM_RX_PIN, GSM_TX_PIN);

// Variables para el estado del fotodetector
bool laserInterrupted = false;
bool lastLaserState = true; // Asume que inicialmente el láser está presente

void setup() {
  // Configuración de los pines
  pinMode(LASER_PIN, OUTPUT);            // Configura el pin del láser como salida
  digitalWrite(LASER_PIN, HIGH);         // Activa el láser (siempre encendido)
  pinMode(PHOTO_DETECTOR_PIN, INPUT);    // Configura el pin del fotodetector como entrada

  // Inicializa la comunicación serial con el módulo GSM
  gsmSerial.begin(9600);  // Velocidad de baudios para el módulo GSM
  Serial.begin(115200);   // Monitor serial para depuración

  // Espera a que el módulo GSM se conecte
  Serial.println("Inicializando el módulo GSM...");
  delay(1000);
  gsmSerial.println("AT"); // Envía un comando AT para verificar la comunicación
  delay(1000);

  // Configuración inicial del módulo GSM para SMS
  gsmSerial.println("AT+CMGF=1"); // Configura el modo de mensaje de texto (SMS)
  delay(1000);
}

void loop() {
  // Lee el estado del fotodetector
  bool laserState = digitalRead(PHOTO_DETECTOR_PIN);

  // Detecta si el haz del láser ha sido interrumpido
  if (laserState == LOW && lastLaserState == HIGH) {
    laserInterrupted = true;  // El láser fue interrumpido
    Serial.println("¡Láser interrumpido! Enviando alerta...");
    sendAlert(); // Llama a la función para enviar la alerta SMS
  }

  // Actualiza el estado del láser
  lastLaserState = laserState;

  // Pequeña pausa para evitar rebotes de señal
  delay(100);
}

// Función para enviar un SMS de alerta
void sendAlert() {
  gsmSerial.println("AT+CMGS=\"+56975414197\""); // Reemplazar con el número de teléfono del destinatario
  delay(1000);
  gsmSerial.println("Alerta: La puerta ha sido abierta."); // Mensaje de alerta
  delay(100);
  gsmSerial.write(26); // Envía el carácter Ctrl+Z para enviar el SMS
  delay(1000);

  Serial.println("Mensaje de alerta enviado.");
}
