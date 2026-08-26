# **Cmote**

A USB-C IR transmitter for controlling devices like ACs, TVs for when you're too lazy to find the remote and your smartphone does not have a built-in IR blaster.

Time Spent: `4h`

---
---
### `(#01)` 26/08/26 (22:39)
## Beginning: 1h

This is the start of Cmote!<br>
I researched about the components that will be required to make this and added them to my schematics in KiCAD.<br>
The PCB files are available in the [PCB directory](./PCB/).

I settled upon using the ATtiny1616 microcontroller as it is small, capable enough, has hardware timers and consumes very less power while working directly with 5V logic level.

<img src="./assets/journalimg_1.png" width="256">

<br>

For transmitting the IR signals, I settled upon using this `Infrared LED Emitter` I found on JLC which will be soldered to the PCB directly and is a small 0402 package: [link](https://jlcpcb.com/partdetail/EverlightElec-IR16_213C_L510TR8/C2943465). It supports 5V at 940nm wavelength which is extremely common in IR devices.

<img src="./assets/journalimg_3.png" width="128">

I will be using this with a Si2302 mosfet to properly drive it as driving it directly from the MCU is never a good idea.
<br>

For receiving the IR signals I settled upon using `TSOP 1738` as it consists of a PIN diode and a preamplifier which are embedded into a single package ([source](https://robocraze.com/products/tsop-1738?_pos=6&_sid=ae6cf2b3a&_ss=r#:~:text=The%20TSOP1738%20IR%20sensor%20module%20consists%20of%20a%20PIN%20diode%20and%20a%20preamplifier%20which%20are%20embedded%20into%20a%20single%20package.)).

<img src="./assets/journalimg_2.png" width="256">


<br>

Other than that, I setup this GitHub repository with the `README.md` and `JOURNAL.md` files with a clean directory structure for easier management of this project.

---
---
### `(#02)` 27/08/26 (02:03)
## Schematics, BOM: 3h

I connected all the components together by looking at their individual datahsheets and keeping in mind the voltage levels and tolerances along with stuff like bypass, decoupling capacitors that were mentioned in the datasheets.

For the Attiny1616, I added a CH340N to convert serial to USB signals which will allow us to communicate with our device over a USB port.

I haven't added the USB plug yet, that is for the next journal.

I added 2.54mm header pads for the following:
- Power (+5V, GND)
- UPDI Programming (VDD, GND, UPDI)
- 2x 8pin unused MCU Pins (7 pins, 1 GND)

<img src="./assets/journalimg_4.png" width="512">