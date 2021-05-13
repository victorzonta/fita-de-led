#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFiMulti.h> 
#include <IRremote.h>

// #define  R D3
// #define  G D2
// #define  B D1

// #define ON                0xF7C03F*
// #define OFF               0xF740BF*

// #define RED               0xF730CF
// #define GREEN             0xF7A05F*
// #define BLUE              0xF7609F*
// #define WHITE             0xF7E01F*

// #define ORANGE            0xF710EF*
// #define YELLOW_DARK       0xF730CF
// #define YELLOW_MEDIUM     0xF708F7 
// #define YELLOW_LIGHT      0xF728D7*

// #define GREEN_LIGHT       0xF7906F
// #define GREEN_BLUE1       0xF7B04F
// #define GREEN_BLUE2       0xF78877
// #define GREEN_BLUE3       0xF7A857

// #define BLUE_RED          0xF750AF
// #define PURPLE_DARK       0xF7708F*
// #define PURPLE_LIGHT      0xF748B7*
// #define PINK              0xF76897*

// #define party             0xF7D02F*
//#define moreshine          0xF700FF*

IRsend irsend;
unsigned long valor;
decode_results res;
decode_type_t tipo;

ESP8266WiFiMulti wifiMulti; 
ESP8266WebServer server(80);
void handleRoot();
void changetored();
void changetogreen();
void changetoblue();
void changetoamarelo();
void changetooff();
void changetopurple();
void changetoparty();
void changetowhite();
void changetoorange();
void changetopink();
void changetodarkpurple();
void changetoon();
void changetowatergrenn();
void changetomoreshine();

void setup() {
  // pinMode ( R, OUTPUT);
  // pinMode ( G, OUTPUT);
  // pinMode ( B, OUTPUT);
  Serial.begin(9600);
  wifiMulti.addAP("WIFI", "SENHA");
  Serial.println("Connecting ...");
  int i = 0;
  while (wifiMulti.run() != WL_CONNECTED) { // Wait for the Wi-Fi to connect: scan for Wi-Fi networks, and connect to the strongest of the networks above
    delay(250);
    Serial.print('.');
  }
  Serial.println('\n');
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());              // Tell us what network we're connected to
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.on("/vermelho", changetored);
  server.on("/verde", changetogreen);
  server.on("/azul", changetoblue);
  server.on("/amarelo", changetoamarelo);
  server.on("/off", changetooff);
  server.on("/roxo", changetopurple);
  server.on("/festa",changetoparty);
  server.on("/branco", changetowhite);
  server.on("/on", changetoon);
  server.on("/laranja", changetoorange);
  server.on("/pink", changetopink);
  server.on("/rochao", changetodarkpurple);
  server.on("/verdin", changetowatergrenn);
  server.on("/+brilho",changetomoreshine);
  server.begin();                           // Actually start the server
  Serial.println("HTTP server started"); 
 
}

void loop() {
  server.handleClient();

}

void changetored() {
  valor=0xEF00;//mudar para valor certo
   irsend.sendNEC(valor,32); 
   Serial.println(valor,HEX); 
   tipo=res.decode_type;
   Serial.println(tipo); 
  server.send(200, "text/plain", "vermelho");
}

void changetogreen() {
   valor=0xF7A05F;
   irsend.sendNEC(valor,32); 
   Serial.println(valor,HEX); 
   tipo=res.decode_type;
   Serial.println(tipo); 
  server.send(200, "text/plain", "verde");
}

void changetoblue() {
  valor=0xF7609F;
   irsend.sendNEC(valor,32); 
   Serial.println(valor,HEX); 
   tipo=res.decode_type;
   Serial.println(tipo); 
  server.send(200, "text/plain", "azul");
}

void changetoamarelo() {

   valor=0xF728D7;
   irsend.sendNEC(valor,32); 
   Serial.println(valor,HEX); 
   tipo=res.decode_type;
   Serial.println(tipo); 

  server.send(200, "text/plain", "amarelo");
}

void changetooff() {
  valor=0xF740BF;
   irsend.sendNEC(valor,32); 
   Serial.println(valor,HEX); 
   tipo=res.decode_type;
   Serial.println(tipo); 
  server.send(200, "text/plain", "off");
}

void changetopurple() {
  valor=0xF748B7;
   irsend.sendNEC(valor,32); 
   Serial.println(valor,HEX); 
   tipo=res.decode_type;
   Serial.println(tipo); 
  server.send(200, "text/plain", "roxo");
}

void changetodarkpurple() {
   valor=0xF7708F;
   irsend.sendNEC(valor,32); 
   Serial.println(valor,HEX); 
   tipo=res.decode_type;
   Serial.println(tipo); 
  server.send(200, "text/plain", "rochao");
}

void changetoon() {
   valor=0xF7C03F;
   irsend.sendNEC(valor,32); 
   Serial.println(valor,HEX); 
   tipo=res.decode_type;
   Serial.println(tipo); 
  server.send(200, "text/plain", "to on");
}

void changetoparty() {
   valor=0xF7D02F;
   irsend.sendNEC(valor,32); 
   Serial.println(valor,HEX); 
   tipo=res.decode_type;
   Serial.println(tipo); 
  server.send(200, "text/plain", "festaaaaaa!!!!!!!!!!");
}

void changetowhite() {
   valor=0xF7E01F;
   irsend.sendNEC(valor,32); 
   Serial.println(valor,HEX); 
   tipo=res.decode_type;
   Serial.println(tipo); 
  server.send(200, "text/plain", "to palido");
}

void changetoorange() {
   valor=0xF710EF;
   irsend.sendNEC(valor,32); 
   Serial.println(valor,HEX); 
   tipo=res.decode_type;
   Serial.println(tipo); 
  server.send(200, "text/plain", "laranja");
}

void changetopink() {
   valor=0xF76897;
   irsend.sendNEC(valor,32); 
   Serial.println(valor,HEX); 
   tipo=res.decode_type;
   Serial.println(tipo); 
  server.send(200, "text/plain", "rosa");
}

void changetowatergrenn() {
   valor=0xF78877;
   irsend.sendNEC(valor,32); 
   Serial.println(valor,HEX); 
   tipo=res.decode_type;
   Serial.println(tipo); 
  server.send(200, "text/plain", "to verdin");
}

void changetomoreshine() {
   valor=0xF700FF;
   irsend.sendNEC(valor,32); 
   Serial.println(valor,HEX); 
   tipo=res.decode_type;
   Serial.println(tipo); 
  server.send(200, "text/plain", "mais brilhoo");
}


void handleRoot() {
  server.send(200, "text/plain", "led zonta on");   // Send HTTP status 200 (Ok) and send some text to the browser/client
}