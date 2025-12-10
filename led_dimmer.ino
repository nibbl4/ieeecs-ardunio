/ --- Değişken Tanımlamaları ---
// Bu satırlar kodda eksikti, çalışması için ekledim.
const int potPin = A0; // Potansiyometrenin orta bacağının bağlı olduğu
Analog pin
const int ledPin = 3; // LED'in bağlı olduğu PWM özellikli (~) dijital pin
void setup() {
// Pin modlarını ayarla
pinMode(ledPin, OUTPUT); // LED ışık vereceği için ÇIKIŞ olarak ayarlanır
// Not: Analog giriş (potPin) için pinMode yapmaya gerek yoktur, otomatik
algılanır.
Serial.begin(9600); // Bilgisayara veri göndermek için seri haberleşmeyi
başlat
}
void loop() {
// --- Veri Okuma ---
// Potansiyometreden 0 ile 1023 arasında bir değer okunur (Arduino ADC'si
10-bit'tir).
int potValue = analogRead(potPin);
// --- Dönüştürme İşlemi (Mapping) ---
// Okunan değer (0-1023), LED parlaklığı için gereken (0-255) aralığına
orantılanır.
// Çünkü analogWrite fonksiyonu en fazla 8-bit (0-255) değer kabul eder.
int brightness = map(potValue, 0, 1023, 0, 255);
// --- Ekrana Yazdırma (Hata Ayıklama) ---
// Seri Monitörden değerleri izlemek için yanyana yazdırıyoruz.
Serial.print("potValue = ");
Serial.print(potValue); // Ham okunan değer
Serial.print(" brightness = ");
Serial.println(brightness); // Dönüştürülmüş (parlaklık) değeri
// --- LED Kontrolü ---
// Hesaplanan parlaklık değeri LED'e gönderilir (PWM Sinyali).
// 0 -> LED sönük, 255 -> LED tam parlak, 127 -> Yarı parlak.
analogWrite(ledPin, brightness);
// Döngünün çok hızlı akıp seri portu kilitlememesi için minik bir bekleme
(opsiyonel)
delay(10);
}
