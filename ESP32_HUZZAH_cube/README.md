# Connecting to ESP32 HUZZAH Feather
Inspired by (this aricle)[https://medium.com/@18218004/devlog-6-bluetooth-and-esp32-ba076a8e207d]

After connecting / pairing to device on Ubuntu 22.04, passkey is presented and manually accepted, but device disconnects shortly after; however, remains paired.

*Work around to connect*
```
# 40:91:51:1D:FE:6E is mac address of ESP32, which can be found with "bluetoothctl scan on"
sudo rfcomm connect /dev/rfcomm0 40:91:51:1D:FE:6E 1
sudo rfcomm connect /dev/rfcomm0 0C:DC:7E:CA:DD:36 1

# Send serial command
sudo su -c "echo 0 > /dev/rfcomm0"
```

*Work around to display serial outputs in separate terminal*
```
sudo screen /dev/rfcomm0
```

# Programming the ESP32 HUZZAH Feather
- Use v2.0.17 of esp32 by Espressif as suggested in [this Issue](https://github.com/espressif/arduino-esp32/issues/10309) to avoid `Compilation error: 'ledcSetup' was not declared in this scope ESP32 HUZZAH`.
