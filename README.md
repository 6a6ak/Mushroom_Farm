# Mushroom_Farm

Automatic environment controller for a small mushroom farm (Arduino Uno).

## Overview

This project uses an Arduino Uno to monitor and control environmental conditions for mushroom cultivation. The controller reads temperature and humidity from a DHT sensor, drives multiple relay channels for cooling/heating, fans and watering, and includes a SIM800-based GPRS/GSM interface to call or send SMS alerts when thresholds are crossed.

The main sketch is `Mashsalon_97030204.ino` in this repository.

## Features

- Automatic temperature control (heater / cooler relays).
- Humidity control (water cooler / misting relay).
- Multiple relay outputs for fans, CO₂ control and extras.
- GSM/SIM800 integration to make calls or send SMS on alerts.
- Simple, easy-to-read Arduino sketch ready to adapt thresholds and phone numbers.

## Hardware (suggested)

- Arduino Uno (or compatible)
- DHT sensor (DHT11 or DHT22)
- SIM800 / SIM900 module (GSM/GPRS)
- 8-channel relay module (or equivalent relays for your actuators)
- External power supply for relays and GSM module (SIM modules require stable 2A bursts)
- Jumper wires, breadboard or PCB, and mushroom farm actuators (fans, pump, heater, etc.)

## Wiring (summary)

- DHT data pin -> Arduino digital pin `2` (as used in the sketch).
- Relay outputs: `RELAY1`..`RELAY8` map to digital pins `4`..`13` in the sketch.
- SIM800 module: wire TX/RX to the UART/SoftwareSerial pins required by your chosen `GPRS`/SIM library and provide a stable power source. Consult your GSM module and `gprs` library documentation for correct wiring and voltage requirements.

Check the sketch `Mashsalon_97030204.ino` for the pin assignments and adapt wiring as needed.

## Software / Libraries

Install the following libraries in the Arduino IDE (or PlatformIO) before compiling:

- `DHT` (e.g., Adafruit or equivalent compatible library)
- `GPRS` or the appropriate SIM800 library used by the sketch
- `SoftwareSerial` (bundled with Arduino)

If you use PlatformIO, add the corresponding library entries to `platformio.ini`.

## Configuration

- Open `Mashsalon_97030204.ino` and update any placeholder phone numbers (`"Phone Number"`) to your desired alert recipient(s).
- Review and adjust temperature/humidity thresholds in the sketch (examples: `Temp>24`, `Humi<55`).
- Ensure the GSM module is powered and has a valid SIM card with network access.

## Usage

1. Connect hardware according to wiring notes and provide stable power to the GSM module and relays.
2. Install the necessary libraries in your Arduino environment.
3. Open `Mashsalon_97030204.ino` in the Arduino IDE, set the board to `Arduino Uno`, select the correct COM port, then compile and upload.
4. Monitor the Serial console at `9600` baud for runtime messages and debug output.

## Safety & Notes

- Test relay outputs without actuators first to verify correct logic and prevent accidental heating/cooling.
- Provide proper power supply and level-shifting for the SIM800 module. GSM modules can draw high current peaks; use a suitable regulator and decoupling.
- This sketch is a starting point — customize thresholds, safety interlocks, and alarms to suit your farm.

## License

This project is licensed under the MIT License — see the `LICENSE` file for details: [LICENSE](LICENSE).
