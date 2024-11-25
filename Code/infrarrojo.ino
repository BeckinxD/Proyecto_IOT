#include <ESP8266WiFi.h>
#include <ESP_Mail_Client.h> // Librería ESP_Mail_Client

// Credenciales WiFi
const char* ssid = "Davis-BITRED 2.4G";
const char* password = "reich0969";

// Configuración del servidor SMTP
const char* smtp_host = "smtp.gmail.com";
const int smtp_port = 465; // Puerto para SMTP seguro

// Credenciales del correo electrónico
const char* email_sender = "alarma.infrarrojo@gmail.com";
const char* email_password = "fwjlfkobzwelkcbl";
const char* email_recipient = "davis.albornoz09@gmail.com";

// Objeto SMTP
SMTPSession smtp;

// Configuración de la sesión SMTP
ESP_Mail_Session session_config;

// Configuración del mensaje
SMTP_Message message;

void setup() {
  Serial.begin(115200);

  // Conectar al WiFi
  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConexión WiFi establecida.");

  // Configuración de la sesión SMTP
  session_config.server.host_name = smtp_host;
  session_config.server.port = smtp_port;
  session_config.login.email = email_sender;
  session_config.login.password = email_password;

  // Callback para depuración
  smtp.callback(smtpCallback);
}

void loop() {
  enviarCorreo("Alerta de Movimiento", "Se detectó que la puerta fue abierta.");
  delay(60000); // Espera 1 minuto antes de enviar otro correo
}

// Función para enviar correo electrónico
void enviarCorreo(const String& asunto, const String& mensaje) {
  // Configuración del mensaje
  message.sender.name = "Sensor de Movimiento";
  message.sender.email = email_sender;
  message.subject = asunto.c_str();
  message.addRecipient("Destinatario", email_recipient);
  message.text.content = mensaje.c_str();

  // Conexión y envío del correo
  if (!smtp.connect(&session_config)) {
    Serial.println("Error al conectar al servidor SMTP.");
    return;
  }

  if (!MailClient.sendMail(&smtp, &message)) {
    Serial.print("Error al enviar correo: ");
    Serial.println(smtp.errorReason());
  } else {
    Serial.println("Correo enviado exitosamente.");
  }

  // Limpiar el mensaje después de enviarlo
  message.clear();
}

// Callback para depuración de SMTP
void smtpCallback(SMTP_Status status) {
  Serial.println("Estado de SMTP:");
  Serial.println(status.info());

  if (status.success()) {
    Serial.println("----------------");
    Serial.println("Correo enviado correctamente.");
    Serial.println("----------------");
  }
}
