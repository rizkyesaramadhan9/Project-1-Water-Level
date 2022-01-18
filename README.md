# Project-1
Project 1 ini memuat source code Arduino dan library yang digunakan untuk merancang sebuah alat pendeteksi ketinggian air/waterlevel (dalam kasus ini dibangun sebagai alat pendeteksi banjir). Project 1 ini seharusnya dirancang pada saat KKN UNILA Periode 1 Tahun 2021, namun saat itu sedang ramai kasus COVID 19 sehingga KKN saya mengalami perubahan konsep. Meskipun begitu, saya berharap source code ini dapat bermanfaat bagi yang ingin merancang alat yang hampir serupa dengan alat yang saya bangun ini.


Pada project ini saya menggunakan alat dan bahan sebagai berikut :
1. Arduino UNO            -> Mikrokontroler utama
2. GSM SIM 800L           -> Modul GSM yang berfungsi mengirimkan peringatan dini (SMS) kepada nomor telepon
3. Buck Converter LM2596  -> Modul penurun tegangan, agar dapat menurunkan tegangan Arduino UNO 5V -> 3.7V - 4.2V sesuai dengan tegangan spesifikasi GSM SIM 800L
4. LCD I2C                -> Menampilkas informasi mengenai status ketinggian air
5. 2N3904 & Resistor (10Kx3; 100kx3)               -> kombinasi rangkaian ini digunakan sebagai pendeteksi ketinggian air
6. Kapasitor 47uF (x3) Paralel dengan Out LM2596   -> Penstabil tegangan keluaran yang dihasilkan dari LM2596 menuju GSM SIM 800L


Ucapan terima kasih saya tunjukkan kepada :
1. Kak Tomi yang telah membantu saya dalam merancang alat ini dari awal, dan mengajarkan kepada saya tentang prinsip kerja dari mikrokontroler.
2. Teman - Teman KKN Periode I Tahun 2021: Kak Dimas Rizqy Pratama, Maghgribi Anjas Ramadhan, Sherly Nova Viona, Yuni Anjelita Br Sipayung, Anggi Anggraeni  yang telah membantu dan menyemangati selama perancangan alat.
3. Paman Yusuf yang telah membantu saya dalam menyolder rangkaian ini pada PCB.
4. Kedua Orang Tua saya, yang telah membantu dan menyemangati selama perancangan alat.
