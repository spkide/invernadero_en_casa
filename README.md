🌱 Sistema de Riego Automático con ESP32, DHT11, FC-28 y Control Web

Este proyecto implementa un sistema de riego automático utilizando un ESP32, un sensor de humedad de suelo FC-28, un sensor de temperatura/humedad DHT11 y un módulo relé para controlar una bomba de agua o motor.
Además, incluye un servidor web que permite encender y apagar el motor manualmente desde cualquier dispositivo conectado a la misma red WiFi.

🚀 Características

Lectura de humedad del suelo (FC-28)

Lectura de temperatura y humedad ambiente (DHT11)

Control manual del motor/bomba mediante interfaz web

Visualización de datos en tiempo real

Código optimizado para ESP32

Compatible con redes WiFi 2.4Ghz

Listo para añadir funciones avanzadas (riego automático, historiales, gráficos, etc.)

📡 Panel Web del ESP32

El ESP32 genera una página web donde puedes:

Ver el estado del motor

Encender o apagar el motor

Ver temperatura

Ver humedad relativa ambiente

Ver humedad del suelo

Se accede desde el navegador ingresando la IP mostrada en el monitor serie.

🖧 Conexiones de Hardware

Aquí está el diagrama completo (sube tu imagen Fritzing con este nombre):

/imagenes/diagrama_fritzing.jpg


Agrega en tu repo:

![Diagrama del proyecto](imagenes/diagrama_fritzing.jpg)

🛠️ Materiales

ESP32

Sensor de humedad de suelo FC-28

Sensor DHT11

Módulo relé de 1 o más canales

Bomba/motor de agua

Fuente de alimentación (powerbank o batería)

Protoboard y cables Dupont

📄 Código del Proyecto

El código incluye:

Configuración WiFi

Lectura de sensores

Servidor web

Control del relé

Puedes encontrar el código completo en:
📁 /src/main.cpp (o tu ruta final)

▶️ Cómo usar

Configura tu SSID y contraseña en el código.

Sube el programa al ESP32.

Abre el monitor serie y espera la IP asignada.

Entra a esa IP en tu navegador.

Controla el motor y revisa los sensores en tiempo real.

📈 Futuras mejoras (opcional)

Activar motor automáticamente si el suelo está seco

Agregar base de datos para registrar datos históricos

Gráfico en tiempo real con Chart.js

App móvil

Control por Telegram o MQTT

📜 Licencia

Este proyecto es de uso libre. Puedes modificarlo, mejorarlo o adaptarlo como desees.
