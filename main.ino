#include "esp_camera.h"
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

#define CAMERA_MODEL_AI_THINKER 
#include "camera_pins.h"

// WiFi AP setup
const char* ssid = "ESP32_CAM_AP";  
const char* password = "123456789"; 

AsyncWebServer server(80);

void startCameraServer() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String html = "<html><body><h1>ESP32-CAM Video Stream</h1>";
    html += "<img src=\"/stream\">";
    html += "</body></html>";
    request->send(200, "text/html", html);
  });

  server.on("/stream", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "multipart/x-mixed-replace; boundary=frame", [](uint8_t *buffer, size_t len) -> size_t {
      camera_fb_t *fb = NULL;
      fb = esp_camera_fb_get(); 
      if (!fb) {
        Serial.println("Camera capture failed");
        return 0;
      }

      memcpy(buffer, fb->buf, fb->len);
      size_t frame_size = fb->len;

      esp_camera_fb_return(fb);  
      return frame_size; 
    });
  });

  server.begin();
}

void setup() {
  Serial.begin(115200);

  WiFi.softAP(ssid, password);
  Serial.println("Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  startCameraServer();
}

void loop() {
}
