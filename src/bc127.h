#ifndef BC127_h
#define BC127_h

#include "smallserial.h"
#include <util/setbaud.h>

class BC127 {
public:
	// Let's make an enum for different types of connections. The BC127 module can
    //  support a lot of different types of connections, but we'll only actually use
    //  a few of them.
    enum connType {SPP, BLE, A2DP, HFP, AVRCP, PBAP, ANY};

    // Now, make a data type for function results.
    enum opResult {REMOTE_ERROR = -5, CONNECT_ERROR, INVALID_PARAM,
                 TIMEOUT_ERROR, MODULE_ERROR, DEFAULT_ERR, SUCCESS};

    // Here's an enum for the various audio commands we can use on the module.
    enum audioCmds {PLAY, PAUSE, FORWARD, BACK, UP, DOWN, STOP};
    
    // Here's an enum for the various valid baud rates. Rather than doing it
    //  with strings, we'll use the enum, to discourage people from experimenting
    //  with out-of-bounds speeds.
    enum baudRates {s9600bps, s19200bps, s38400bps, s57600bps, s115200bps};

    opResult setBaudRate(baudRates newSpeed);
}