#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

// Định nghĩa chân và mức tích cực phần cứng
#define LED_PIN 5       // GPIO 5 (D5) điều khiển LED ngoài
#define LED_ACT LOW     // Mạch Active LOW (Mức LOW thì LED sáng)

#define BTN_PIN 22      // GPIO 22 (D22) nối với Nút bấm
#define BTN_ACT LOW     // Nút bấm Active LOW (Nhấn nút nối xuống GND)

LED led(LED_PIN, LED_ACT);

void btnPush();
void btnDoubleClick();

// Khởi tạo nút bấm OneButton
OneButton button(BTN_PIN, !BTN_ACT);

void setup()
{
    led.off();
    // Đăng ký sự kiện nút bấm
    button.attachClick(btnPush);                 // Single click -> Bật/Tắt LED
    button.attachDoubleClick(btnDoubleClick);   // Double click -> Nháy LED (200ms)
}

void loop()
{
    led.loop();
    button.tick();
}

// Xử lý khi nhấn đơn (Single Click)
void btnPush()
{
    led.flip();
}

// Xử lý khi nhấn kép (Double Click)
void btnDoubleClick()
{
    led.blink(200);
}