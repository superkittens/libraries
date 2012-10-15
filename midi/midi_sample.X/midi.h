/*
 * This is a very basic MIDI library.  This library can be used with any
 * MIDI IC without too much problems.  I have used the Sparkfun Music Instrument
 * Shield using the VS1053B IC with this library and found no problems...yet.
 * The uC used was a PIC18F4550 with a 4 MHz Crystal
 *
 * This library is in Public Domain ( BEERWARE License ).  If you like it,
 * you can buy me a beer if we ever meet.  I also accept cookies.
 *
 * Portions of this library are based off of the example code written by
 * Nathan Seidle for the Sparkfun Music Instrument Shield.
 *
 * Descriptions of Functions:
 *
 * - midi_init() sets up the EUSART peripheral on the PIC for MIDI Transmission
 * - setBank() sets up the instrument bank for a given channel
 * - setVol() sets up the volume of a particular channel
 * - setInstrument() sets up the instrument for a given channel
 * - playNote() plays a specified note on a specified channel
 * - stopNote() does the opposite of playNote()
 * - txMIDI() is mainly used internally in the library but you can send other
 *            MIDI commands that are not in this library using this function
 * - setTempo() sets the tempo if you are hard coding a musical phrase
 * - nr() is the duration of a note or rest.  You can have the following durations:
 *              > whole ('w')
 *              > half ('h')
 *              > quarter ('q')
 *              > eighth ('e')
 *              > sixteenth ('s')
 *
 *
 * Written by Allen Lee - alee@meoworkshop.org
 * rev. O 8-Sept/2012
 * rev. 1 1-Oct/2012
 *
 * rev.1    Multichannel support
 *          Note & Rest Duration Functions
 *          Added txMIDI function to handle all MIDI Transmissions
 */

#ifndef MIDI_CMD_H
#define	MIDI_CMD_H

    void midi_init(void);
    void setBank(char channel, char bank);
    void setVol(char channel, char vol);
    void setInstrument(char channel, char instr);
    void playNote(char channel, char note);
    void stopNote(char channel, char note);
    void txMIDI(char cmd, char data1, char data2);
    void setTempo(float tempo);
    void nr(char type);

#endif	/* MIDI_CMD_H */