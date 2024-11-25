README: OpenAlert

Descripción del Proyecto
OpenAlert es un sistema de seguridad basado en un sensor infrarrojo que detecta la apertura de puertas. Este dispositivo envía una notificación al propietario a través de un correo electrónico cada vez que la puerta es abierta. Diseñado para ofrecer una solución económica y efectiva para monitorear accesos, OpenAlert es ideal para hogares, oficinas y pequeños negocios.

Características.

Monitoreo continuo de la puerta mediante un sensor infrarrojo.
Envío automático de notificaciones por correo electrónico al detectar actividad.
Conexión a redes WiFi para una integración eficiente.
Configuración simple y adaptable a diferentes entornos.
Basado en hardware ESP8266, económico y ampliamente disponible.

Requisitos del Proyecto

Hardware:
Placa ESP8266.
Sensor infrarrojo (por ejemplo, KY-022).
Resistencia de 10kΩ para la conexión del sensor.
Fuente de alimentación compatible con ESP8266 (5V).
Cables de conexión y protoboard (opcional).

Software:
Arduino IDE.
Biblioteca ESP8266WiFi (instalada desde el Administrador de Bibliotecas de Arduino).
Biblioteca para envío de correos electrónicos si se implementa (como ESP8266SMTP o SMTPClient).
Configuración del Proyecto
Instalar Arduino IDE:

Descarga e instala el Arduino IDE.
Configurar la Placa ESP8266 en el Arduino IDE:

Ve a Archivo → Preferencias.
Agrega este enlace en "Gestor de URLs Adicionales de Tarjetas":
http://arduino.esp8266.com/stable/package_esp8266com_index.json.
Ve a Herramientas → Placa → Gestor de tarjetas e instala el paquete "esp8266".
Conexión del Hardware:

Conecta el sensor infrarrojo al ESP8266:
VCC a 3.3V del ESP8266.
GND a GND del ESP8266.
OUT a un pin digital (por defecto D1 en el código).
Configurar el Código:

Abre el archivo .ino en el Arduino IDE.
Modifica las líneas del código para agregar tu red WiFi:
cpp
Copiar código
const char* ssid = "Tu_SSID";
const char* password = "Tu_Contraseña";
Carga el código a la placa.
Prueba Inicial:

Conecta el ESP8266 al ordenador.
Abre el Monitor Serial (Ctrl+Shift+M) en el Arduino IDE y observa las lecturas del sensor.
Estructura del Código
Configuración inicial: Configuración de WiFi y definición del sensor.
Loop principal: Detección de cambios en el sensor infrarrojo.
Funciones adicionales: Punto para implementar envío de correos u otras notificaciones.
Uso
Alimenta el ESP8266 y verifica que se conecta al WiFi.
Instala el sensor en el marco de la puerta.
Monitorea las notificaciones enviadas desde el dispositivo.

Limitaciones
Requiere acceso a una red WiFi estable.
No incluye batería de respaldo (puede añadirse como mejora).

Futuras Mejoras
Agregar envío de notificaciones por SMS o aplicaciones móviles.
Implementar una batería de respaldo.
Integración con asistentes virtuales como Alexa o Google Assistant.

Licencia
Este proyecto es de código abierto bajo la Licencia MIT. Puedes modificarlo y distribuirlo según las necesidades, pero se agradece mencionar el proyecto original.

Contacto
Para preguntas o sugerencias, puedes contactar a [alarma.infrarrojo@gmail.com].
