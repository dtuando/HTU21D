#include <Adafruit_HTU21DF.h>
#include <ESP8266WiFi.h>
#include <PString.h>
#include <Streaming.h>

Adafruit_HTU21DF htu;

void
setup()
{
  WiFi.disconnect();
  WiFi.persistent(false);
  WiFi.mode(WIFI_AP);

  htu.begin();
}

void
loop()
{
  char buf[32];
  PString out(buf, sizeof(buf));
  out << (htu.readTemperature() * 1.8) + 32 << "°F " << htu.readHumidity() << "%" << " HTU21D";
  WiFi.softAP(out);
  delay(10000);
}