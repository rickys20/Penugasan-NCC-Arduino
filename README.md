# Alat Deteksi Jarak

Alat Deteksi Kedalaman air adalah salah satu alat yang dapat mendeteksi serta memberi peringatan kepada pengguna jika kedalaman air tersebut sudah mencapai batas tampung air.Pada kasus ini saya mengambil objek yaitu busa yang jika semakin bertambah tinggi air maka busa tersebut mendekati sensor jarak. Saya memilih alat pendeteksi air karena alat ini menggunakan sensor jarak dalam penggunaan arduino. Berikut mengenai sistem kerja pada Alat Deteksi
![image](https://user-images.githubusercontent.com/73892020/113332676-b1380180-934b-11eb-91a7-0d1c4f910ab5.png)

Pada gambar tersebut prinsip dari sensor jarak yaitu memantulkan gelombang dan menghitung waktu gelombang tersebut kembali. Pada sistem penggunaan dari rangkain tersebut seperti berikut:

1. Sistem akan mencetak jarak suatu objek terhadap sensor
2. Pada kasus jarak diatas 100 cm maka LCD akan melakukan print pada `lcd.setCursor(0,0);`berisi data berupa jarak dalam cm, dan pada `lcd.setCursor(0,1)`; berisi data jarak inch
3. Pada Kasus jarak objek dibawah 100 cm `lcd.setCursor(0,0);` akan tetap memeberi keterangan jarak, dan pada `lcd.setCursor(0,1);`akan memberi peringatan terhadap pengguna untuk mematikan seperti kran air, dan pompa air.
4. Pada kasus jarak objek dibawah 100 cm juga akan menghidupkan led merah sebagai penanda.Jika jarak diatas 100 cm maka led tersebut akan mati.

# Implementasi

Pada implementasi diperlukan `#include <LiquidCrystal.h>` untuk library dari lcd. Pada implementasi terdapat `LiquidCrystal lcd(12, 11, 5, 4, 3, 2);` sebagai inisialisasi pada library. Pada deklarasi awal seperti berikut:
```
int trigPin = 10;
int echoPin = 9;
int led =13;
long duration;
int distanceCm, distanceInch;
```

Pada deklarasi tersebut terdapat `trigPin` dan `echoPin` yang tersambung pada sensor ultrasonic.Pada dungsi dari sensor ultrasonic seperti berikut:
1. VCC = 5V Power Supply. Pin sumber tegangan positif sensor.
2. Trig = Trigger/Penyulut. Pin ini yang digunakan untuk membangkitkan sinyal ultrasonik.
3. Echo = Receive/Indikator. Pin ini yang digunakan untuk mendeteksi sinyal pantulan ultrasonik.
4. GND = Ground/0V Power Supply. Pin sumber tegangan negatif sensor.

Untuk setup seperti berikut:
```
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  // lcd.print("hello, world!");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
}
```
Pada setup `trigPin` dan `led` berperan sebagai output dan `echoPin` berperan sebagai input.

Pada loop kita mengambil data cm dan inch seperti berikut:
```
  duration = pulseIn(echoPin, HIGH);
  distanceCm= (duration/2) / 29.1;
  distanceInch = (duration/2) / 74;
```

Pada lcd baris pertama digunakan penghitungan jarak menggunakan cm:
```
  lcd.setCursor(0,0);
  lcd.print("Jarak: ");
  lcd.print(distanceCm);
  lcd.print(" cm ");
``` 
Pada tampilan lcd baris kedua menggunakan `if else` yaitu kasus jika jarak objek diatas 100 cm dan dibawah 100 cm:
```
   if (distanceCm <= 100)
	{
	  digitalWrite(led, HIGH);
      lcd.setCursor(0,1);
	  lcd.print("FULL!!");
      lcd.print("Turn Off!!!");
	}
    else{
      digitalWrite (led, LOW);
      lcd.setCursor(0,1);
	  lcd.print("Jarak: ");
      lcd.print(distanceInch);
      lcd.print(" Inch ");
    }
```

## Tugas 3

Berikut link implementasi langsung pada tinkercad
LINK TINKERCAD : https://www.tinkercad.com/things/7KETNHXUrDL-tugas-3-ncc
