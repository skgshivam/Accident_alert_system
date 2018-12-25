
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

//File myFile;
//double x, y;

static const int RXPin = 4, TXPin = 2;
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

LiquidCrystal lcd(A3,A2,A1,10,9,8);

SoftwareSerial mySerial(5,6);// 5 RX 6 TX

int LED_Pin = 7;
int vibr_Pin =3;
//-------------------------------------------------------------
int i=0,k=0;
int  gps_status=0;
double latitude=0; 
double logitude=0;   
String latitudee; 
String logitudee;                    
String Speed="";
String gpsString="";
char *test="$GPRMC";
// The serial connection to the GPS module
//SoftwareSerial gps(4,2);
//-------------------------------------------------------------

bool readLine(File &f, char* line, size_t maxLen) {
  for (size_t n = 0; n < maxLen; n++) {
    int c = f.read();
    //if ( c < 0 && n == 0) return false;  // EOF
    if (c == '\n') {
      line[n] = 0;
      return true;
    }
    line[n] = c;
  }
  return false; // line too long
}

bool readVals(double* v1, double* v2) {
  char line[40], *ptr, *str;
  if (!readLine(myFile, line, sizeof(line))) {
    return false;  // EOF or too long
  }
  *v1 = strtol(line, &ptr, 10);
  if (ptr == line) return false;  // bad number if equal
  while (*ptr) {
    if (*ptr++ == ',') break;
  }
  *v2 = strtol(ptr, &str, 10);
  return str != ptr;  // true if number found
}
//-------------------------------------------------------------------
void setup(){
pinMode(A0, INPUT); // analog

Serial.begin(9600); //init serial 9600
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(LED_Pin, OUTPUT);
pinMode(vibr_Pin, INPUT); //set vibr_Pin input for measurment

 // Serial.println("----------------------Vibration demo------------------------");
 mySerial.begin(9600);
  Serial.begin(9600);
   // Serial.println("99");
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("ACCIDENT ALERT ");
  lcd.setCursor(0,1);
  lcd.print("SYSTEM ");
  delay(100);
  // Start the software serial port at the GPS's default baud
//  Serial.begin(GPSBaud);
  Serial.println();
 // ----------------------------------------------
//   gps.begin(9600);
  get_gps();
  //show_coordinate();
  //------------------------------------------------
}
void SendMessage()
{
   
 // show_coordinate();
  
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+917981823134\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Accident has happened at lat : ");// The SMS text you want to send
  mySerial.println(latitude);
 mySerial.println("long : ");// The SMS text you want to send
mySerial.println(logitude);
mySerial.print("https://www.google.com/maps/search/?api=1&query=");
mySerial.print(latitude);
mySerial.print(",");
mySerial.print(logitude);
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
   Serial.println("MESSAGE SENT !");
  delay(2000);
}
void loop(){
 //-------------------------------------------------------
 ss.begin(GPSBaud);
 while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6);
    }
  }
 //------------------------------------------------------------------------------
  lcd.setCursor(0,0);
  lcd.print("ACCIDENT ALERT ");
  lcd.setCursor(0,1);
  lcd.print("SYSTEM ");
  
   //show_coordinate();

  myFile = SD.open("test3.txt");
  
  if (!myFile) {
    Serial.println("available test3.txt:");

    // read from the file until there's nothing else in it:
     while (readVals(&x, &y)) {
    Serial.print("x: ");
    Serial.println(x);
    Serial.print("y: ");
    Serial.println(y);
    Serial.println();
  }
  Serial.println("Done");
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  //-------------------------------------------------------------------------------------------
  long measurement =TP_init();
  delay(50);
  Serial.print("measurment = ");
  Serial.println(measurement);
  if (measurement > 1000){
    // accident occur 
      Serial.print("measurment = ");
  Serial.println(measurement);
    digitalWrite(LED_Pin, HIGH);
    Serial.begin(9600);
        lcd.print("Are u Safe????");
        delay(2000);
        lcd.clear();
        lcd.print("Press Reset");
        delay(10000);
        SendMessage();
        lcd.clear();
        lcd.print("Message SENT!!");
        delay(1000);
  }
  else{
    digitalWrite(LED_Pin, LOW); 
  }
}

long TP_init(){
  delay(10);
  long measurement=pulseIn (vibr_Pin, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
}
//--------------------------------------------------------
void get_gps()
{
 while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6);
    }
  }
 }
//---------------------------------------------------------------------------

