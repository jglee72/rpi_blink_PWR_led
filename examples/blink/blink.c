// blink.c
//
// Example program for bcm2835 library
// Blinks a pin on an off every 0.5 secs
//
// After installing bcm2835, you can build this 
// with something like:
// gcc -o blink blink.c -l bcm2835
// sudo ./blink
//
// Or you can test it before installing with:
// gcc -o blink -I ../../src ../../src/bcm2835.c blink.c
// sudo ./blink
//
// Author: Mike McCauley
// Copyright (C) 2011 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $
//#include <stdlib.h>

#include <bcm2835.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <ncurses.h>
#include <unistd.h>
#include "test.h"
//#include "gtkwidget.h" //Not needed so far
//#include <gtk/gtk.h> //Un comment to use with GUI shit

// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
#define PIN RPI_GPIO_P1_11


/*
int kbhit(void);

int kbhit()
{
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds); //STDIN_FILENO is 0
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}
*/

int main(int argc, char **argv)
{
    // If you call this, it will not actually access the GPIO
    // Use for testing
    bcm2835_set_debug(1);
    
    printf("\n Starting Blinking of POWER LED\n");

/*
    GtkWidget *image_button_down;
    GtkWidget *event_box_button_down;
	
	//----- EVENT BOX BASED IMAGE BUTTON -----
	image_button_down = gtk_image_new_from_file("/home/pi/projects/ui/button_down_a.png");
	event_box_button_down = gtk_event_box_new();
	gtk_container_add(GTK_CONTAINER(event_box_button_down), image_button_down);
	//gtk_widget_set_size_request(event_box_button_down, 68, 68);			//Will be image size by default, but you can force the widget to be either larger or smaller than it normally would be using this
	gtk_fixed_put(GTK_FIXED(fixed), event_box_button_down, 460, 270);		//x, y from top left	
	
	//----- SET EVENTS TO BE CALLED ----- 
	g_signal_connect(G_OBJECT(event_box_button_down), "button_press_event", G_CALLBACK(event_button_press_event), NULL);		//("button_press_event" must not be changed)
	g_signal_connect(G_OBJECT(event_box_button_down), "button_release_event", G_CALLBACK(event_button_release_event), NULL);	//Include if you want the release event ("button_release_event" must not be changed)	
*/	

    if (!bcm2835_init())
 	    return 1;
    struct termios info;
    tcgetattr(0, &info);          /* get current terminal attirbutes; 0 is the file descriptor for stdin */
    info.c_lflag &= ~ICANON;      /* disable canonical mode */
    info.c_cc[VMIN] = 1;          /* wait until at least one keystroke available */
    info.c_cc[VTIME] = 0;         /* no timeout */
    tcsetattr(0, TCSANOW, &info); /* set immediately */
    char c;
    int i=0;

  // Set the PWR LED to GPIO mode
    system ("echo gpio | sudo tee /sys/class/leds/led1/trigger"); 

  // Set the pin to be an output
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

    // Blink
    while (!i)
    {
        i=kbhit();
	    if (i != 0)
	    {
		    c = getchar();
		    if (c== 'q')
		    i=1;
		    else 
		    i=0;
	    }
	    // Turn OP ON
	    bcm2835_gpio_write(PIN, HIGH);
            // Set PWR LED to ON
        system ("echo 1 | sudo tee /sys/class/leds/led1/brightness");
	    
	    // wait a bit
	    bcm2835_delay(500);
	    
	    // turn OP OFF
	    bcm2835_gpio_write(PIN, LOW);
	    // Set the PWR LED to OFF
        system ("echo 0 | sudo tee /sys/class/leds/led1/brightness");
    
	    // wait a bit
	    bcm2835_delay(500);
    } 

    printf("\n you hit %c. \n",c);

    bcm2835_close();
    
// Set the PWR LED to Low Power mode
    system ("echo input | sudo tee /sys/class/leds/led1/trigger");
    info.c_lflag |= ICANON;      /* re-enable canonical mode */

    return 0;
}

