Initialize the 8-bit computer memory with a program to be executed automatically on powering.

![](/assets/execution-on-powering.gif)

## Motivation

The goal of the project is to have an option of hanging the 8-bit computer on a wall, connect it to a power supply and
see how a program is executed automatically without manually programming the memory.

<img src="/assets/computer-on-a-wall.png" width="400" height="340">

*The picture is lent from this [Reddit thread](https://www.reddit.com/r/beneater/comments/k7yjz6/8bit_build_done_and_hung/).*

## Setup

The program was tested with the following systems:

* macOS Big Sur:
  * Arduino Nano:
    * Board — Arduino Nano.
    * Processor — ATmega328P (Old Bootloader).
    * Programmer — Arduino as ISP.

## Instructions

### Software

Clone the repository with the following command:

```bash
$ git clone git@github.com:dmytrostriletskyi/8-bit-computer-memory-init.git
$ cd 8-bit-computer-memory-init
```

By default, the [Fibonacci number](https://en.wikipedia.org/wiki/Fibonacci_number) program is defined in the 
[code file on 28th line](https://github.com/dmytrostriletskyi/8-bit-computer-memory-init/blob/main/program.ino#L28)
in the exact same way it's [done by Ben Eater in his video](https://youtu.be/a73ZXDJtU48?t=263). If you want to change
it, open the code file and change the program, otherwise skip this step:

```bash
$ vim +28 program.ino
```

Copy the program to the `Arduino` sketchbook folder with the following command:

```bash
$ mkdir ~/Documents/Arduino/program && cp program.ino ~/Documents/Arduino/program
```

Then connect `Arduino` to a computer, open and upload the sketch.

### Schema

The wiring schema is illustrated below according to the following matching:

* A1 — the chip right from run or programming mode switch.
* A2 — the chip right from writting to memory button.
* A3 — the chip right from resetting computer button.
* D2-D9 — the chips right from the DIP switches for memory values.
* D10-D13 — the chip right from the DIP switches for memory address.

![](/assets/schema.png)
