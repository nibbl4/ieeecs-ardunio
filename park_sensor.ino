Park Sensörü
// --- Değişken Tanımlamaları ---
const int trigPin = 9; // HC-SR04 sensörünün Tetik (Trigger) bacağının
bağlı olduğu pin
const int echoPin = 10; // HC-SR04 sensörünün Yankı (Echo) bacağının bağlı
olduğu pin
const int buzzerPin = 11; // Sesli uyarı verecek Buzzer'ın bağlı olduğu pin
void setup() {
// Pinlerin giriş/çıkış modlarını ayarla
pinMode(trigPin, OUTPUT); // Trig pini ses dalgası göndereceği için ÇIKIŞ
pinMode(echoPin, INPUT); // Echo pini dönen dalgayı okuyacağı için GİRİŞ
pinMode(buzzerPin, OUTPUT); // Buzzer ses vereceği için ÇIKIŞ
Serial.begin(9600); // Seri haberleşmeyi başlat (Hata ayıklama veya
monitörden izleme gerekirse diye)
}
void loop() {
// --- Mesafe Ölçüm İşlemi Başlangıcı ---
// Temiz bir sinyal için önce pini LOW yapıyoruz
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sensörü tetiklemek için 10 mikrosaniyelik bir ses dalgası gönderiyoruz
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Echo pininden dönen sinyalin süresini (mikrosaniye cinsinden) okuyoruz.
// 30000 (30ms) parametresi zaman aşımıdır; bu süre içinde yanıt gelmezse
beklemez.
long duration = pulseIn(echoPin, HIGH, 30000);
if (duration == 0) {
// Eğer süre 0 ise (sensör okuyamadıysa veya menzil dışıysa)
// Buzzer susturulur ve döngü başına dönülür (hatalı ölçümü önler).
noTone(buzzerPin);
return;
}
// --- Mesafe Hesaplama ---
// Ses hızı havada yaklaşık 340 m/s'dir (0.034 cm/mikrosaniye).
// Sinyal gidip geri geldiği için süre 2'ye bölünür.
float distance = duration * 0.034 / 2.0;
// --- Park Sensörü Mantığı ---
if (distance < 30) {
// Eğer engel 30 cm'den yakınsa uyarı başlar:
// map fonksiyonu: Mesafeyi (0-30 cm) ses frekansına (1000-200 Hz)
dönüştürür.
// Mesafe 0'a yaklaştıkça ses frekansı 1000 Hz olur (daha ince/tiz ses).
// Mesafe 30'a yaklaştıkça ses frekansı 200 Hz olur (daha kalın ses).
int pitch = map(distance, 0, 30, 1000, 200);
tone(buzzerPin, pitch); // Hesaplanan frekansta buzzer'ı öttür.
} else {
// Engel 30 cm'den uzaktaysa buzzer sussun.
noTone(buzzerPin);
}
delay(100); // Ölçümler arasında 100 milisaniye bekle (Stabilite için)
}
