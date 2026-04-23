#include <Keyboard.h>

// Назначаем пины для 8 кнопок
const int buttonPins[] = {3, 2, 4, 5, 21, 20, 18, 19};
const int numButtons = 8;

// Пин встроенного красного светодиода на Pro Micro
// RX LED находится на пине 17 ()
const int ledPin = 17;  // Встроенный красный светодиод (RX)

// Состояния кнопок
bool lastButtonState[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
// Состояние светодиода для кнопки 3
bool ledState = false;

void setup() {

  // Инициализируем Serial для отладки
  Serial.begin(9600);
  // Инициализируем клавиатуру
  Keyboard.begin();
  
  // Настраиваем пины кнопок
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  
  // Настраиваем пин светодиода
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);  // Начинаем с выключенным светодиодом
  
  // Небольшая задержка для стабилизации
  delay(1000);
}

void loop() {
  for (int i = 0; i < numButtons; i++) {
    bool currentState = digitalRead(buttonPins[i]);
    
    // Если кнопка нажата (состояние LOW при INPUT_PULLUP)
    if (currentState == LOW && lastButtonState[i] == HIGH) {
      delay(50); // Защита от дребезга
      
      // Выполняем действие в зависимости от номера кнопки
      switch(i) {
        case 0:
          // Кнопка 1 (пин 3): Ctrl+Z
          if (ledState == false) {
          Serial.print("Режим - Обычный, Кнопка - 1, Светодиод - ");
          Serial.println(ledState);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('z');
          delay(100);
          Keyboard.releaseAll();
          break;
          } else {
            Serial.print("Режим - Расширенный, Кнопка - 1, Светодиод - ");
            Serial.println(ledState);
            Keyboard.print("Hello from my 8-button macro pad!");
            break;
          }
          
        case 1:
          // Кнопка 2 (пин 2): Ctrl+X
          if (ledState == false) {
          Serial.print("Режим - Обычный, Кнопка - 2, Светодиод - ");
          Serial.println(ledState);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('x');
          delay(100);
          Keyboard.releaseAll();
          break;
          } else {
            Serial.print("Режим - Расширенный, Кнопка - 2, Светодиод - ");
            Serial.println(ledState);
            break;
          }
          
        case 2:
          // Кнопка 3 (пин 4): Ctrl+C и Kando
          if (ledState == false) {
          Serial.print("Режим - Обычный, Кнопка - 3, Светодиод - ");
          Serial.println(ledState);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('c');
          delay(100);
          Keyboard.releaseAll();
          break;
          } else {
          Serial.print("Режим - Расширенный, Кнопка - 3, Светодиод - ");
          Serial.println(ledState);
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.press('z');
          delay(100);
          Keyboard.releaseAll();
          break;
          }
          
        case 3:
          // Кнопка 4 (пин 5): Ctrl+V
          if (ledState == false) {
          Serial.print("Режим - Обычный, Кнопка - 4, Светодиод - ");
          Serial.println(ledState);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('v');
          delay(100);
          Keyboard.releaseAll();
          break;
          } else {
            Serial.print("Режим - Расширенный, Кнопка - 4, Светодиод - ");
            Serial.println(ledState);
            break;
          }
          
        case 4:
          // Кнопка 5 (пин 21): Ctrl+A
          if (ledState == false) {
          Serial.print("Режим - Обычный, Кнопка - 5, Светодиод - ");
          Serial.println(ledState);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('a');
          delay(100);
          Keyboard.releaseAll();
          break;
          } else {
            Serial.print("Режим - Расширенный, Кнопка - 5, Светодиод - ");
            Serial.println(ledState);
            break;
          }
          
        case 5:
          // Кнопка 6 (пин 20): CAPS LOCK (доп действия) типа
          Serial.print("Кнопка - 6 (ПЕРЕКЛЮЧАТЕЛЬ), Светодиод был - ");
          Serial.println(ledState);
          // Переключаем состояние светодиода (тумблер)
          ledState = !ledState;
          Serial.print("Переключен в - ");
          Serial.println(ledState);
          if (ledState == true) {
            digitalWrite(ledPin, LOW);
          } else {
            digitalWrite(ledPin, HIGH);
          }
          break;
          
        case 6:
          // Кнопка 7 (пин 18): Открыть Kando (Alt+z)
          if (ledState == false) {
          Serial.print("Режим - Обычный, Кнопка - 7, Светодиод - ");
          Serial.println(ledState);
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.press('z');
          delay(100);
          Keyboard.releaseAll();
          break;
          } else {
            Serial.print("Режим - Расширенный, Кнопка - 7, Светодиод - ");
            Serial.println(ledState);
            break;
          }
          
        case 7:
          // Кнопка 8 (пин 19): Открыть пароли касперский (Ctrl+Alt+q)
          if (ledState == false) {
          Serial.print("Режим - Обычный, Кнопка - 8, Светодиод - ");
          Serial.println(ledState);
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('q');
          delay(100);
          Keyboard.releaseAll();
          break;
          } else {
            Serial.print("Режим - Расширенный, Кнопка - 8, Светодиод - ");
            Serial.println(ledState);
            break;
          }
      }
    }
    
    lastButtonState[i] = currentState;
  }
  
  delay(10); // Небольшая задержка для стабильности
}