# Garden control
> Based on example MQTT app from esp-idf framework

## Prerequisite
Assumes you already have an MQTT broker service running or are going to use a public service like test.mosquitto.org to test out the pub/sub of the messages (strongly recommend running local server to keep control/messages in the LAN: https://mosquitto.org/)


## Setup
1. Install esp-idf (use espressif vs-code plugin or manually install)
1. Run the `install.sh` and `. export.sh` scripts or corresponding batch files to setup the env vars for idf.py build system
1. Run `idf.py menuconfig` adjust the `Camera with IR Sensor - Firmware Configuration` with the appropriate MQTT host server URL and adjust the `Example Connection Configuration` with the appropriate WiFi username/password.
1. Hit S to save the `sdkconfig` file and Q to quit
1. Run `idf.py build flash monitor` to test the compilation and flash any esp32 devices found on the USB ports

## Usage
The firmware is setup to monitor and IR sensor on an ESP32 camera board and broadcast an MQTT message anytime the motion detector state changes (from 0 no motion to 1, motion detected and back to 0 no motion detected)

The firmware will connect to the wifi network then publishes a message `/camera/online/CAM_NAME` where CAM_NAME is set in the firmware using `idf menuconfig` to adjust the value for the `Camera Name` within the `Camera with IR Sensor - Firmware Configuration` section (similarly can edit the MQTT broker URL as needed in the config there).  The camera firmware also has a web server at the default port 80 (find the camera IP by looking in the monitor/serial output or router device list etc.) and hosts a JPEG streaming service on port :81 at http://cam_IP_or_Name:81/stream

To test the firmware you can use the mosquitto_pub and mosquitto_sub apps which can be installed with: `sudo apt install mosquitto-clients`

Terminal 1 (Listen for all messages):

```bash
mosquitto_sub -t "#" -h 192.168.0.11
```

Where 192.168.0.11 is the MQTT host IP

---

# Base Example README

## MQTT demo application that runs on linux

### Overview

This is a simple example demonstrating connecting to an MQTT broker, subscribing and publishing some data.
This example uses IDF build system and could be configured to be build and executed:
* for any ESP32 family chip
* for linux target

### How to use example

#### Hardware Required

To run this example, you need any ESP32 development board or just PC/virtual machine/container running linux operating system.

#### Host build modes

Linux build is supported in these two modes:
* `WITH_LWIP=0`: Without lwIP component. The project uses linux BSD socket interface to interact with TCP/IP stack. There's no connection phase, we use the host network as users. This mode is often referred to as user-side networking.
* `WITH_LWIP=1`: Including lwIP component, which is added to the list of required components and compiled on host. In this mode, we have to map the host network (linux TCP/IP stack) to the target network (lwip). We use IDF's [`tapif_io`](https://github.com/espressif/esp-idf/tree/master/examples/common_components/protocol_examples_tapif_io) component to create a network interface, which will be used to pass packets to and from the simulated target. Please refer to the [README](https://github.com/espressif/esp-idf/tree/master/examples/common_components/protocol_examples_tapif_io#readme) for more details about the host side networking.

#### Building on linux

1) Configure linux target
```bash
idf.py --preview set-target linux
```

2) Build the project with preferred components (with or without lwip)
```bash
idf.py -DWITH_LWIP=0 build  # Building without lwip (user networking)
idf.py -DWITH_LWIP=1 build  # Building with lwip (TAP networking)
```

3) Run the project

It is possible to run the project elf file directly, or using `idf.py` monitor target (no need to flash):
```bash
idf.py monitor
```
idf.py -DWITH_LWIP=0 build  # Building without lwip (user networking)
