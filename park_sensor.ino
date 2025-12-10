// --- Değişken Tanımlamaları ---
const int trigPin = 9;     // HC-SR04 sensörünün Tetik (Trigger) bacağının bağlı olduğu pin
const int echoPin = 10;    // HC-SR04 sensörünün Yankı (Echo) bacağının bağlı olduğu pin
const int buzzerPin = 11;  // Sesli uyarı verecek buzzer'ın bağlı olduğu pin

void setup() {
  // Pinlerin giriş/çıkış modlarını ayarla
  pinMode(trigPin, OUTPUT);   // Trig pini ses dalgası göndereceği için ÇIKIŞ
  pinMode(echoPin, INPUT);    // Echo pini dönen dalgayı okuyacağı için GİRİŞ
  pinMode(buzzerPin, OUTPUT); // Buzzer ses vereceği için ÇIKIŞ

  Serial.begin(9600);         // Seri haberleşmeyi başlat (hata ayıklama için kullanılabilir)
}

void loop() {
  // --- Mesafe Ölçüm İşlemi Başlangıcı ---
  // Temiz bir sinyal için önce trig pinini LOW yapıyoruz
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sensörü tetiklemek için 10 mikrosaniyelik bir HIGH sinyali gönderiyoruz
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Echo pininden dönen sinyalin süresini (mikrosaniye cinsinden) okuyoruz.
  // 30000 µs (30 ms) zaman aşımıdır; bu süre içinde yanıt gelmezse beklemeyi bırakır.
  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    // Sensör okuyamadıysa veya menzil dışıysa:
    // Buzzer susturulur ve hatalı ölçümü önlemek için döngü başa döner.
    noTone(buzzerPin);
    return;
  }

  // --- Mesafe Hesaplama ---
  // Ses hızı havada yaklaşık 340 m/s'dir → 0.034 cm/mikrosaniye.
  // Sinyal gidip geri geldiği için süre 2'ye bölünerek tek yön mesafe hesaplanır.
  float distance = duration * 0.034 / 2.0;

  // --- Uyarı Sistemi ---
  if (distance < 30) {
    // Mesafe 0–30 cm arasındaysa buzzer devreye girer.
    // Mesafe küçüldükçe frekans artar → daha hızlı/tiz ses.
    int pitch = map(distance, 0, 30, 1000, 200);
    tone(buzzerPin, pitch);
  } else {
    // Engel 30 cm'den uzaktaysa buzzer kapatılır.
    noTone(buzzerPin);
  }

  // Stabil ölçüm için kısa bir bekleme
  delay(100);
}
