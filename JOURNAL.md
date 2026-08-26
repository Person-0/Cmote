# **Cmote**

A USB-C IR transmitter for controlling devices like ACs, TVs for when you're too lazy to find the remote and your smartphone does not have a built-in IR blaster.

Time Spent: `1h`

---
### `(#01)` 26/08/26 (22:39)
## Beginning: 1h

This is the start of Cmote!<br>
I researched about the components that will be required to make this and added them to my schematics in KiCAD.<br>
The PCB files are available in the [PCB directory](./PCB/).

I settled upon using the ATtiny1616 microcontroller as it is small, capable enough, has hardware timers and consumes very less power while working directly with 5V logic level.

<img src="./assets/journalimg_1.png" width="256">

<br>

For transmitting the IR signals, I settled upon using `5mm IR Transmitter` LEDs (rated for 5V),

<img src="./assets/journalimg_3.png" width="64">

<br>

and for receiving the IR signals I settled upon using `TSOP 1738` as it consists of a PIN diode and a preamplifier which are embedded into a single package ([source](https://robocraze.com/products/tsop-1738?_pos=6&_sid=ae6cf2b3a&_ss=r#:~:text=The%20TSOP1738%20IR%20sensor%20module%20consists%20of%20a%20PIN%20diode%20and%20a%20preamplifier%20which%20are%20embedded%20into%20a%20single%20package.)).

<img src="./assets/journalimg_2.png" width="256">


<br>

Other than that, I setup this GitHub repository with the `README.md` and `JOURNAL.md` files with a clean directory structure for easier management of this project.

---