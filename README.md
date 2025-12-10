Arduino Kodları – LED Dimmer & Park Sensörü

Bu repo, iki farklı Arduino örnek projesinin kodlarının ne yaptığını açıklayan bir dokümantasyon içerir. Kodlar öğrenme, etkinlik, sunum ve eğitim ortamlarında kullanılmak üzere sadeleştirilmiş ve anlaşılır hâle getirilmiştir.

## 1) LED Dimmer – Kod Açıklaması

Bu kod, bir potansiyometreden okunan analog değeri kullanarak LED'in parlaklığını kontrol eder.

Kodun İşleyişi

Arduino, potansiyometreden 0–1023 arası bir analog değer okur.

Okunan değer, LED'in parlaklığı için gereken 0–255 aralığına dönüştürülür (map() fonksiyonu).

analogWrite() fonksiyonu ile LED’e PWM sinyali gönderilir ve parlaklık bu sinyale göre değişir.

Serial Monitor üzerinden hem ham değer hem de parlaklık değeri görüntülenir.

Davranış Özeti

Potansiyometre sola çevrilirse → LED kararır

Sağ çevrilirse → LED parlaklaşır

Değerler anlık olarak yenilenir ve seri portta gözlemlenebilir.

## 2) Park Sensörü – Kod Açıklaması

Bu kod, HC-SR04 ultrasonik sensör ile mesafeyi ölçer ve engel yaklaştıkça buzzer’ın frekansını değiştiren bir uyarı sistemi oluşturur.

Kodun İşleyişi

Sensöre 10 µs’lik bir tetik sinyali gönderilir.

Echo pininden dönen ses dalgasının süresi ölçülür (pulseIn).

Ölçülen süre, ses hızına göre cm cinsinden mesafeye dönüştürülür.

Mesafe 30 cm’den küçükse, buzzer devreye girer ve yakınlık arttıkça daha yüksek frekansta öter.

Mesafe 30 cm’den büyükse, buzzer tamamen susar.

Davranış Özeti

Engelin uzaklığı arttıkça → Buzzer daha kalın ve yavaş ses verir

Engelin uzaklığı azaldıkça → Buzzer daha ince ve hızlı ses çıkarır

Bu mantık, gerçek araç park sensörlerindeki çalışma prensibine benzer.

## Genel Bakış – Kodlar Ne Öğretiyor?

Bu iki örnek kod, Arduino dünyasındaki temel kavramlara odaklanır:

LED Dimmer

Analog okuma

PWM çıkışı

Değer dönüştürme (mapping)

Park Sensörü

Ultrasonik mesafe ölçümü

Zaman → mesafe dönüşümü

Yakınlığa göre değişen uyarı sistemi

Bu projeler, sensör kullanımı ve fiziksel çıktı üretme gibi konularda başlangıç seviyesinde güçlü bir temel oluşturur.

## Dosya Yapısı
/LED-Dimmer/
    led_dimmer.ino

/Park-Sensoru/
    park_sensor.ino

README.md

## Lisans

Bu içerik eğitim ve etkinlik amaçlı serbestçe kullanılabilir.
