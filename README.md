# rpi_blink_PWR_led
Blink "PWR ON" LED instead of using IO pins to external LED

### What is this repository for? ###

This is a small driver program to cycle the POWER ON LED of a raspberry pi off and on.  Program started as a first program to blink an external LED using /mattiasblok/BCM2835 (originall author Mike McCauley) io library. It was expanded to be tested without the need for external hardware.

### How do I get set up? ###
The following Instructions were modelled after the following website http://www.raspberry-projects.com/pi/programming-in-c/io-pins/bcm2835-by-mike-mccauley: 

In /home/pi Clone or download and unzip git 

    git clone https://github.com/matthiasbock/bcm2835.git

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

### Who do I talk to? ###

- Jimmy Johnny
- johnny@johnny-inc.com
