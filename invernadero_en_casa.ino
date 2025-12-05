#include <WiFi.h>
#include <WebServer.h>
#include "DHT.h"

// ------------ CONFIGURACIÓN DEL WIFI ------------
const char* ssid = "Dep-IT";
const char* password = "CGcarmen-31";

// ------------ CONFIG DEL RELÉ ------------
#define RELE_PIN 5   // Pin donde conectaste IN del relé
bool estadoRele = false;

// ------------ CONFIG DEL SENSOR DHT11 ------------
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ------------ CONFIG DEL SENSOR FC-28 ------------
#define FC_PIN 34  // Entrada analógica
int humedadSuelo = 0;

WebServer server(80);

// ------------ GENERAR LA PÁGINA WEB ------------
String paginaWeb() {
  // Leer sensores
  float temp = dht.readTemperature(); // °C
  float hum = dht.readHumidity();     // %
  humedadSuelo = analogRead(FC_PIN);  // 0-4095 en ESP32

  String html = "<!DOCTYPE html><html><head>";
  html += "<meta charset='UTF-8'>";
  html += "<title>Control del Motor</title>";
  html += "<style>";
  html += "body { font-family: Arial; text-align:center; background:#f0f0f0; }";
  html += "h1 { color:#333; }";
  html += "button { width:200px; height:60px; font-size:22px; margin:20px; border:none; border-radius:12px; cursor:pointer; }";
  html += ".on { background:#4CAF50; color:white; }";
  html += ".off { background:#E53935; color:white; }";
  html += "</style></head><body>";

  html += "<h1>Control del Motor de Agua</h1>";

  // Estado del motor
  html += "<p><b>Estado del motor: " + String(estadoRele ? "ENCENDIDO" : "APAGADO") + "</b></p>";

  // Lectura sensores
  html += "<p><b>Temperatura: " + String(temp) + " °C</b></p>";
  html += "<p><b>Humedad ambiente: " + String(hum) + " %</b></p>";
  html += "<p><b>Humedad del suelo (FC-28): " + String(humedadSuelo) + "</b></p>";

  html += "<button class='on' onclick=\"location.href='/encender'\">ENCENDER</button>";
  html += "<button class='off' onclick=\"location.href='/apagar'\">APAGAR</button>";

  html += "</body></html>";
  return html;
}

// ------------ RUTAS DEL SERVIDOR ------------
void handleRoot() {
  server.send(200, "text/html", paginaWeb());
}

void encenderMotor() {
  digitalWrite(RELE_PIN, HIGH);
  estadoRele = true;
  server.send(200, "text/html", paginaWeb());
}

void apagarMotor() {
  digitalWrite(RELE_PIN, LOW);
  estadoRele = false;
  server.send(200, "text/html", paginaWeb());
}

// ------------ SETUP ------------
void setup() {
  Serial.begin(115200);

  pinMode(RELE_PIN, OUTPUT);
  digitalWrite(RELE_PIN, LOW);  // Iniciar apagado
  estadoRele = false;

  dht.begin();

  // Conectar WiFi
  Serial.println("Conectando al WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado!");
  Serial.print("IP del servidor: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/encender", encenderMotor);
  server.on("/apagar", apagarMotor);

  server.begin();
  Serial.println("Servidor web iniciado");
}

// ------------ LOOP ------------
void loop() {
  server.handleClient();
}
