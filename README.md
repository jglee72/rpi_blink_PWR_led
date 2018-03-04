# rpi_blink_PWR_led
Blink "PWR ON" LED instead of using IO pins to external LED

### What is this repository for? ###

This is a small driver program to cycle the POWER ON LED of a raspberry pi off and on.  Program started as a first program to blink an external LED using /mattiasblok/BCM2835 (originall author Mike McCauley) io library. It was expanded to be tested without the need for external hardware.

### How do I get set up? ###
The following Instructions were modelled after the following websites

* http://www.raspberry-projects.com/pi/programming-in-c/io-pins/bcm2835-by-mike-mccauley
* http://www.airspayce.com/mikem/bcm2835/

In /home/pi Clone or download and unzip this git 

    git clone https://github.com/jglee72/rpi_blink_PWR_led.git 

Change to bcm2835 directory

    cd /home/pi/bcm2835
    
Run the configure exe

    ./configure

Execute the makefile

    make

Then

    sudo make check

Then

     sudo make install 

The library is now ready to use. 

### How do you Make and Run the blink.exe

change to examples directory

    cd /examples/blink
    
Make blink executable

    gcc -o blink blink.c -lbcm2835
    
Then run the file

    ./blink
    
The screen will output a string of 1's and 0's as a visual indicator that the function is running.  Your Power On LED on the RPI should
now be blinking at approx 1Hz.  Use 'q' to exit.  Ctrl-c also kills the program.

### Who do I talk to? ###

- Jimmy Johnny
- johnny@johnny-inc.com
