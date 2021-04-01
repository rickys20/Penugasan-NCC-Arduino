# Alat Deteksi Kedalaman Air

Alat Deteksi Kedalaman air adalah salah satu alat yang dapat mendeteksi serta memberi peringatan kepada pengguna jika kedalaman air tersebut sudah mencapai batas tampung air. Saya memilih alat pendeteksi air karena alat ini menggunakan sensor jarak dalam penggunaan arduino. Berikut mengenai sistem kerja pada Alat Deteksi
![image](https://user-images.githubusercontent.com/73892020/113332676-b1380180-934b-11eb-91a7-0d1c4f910ab5.png)

Pada gambar tersebut prinsip dari sensor jarak yaitu memantulkan gelombang dan menghitung waktu gelombang tersebut kembali. Pada sistem penggunaan dari rangkain tersebut seperti berikut:

1. Sistem akan mencetak jarak suatu objek terhadap sensor
2. Pada kasus jarak diatas 100 cm maka LCD akan melakukan print pada `lcd.setCursor(0,0);`berisi data berupa jarak dalam cm, dan pada `lcd.setCursor(0,1)`; berisi data jarak inch
3. Pada Kasus jarak objek dibawah 100 cm `lcd.setCursor(0,0);` akan tetap memeberi keterangan jarak, dan pada `lcd.setCursor(0,1);`akan memberi peringatan terhadap pengguna untuk mematikan seperti kran air, dan pompa air.
4. Pada kasus jarak objek dibawah 100 cm juga akan menghidupkan led merah sebagai penanda.Jika jarak diatas 100 cm maka led tersebut akan mati.

# Implementasi

Pada implementasi diperlukan `#include <LiquidCrystal.h>` untuk library dari lcd.


## Tugas 3


LINK TINKERCAD : https://www.tinkercad.com/things/7KETNHXUrDL-tugas-3-ncc
