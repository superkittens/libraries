/*
 * This is some sample code using the MIDI Library and the Sparkfun Music
 * Instrument Shield (which has the VLSI VS1053b chip).
 * NOTE:  USE THE C18 TOOLCHAIN WHEN BUILDING THIS PROJECT!
 *
 * This code has the Beerware License.  If you like and use it, you can buy me
 * a beer if we ever meet.
 *
 * If you have any questions/comments give me a shout at alee@meoworkshop.org
 *
 * This code cycles through 10 + 10 notes as defined in the "seq_1" & "seq_2"
 * arrays repeatedly with a quarter note spacing in between each note.
 * Tempo is set to 120 bpm.
 * There are two instruments playing.  A piano cycles through each note, while
 * a flute plays two notes while the piano cycles.  The flute changes notes
 * after 10 notes have been played by the piano.
 *
 * The piano is on channel 0 and the flute on channel 1
 *
 * You can change parameters by playing around with the variables after the
 * configuration pragma.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <p18f4550.h>
#include <delays.h>
#include "midi.h"



/*Configuration bits are the following:
 * Use External Crystal (4 MHz)
 * Watchdog Timer OFF
 * Oscillator Switchover ON
 * Failsafe Clock Monitor OFF
 *
 * Feel free to change these around to your specific board
 */
#pragma config FOSC=XT_XT, WDT=OFF, IESO=ON, FCMEN=ON, LVP=ON

//  Set up some parameters here
//  We will be using two channels.  ch.0 will be piano while ch.1 is flute
char bank = 0x00;
char vol = 80;
char instr_0 = 0;
char instr_1 = 73;
char note_length = 's';
char tempo = 120;

//  Define two different musical phrases.  The numbers are note numbers
int seq_1[10] = {55,58,60,62,65,67,65,62,60,58};
int seq_2[10] = {48,51,53,55,58,60,58,55,53,51};

void main(void) {

    //  MIDI Initialization functions
    midi_init();
    setTempo(tempo);
    setBank(0,bank);
    setBank(1,bank);
    setVol(0,vol);
    setVol(1,vol);
    setInstrument(0,instr_0);
    setInstrument(1,instr_1);

    while(1)
    {
        //  Variables for loops
        int i;
        int j;

        playNote(1,60);                  //  Start the flute's first note

        for(i = 0; i < 10; i++)          //  Here we start cycling though notes
        {
            playNote(0,seq_2[i]);        //  Play a note!
            nr(note_length);             //  Let the note play for a certain length
            stopNote(0,seq_2[i]);        //  Stop the note!

        }

        stopNote(1,60);                  //  Stop the flute playing

        //  As you may have probably noticed, each "playNote" is paired with
        //  a "stopNote".  Some instruments (like a piano) stop automatically
        //  while others like the flute do not so you have to explicitly state
        //  the "stopNote" function.


        //  The next half is pretty much the same as above, only the notes are
        //  different.
        playNote(1,67);

        for(j = 0; j < 10; j++)     
        {                           
            playNote(0,seq_1[j]);
            nr(note_length);
            stopNote(0,seq_1[j]);

        }

        stopNote(1,67);

    }

}

