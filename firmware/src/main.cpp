#define REMOTEXY_MODE__WIFI_POINT

#include <WiFi.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "classic"
#define REMOTEXY_WIFI_PASSWORD "vitamind"
#define REMOTEXY_SERVER_PORT 6377


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 101 bytes
  { 255,15,0,0,0,94,0,19,0,0,0,0,31,2,106,200,200,84,1,1,
  5,0,1,249,33,57,57,31,11,24,24,1,133,16,70,47,82,0,1,250,
  100,57,57,31,42,24,24,1,35,31,66,47,76,0,1,49,26,57,57,118,
  27,24,24,1,93,24,60,47,115,0,1,59,62,57,57,153,26,24,24,1,
  93,24,114,47,62,0,7,35,76,24,24,68,32,40,10,102,64,16,24,1,
  11 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
 
  uint8_t button_01; // =1 if button pressed, else =0
  uint8_t button_02; // =1 if button pressed, else =0
  uint8_t button_03; // =1 if button pressed, else =0
  uint8_t button_04; // =1 if button pressed, else =0
  char edit_1[11];
    // output variables
  float value_01;

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 


#define MOTOR_FL_PWM 27   //FLW1
#define MOTOR_FL_DIR 26
  
#define MOTOR_FR_PWM 18 //FRW1
#define MOTOR_FR_DIR 19

#define MOTOR_BL_PWM 33  //EN BRW1
#define MOTOR_BL_DIR 25

#define MOTOR_BR_PWM 4
#define MOTOR_BR_DIR 32  //BRW1







#define MOTOR_SFL_DIR 16 //MLW1
#define MOTOR_SFL_PWM  17

#define MOTOR_SFR_DIR 21 ///MRW1
#define MOTOR_SFR_PWM 22

#define MOTOR_SBR_DIR 13 ///MRW1
#define MOTOR_SBR_PWM 15

#define MOTOR_SBL_DIR 14 //MLW1
#define MOTOR_SBL_PWM 23


const int freq = 1000;
const int resolution = 8;
int pwmValue = 0;
int pwms = 0;

#define CH_FL 0
#define CH_FR 1
#define CH_BL 2
#define CH_BR 3
#define CH_SFL 4
#define CH_SFR 5
#define CH_SBR 6
#define CH_SBL 7


void setupLEDC() {
  ledcSetup(CH_FL, freq, resolution);
  ledcAttachPin(MOTOR_FL_PWM, CH_FL);

  ledcSetup(CH_FR, freq, resolution);
  ledcAttachPin(MOTOR_FR_PWM, CH_FR);

  ledcSetup(CH_BL, freq, resolution);
  ledcAttachPin(MOTOR_BL_PWM, CH_BL);

  ledcSetup(CH_BR, freq, resolution);
  ledcAttachPin(MOTOR_BR_PWM, CH_BR);

  ledcSetup(CH_SFL, freq, resolution);
  ledcAttachPin(MOTOR_SFL_PWM, CH_SFL);

  ledcSetup(CH_SFR, freq, resolution);
  ledcAttachPin(MOTOR_SFR_PWM, CH_SFR);

  ledcSetup(CH_SBR, freq, resolution);
  ledcAttachPin(MOTOR_SBR_PWM, CH_SBR);

  ledcSetup(CH_SBL, freq, resolution);
  ledcAttachPin(MOTOR_SBL_PWM, CH_SBL);
}
void stopsteer()
{
  ledcWrite(CH_SFL, 0);
  ledcWrite(CH_SFR, 0);
  ledcWrite(CH_SBR, 0);
  ledcWrite(CH_SBL, 0);
}
void stopMotors() {
  ledcWrite(CH_FL, 0);
  ledcWrite(CH_FR, 0);
  ledcWrite(CH_BL, 0);
  ledcWrite(CH_BR, 0);
  ledcWrite(CH_SFL, 0);
  ledcWrite(CH_SFR, 0);
  ledcWrite(CH_SBR, 0);
  ledcWrite(CH_SBL, 0);

}

void setMotorDirection(bool fl, bool fr, bool bl, bool br) {
  digitalWrite(MOTOR_FL_DIR, fl);
  digitalWrite(MOTOR_FR_DIR, fr);
  digitalWrite(MOTOR_BL_DIR, bl);
  digitalWrite(MOTOR_BR_DIR, br);
}

void moveForward() {
    setMotorDirection(1, 1, 0, 0);
    ledcWrite(CH_FL, pwmValue);
    ledcWrite(CH_FR, pwmValue);
    ledcWrite(CH_BL, pwmValue);
    ledcWrite(CH_BR, pwmValue);
  }
  
  void moveBackward() {
    setMotorDirection(0, 0, 1, 1);
    ledcWrite(CH_FL, pwmValue);
    ledcWrite(CH_FR, pwmValue);
    ledcWrite(CH_BL, pwmValue);
    ledcWrite(CH_BR, pwmValue);
  }
  void acerForward() {
    setMotorDirection(1, 1, 0, 0);
    ledcWrite(CH_FL, pwmValue);
    ledcWrite(CH_FR, pwmValue);
    ledcWrite(CH_BL, pwmValue);
    ledcWrite(CH_BR, pwmValue);
  }
  void acerBackward() {
    setMotorDirection(0, 0, 1, 1);
    ledcWrite(CH_FL, -pwmValue);
    ledcWrite(CH_FR, -pwmValue);
    ledcWrite(CH_BL, -pwmValue);
    ledcWrite(CH_BR, -pwmValue);
  }
  void moveLeft() {
    setMotorDirection(0, 1, 1, 0);
    ledcWrite(CH_FL, pwmValue);
    ledcWrite(CH_FR, pwmValue);
    ledcWrite(CH_BL, pwmValue);
    ledcWrite(CH_BR, pwmValue);
  }

  void moveRight() {
    setMotorDirection(1, 0, 0, 1);
    ledcWrite(CH_FL, pwmValue);
    ledcWrite(CH_FR, pwmValue);
    ledcWrite(CH_BL, pwmValue);
    ledcWrite(CH_BR, pwmValue);

  }
  void spot()
  {
    digitalWrite(MOTOR_SFL_DIR,1);
    digitalWrite(MOTOR_SFR_DIR,1);
    digitalWrite(MOTOR_SBL_DIR,1);
    digitalWrite(MOTOR_SBR_DIR,1);

    ledcWrite(CH_SFL, 115);
    ledcWrite(CH_SFR, 80);
    ledcWrite(CH_SBL, 130);
    ledcWrite(CH_SBR, 130);



  }
  
  void revspot()
  {

   digitalWrite(MOTOR_SFL_DIR,0);
    digitalWrite(MOTOR_SFR_DIR,0);
    digitalWrite(MOTOR_SBL_DIR,0);
    digitalWrite(MOTOR_SBR_DIR,0);   

    ledcWrite(CH_SFL, 115);
    ledcWrite(CH_SFR, 80);
    ledcWrite(CH_SBL, 130);
    ledcWrite(CH_SBR, 130);

  }
  void holomonicleft()
  {
    digitalWrite(MOTOR_SFL_DIR,0);
    digitalWrite(MOTOR_SFR_DIR,1);
    ledcWrite(CH_SFL, 115);
    ledcWrite(CH_SFR, 80);
    digitalWrite(MOTOR_SBL_DIR,0);
    digitalWrite(MOTOR_SBR_DIR,1);
    ledcWrite(CH_SBL, 130);
    ledcWrite(CH_SBR, 130);

  }
  void holomonicright()
  {
    digitalWrite(MOTOR_SFL_DIR,1);
    digitalWrite(MOTOR_SFR_DIR,0);
    ledcWrite(CH_SFL, 115);
    ledcWrite(CH_SFR, 80);
    digitalWrite(MOTOR_SBL_DIR,1);
    digitalWrite(MOTOR_SBR_DIR,0);
    ledcWrite(CH_SBL, 130);
    ledcWrite(CH_SBR, 130);

  }
  
  void acerleft()
  {
    digitalWrite(MOTOR_SFL_DIR,0);
    digitalWrite(MOTOR_SFR_DIR,1);

    ledcWrite(CH_SFL, 115);
    ledcWrite(CH_SFR, 80);
  }

   void acerright()
  {
    digitalWrite(MOTOR_SFL_DIR,1);
    digitalWrite(MOTOR_SFR_DIR,0);

    ledcWrite(CH_SFL, 115);
    ledcWrite(CH_SFR, 80);
  }
  void bacerleft()
  {
    digitalWrite(MOTOR_SBL_DIR,0);
    digitalWrite(MOTOR_SBR_DIR,1);

    ledcWrite(CH_SBL, 130);
    ledcWrite(CH_SBR, 130);
  }

  void bacerright()
  {
    digitalWrite(MOTOR_SBL_DIR,1);
    digitalWrite(MOTOR_SBR_DIR,0);

    ledcWrite(CH_SBL, 130);
    ledcWrite(CH_SBR, 130);
  }

  
void setup() 
{
  Serial.begin(115200);
  delay(1000);
  Serial.println("Booting...");

  pinMode(MOTOR_FL_DIR, OUTPUT);
  pinMode(MOTOR_FR_DIR, OUTPUT);
  pinMode(MOTOR_BL_DIR, OUTPUT);
  pinMode(MOTOR_BR_DIR, OUTPUT);
  pinMode(MOTOR_SFL_DIR, OUTPUT);
  pinMode(MOTOR_SFR_DIR, OUTPUT);
  pinMode(MOTOR_SBR_DIR, OUTPUT);
  pinMode(MOTOR_SBL_DIR, OUTPUT);
  setupLEDC();

  // Initialize RemoteXY with config
  RemoteXY_Init();

  Serial.println("RemoteXY Ready.");

}

void loop() 
{

  RemoteXY_Handler();

 if (strcmp(RemoteXY.edit_1, "spot") == 0)
  {  
    if(RemoteXY.button_01)
    {
      Serial.print("spot turn");
      spot();
    }
    else if (RemoteXY.button_02)
    {
      Serial.print("revspot turn");
      revspot();
    }
 
     else if (RemoteXY.button_03)
     {
      Serial.print("Moving Left");
      moveLeft();
     }
     else if (RemoteXY.button_04)
     {
      Serial.print("Moving Right");
      moveLeft();
     }
     else{
      stopMotors();
     }
  }
 
if (strcmp(RemoteXY.edit_1, "move") == 0)
{
  if(RemoteXY.button_01)
  {
    Serial.println("forward");  
    moveForward();
  }
  else if(RemoteXY.button_02)
  {
    Serial.println("backward");  
    moveBackward();
  }
  else if(RemoteXY.button_03)
  {
    pwmValue -= 5;
    if (pwmValue < 0) pwmValue = 0;
    Serial.print("PWM decreased: "); Serial.println(pwmValue);
  }
  else if(RemoteXY.button_04)
  {
    pwmValue += 5;
    if (pwmValue > 255) pwmValue = 255;
    Serial.print("PWM increase: "); Serial.println(pwmValue);
  }
  else
  stopMotors();
}

if (strcmp(RemoteXY.edit_1, "acer") == 0)
{
  if (RemoteXY.button_03 && RemoteXY.button_04)
  {
    Serial.println("stop");
    stopMotors();
  }
  else if(RemoteXY.button_01)
  { 
    Serial.println("forward");  
    pwmValue += 5;
    if (pwmValue > 255) pwmValue = 255;
    Serial.print("PWM increase: "); Serial.println(pwmValue);
    acerForward();
  }
  else if(RemoteXY.button_02)
  {  
    
    Serial.println("backward");  
    pwmValue -= 5;
    if (pwmValue < -255) pwmValue = -255;
    Serial.print("PWM decreased: "); Serial.println(pwmValue);
    if (pwmValue < 0)  acerBackward();
    else acerForward();
  }
  if(RemoteXY.button_03 && !RemoteXY.button_04)
  {
    acerleft();
    Serial.println("acerleft");
  }
  else if(RemoteXY.button_04 && !RemoteXY.button_03)
  {
    acerright();
    Serial.println("acerright");
  }
  
  else
  {
    stopsteer();
  }
}

if (strcmp(RemoteXY.edit_1, "backacer") == 0)
{
  if (RemoteXY.button_03 && RemoteXY.button_04)
  {
    Serial.println("stop");
    stopMotors();
  }
  else if(RemoteXY.button_01)
  { 
    
    Serial.println("forward");  
    pwmValue += 5;
    if (pwmValue > 255) pwmValue = 255;
    Serial.print("PWM increase: "); Serial.println(pwmValue);
    acerForward();
  }
  else if(RemoteXY.button_02)
  {  
    
    Serial.println("backward");  
    pwmValue -= 5;
    if (pwmValue < -255) pwmValue = -255;
    Serial.print("PWM decreased: "); Serial.println(pwmValue);
    if (pwmValue < 0)  acerBackward();
    else acerForward();
  }
  if(RemoteXY.button_03 && !RemoteXY.button_04)
  {
    bacerleft();
    Serial.println("bacerleft");
  }
  else if(RemoteXY.button_04 && !RemoteXY.button_03)
  {
    bacerright();
    Serial.println("bacerright");
  }
  
  else
  {
    stopsteer();
  }
}

if (strcmp(RemoteXY.edit_1, "frs") == 0)
{
  if (RemoteXY.button_01)
  {
    pwms += 5;
    if (pwms > 255) pwms = 255;
    Serial.print("PWM increase: "); Serial.println(pwms);
  }
  else if (RemoteXY.button_02)
  {
    pwms -= 5;
    if (pwms < 0) pwms = 0;
    Serial.print("PWM decrease: "); Serial.println(pwms);
  }
  else if(RemoteXY.button_03)
  {
    Serial.println("moving left");
    digitalWrite(MOTOR_SFR_DIR,0);
    ledcWrite(CH_SFR , pwms);
  }
   else if(RemoteXY.button_04)
  {
    Serial.println("moving right");
    digitalWrite(MOTOR_SFR_DIR,1);
    ledcWrite(CH_SFR , pwms);
  }
  else{
    stopMotors();
  } 
}

if (strcmp(RemoteXY.edit_1, "fls") == 0)
{
  if (RemoteXY.button_01)
  {
    pwms += 5;
    if (pwms > 255) pwms = 255;
    Serial.print("PWM increase: "); Serial.println(pwms);
  }
  else if (RemoteXY.button_02)
  {
    pwms -= 5;
    if (pwms < 0) pwms = 0;
    Serial.print("PWM decrease: "); Serial.println(pwms);
  }
  else if(RemoteXY.button_03)
  {
    Serial.println("moving left");
    digitalWrite(MOTOR_SFL_DIR,0);
    ledcWrite(CH_SFL , pwms);
  }
   else if(RemoteXY.button_04)
  { 
    Serial.println("moving right");
    digitalWrite(MOTOR_SFL_DIR,1);
    ledcWrite(CH_SFL , pwms);
  }
  else{
    stopMotors();
  }
}
  if (strcmp(RemoteXY.edit_1, "brs") == 0)
{
  if (RemoteXY.button_01)
  {
    pwms += 5;
    if (pwms > 255) pwms = 255;
    Serial.print("PWM increase: "); Serial.println(pwms);
  }
  else if (RemoteXY.button_02)
  {
    pwms -= 5;
    if (pwms < 0) pwms = 0;
    Serial.print("PWM decrease: "); Serial.println(pwms);
  }
  else if(RemoteXY.button_03)
  {
    Serial.println("moving left");
    digitalWrite(MOTOR_SBR_DIR,0);
    ledcWrite(CH_SBR , pwms);
  }
   else if(RemoteXY.button_04)
  { 
    Serial.println("moving right");
    digitalWrite(MOTOR_SBR_DIR,1);
    ledcWrite(CH_SBR , pwms);
  }
  else{
    stopMotors();
  }
}
if (strcmp(RemoteXY.edit_1, "bls") == 0)
{
  if (RemoteXY.button_01)
  {
    pwms += 5;
    if (pwms > 255) pwms = 255;
    Serial.print("PWM increase: "); Serial.println(pwms);
  }
  else if (RemoteXY.button_02)
  {
    pwms -= 5;
    if (pwms < 0) pwms = 0;
    Serial.print("PWM decrease: "); Serial.println(pwms);
  }
  else if(RemoteXY.button_03)
  {
    Serial.println("moving left");
    digitalWrite(MOTOR_SBL_DIR,0);
    ledcWrite(CH_SBL , pwms);
  }
   else if(RemoteXY.button_04)
  {
    Serial.println("moving right");
    digitalWrite(MOTOR_SBL_DIR,1);
    ledcWrite(CH_SBL , pwms);
  }
  else{
    stopMotors();
  }
}
if (strcmp(RemoteXY.edit_1, "holomonic") == 0)
{
 if (RemoteXY.button_03 && RemoteXY.button_04)
  {
    Serial.println("stop");
    stopMotors();
  }
  else if(RemoteXY.button_01)
  { 
    Serial.println("forward");  
    pwmValue += 5;
    if (pwmValue > 255) pwmValue = 255;
    Serial.print("PWM increase: "); Serial.println(pwmValue);
    acerForward();
  }
  else if(RemoteXY.button_02)
  {  
    
    Serial.println("backward");  
    pwmValue -= 5;
    if (pwmValue < -255) pwmValue = -255;
    Serial.print("PWM decreased: "); Serial.println(pwmValue);
    if (pwmValue < 0)  acerBackward();
    else acerForward();
  }
  if(RemoteXY.button_03 && !RemoteXY.button_04)
  {
    holomonicleft();
    Serial.println("holomonicleft");
  }
  else if(RemoteXY.button_04 && !RemoteXY.button_03)
  {
    holomonicright();
    Serial.println("holomonicright");
  }
  else
  {
    stopsteer();
  } 
}
  delay(150);
}



