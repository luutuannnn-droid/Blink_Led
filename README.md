# ESP32 LED Control with OneButton Library (Double Click Edition)

Dự án điều khiển LED ngoại vi sử dụng vi điều khiển ESP32 và thư viện OneButton trên nền tảng PlatformIO.

Tính năng chính:
- Single Click (Nhấn 1 lần): Bật hoặc Tắt LED (Đảo trạng thái).
- Double Click (Nhấn 2 lần liên tiếp) Chuyển LED sang chế độ nhấp nháy liên tục (chu kỳ 200ms).
- Khử rung phím bấm (Debounce) tự động nhờ thư viện `OneButton`.
- Điều khiển LED bất đồng bộ (Non-blocking) sử dụng hàm `millis()`.

Sơ đồ kết nối phần cứng
LED Ngoại vi (Active LOW):
 Anode (+) -> Điện trở 1k -> Nguồn 3.3V
 Cathode (-) -> Chân GPIO 5(ESP32)
Nút bấm (Active LOW):
 Chân 1 -> Chân GPIO 22(ESP32)
 Chân 2 -> Chân GND

Cấu trúc dự án
```text
.
├── include/
│   └── LED.h           # Lớp điều khiển LED
├── src/
│   └── main.cpp        # Mã nguồn chính
├── platformio.ini      # Cấu hình dự án & cài đặt thư viện
└── README.md           # Tài liệu hướng dẫn