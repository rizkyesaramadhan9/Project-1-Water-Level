//Create by : Rizky Esa Ramadhan
//For KKN UNILA I 2021

#include <Wire.h>               // Library LCD
#include <LiquidCrystal_I2C.h>  // Library I2C
#include <SoftwareSerial.h>     // Library 800L

LiquidCrystal_I2C lcd(0x27, 16, 2); // Pin LCD
SoftwareSerial SIM800L(3, 2);       // Pin RX | TX

boolean siaga1 = false;
boolean siaga2 = false;
boolean bahaya = false;

void setup()
{
  Serial.begin(115200);   //Serial Komunikasi untuk Serial Monitor
  SIM800L.begin(9600);    //Serial Komunikasi untuk Monitor 800L

  // Deklasrasi Kabel Indikator pada Pin Arduino
  pinMode(8, INPUT);     // Kondisi Siaga 1
  pinMode(9, INPUT);     // Konidsi Siaga 2
  pinMode(10, INPUT);    // Kondisi Bahaya

  //Tampilan Awal di LCD
  lcd.begin();
  lcd.backlight();

  //  Baris 1
  lcd.setCursor(0, 0);
  lcd.print(" WaterLevel SMS ");

  //  Baris 2
  lcd.setCursor(0, 1);
  delay(2000);
  lcd.print("KKN UNILA I 2021");
  delay(1000);

  //  Mebersihkan Tampilan LCD
  lcd.clear();

  //Tampilan di Serial Monitor
  while (!Serial)
  {
    Serial.println("SMS Messages Sender");
  }
  delay(1000);
}

void loop()
{
  //  Tampilan Baris 1 di LCD
  lcd.setCursor(0, 0);
  lcd.print("Status saat ini:");

  //  Tampilan di Serial Monitor
  Serial.println("Status saat ini :\n");
  delay(10000);

  //  Tampilan Baris ke 2 di LCD
  lcd.setCursor(0, 1); //Baris ke 2

  SIM800L.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  //  Logika BOOLEAN
  boolean a = digitalRead (8); // Kondisi SIAGA 1
  boolean b = digitalRead (9); // Kondisi SIAGA 2
  boolean c = digitalRead (10); // Kondisi BAHAYA

  // Format Untuk 800L
  SIM800L.println("AT+CMGF=1");                   // Konfigurasi Mode Teks
  delay(1000);

  if (!c && !b && !a)
  {
    lcd.print("Bahaya->KirimSMS");   // Kondisi Terjadi Bahaya
    if (!bahaya)
    {
      Serial.println("Hubungi=\"08xxxxxxxxxx\"");   // Menampilkan Perintah Mengirim Pesan di Serial Monitor
      Serial.println("Status Dalam Kondisi BAHAYA."); // Isi Pesan Dalam Serial Monitor
      delay(100);

      SIM800L.println("AT+CMGS=\"082297161301\"");    // Mengirim Pesan ke No yang Dituju
      updateSerial();
      SIM800L.print("Status dalam kondisi BAHAYA.");  // Isi Pesan SMS yang Dikirimkan ke No.Tujuan
      updateSerial();
      SIM800L.write(26);
      delay(1000);

      lcd.print("SMS telah Dikirim");
      delay(1000);

      bahaya  = true;
      siaga2  = false;
      siaga1  = false;
    }
  }

  else if (!b && !a)
  {
    lcd.print("Siaga2->KirimSMS");
    if (!siaga2)
    {
      Serial.println("Hubungi=\"08xxxxxxxxxx\"");   // Menampilkan Perintah Mengirim Pesan di Serial Monitor
      Serial.println("Status Dalam Kondisi SIAGA2."); // Isi Pesan Dalam Serial Monitor
      delay(100);

      SIM800L.println("AT+CMGS=\"082297161301\"");    // Mengirim Pesan ke No yang Dituju
      updateSerial();
      SIM800L.print("Status dalam kondisi SIAGA2.");  // Isi Pesan SMS yang Dikirimkan ke No.Tujuan
      updateSerial();
      SIM800L.write(26);
      delay(1000);

      lcd.print("SMS telah Dikirim");
      delay(1000);

      siaga2  = true;
      siaga1  = false;
      bahaya  = false;
    }
  }

  else if (!a)
  {
    lcd.print("SIAGA1->KirimSMS");
    if (!siaga1)
    {
      Serial.println("Hubungi=\"08xxxxxxxxxx\"");     // Menampilkan Perintah Mengirim Pesan di Serial Monitor
      Serial.println("Status Dalam Kondisi SIAGA1."); // Isi Pesan Dalam Serial Monitor
      delay(100);

      SIM800L.println("AT+CMGS=\"08xxxxxxxxxx\"");    // Mengirim Pesan ke No yang Dituju
      updateSerial();
      SIM800L.print("Status dalam kondisi SIAGA1.");  // Isi Pesan SMS yang Dikirimkan ke No.Tujuan
      updateSerial();
      SIM800L.write(26);
      delay(1000);

      lcd.print("SMS telah Dikirim");
      delay(1000);

      siaga1 = true;
      siaga2 = false;
      bahaya = false;
    }
  }
}

void updateSerial()
{
  delay(500);
  while (Serial.available())
  {
    SIM800L.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while (SIM800L.available())
  {
    Serial.write(SIM800L.read());//Forward what Software Serial received to Serial Port
  }
}
