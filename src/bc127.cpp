

// We need a baud rate setting handler. Let's make one! This is kinda tricksy,
//  though, b/c the baud rate change takes effect immediately, so the return
//  string from the baud rate change will be garbled. This will result in a
//  TIMEOUT_ERROR from that function (after all, the EOL won't be recognized,
//  since it'll be at the wrong baud rate). So, if we get a TIMEOUT_ERROR from
//  the module, we'll re-do the command at the new baud rate. If *that* fails.
//  we can assume something is radically wrong. 
BC127::opResult BC127::setBaudRate(baudRates newSpeed)
{
  // The BC127 wants a string, but the .begin() functions want an integer. We
  //  need a variable to hold both types.
  int intSpeed;
  String stringSpeed;
  
  // Convert our enum values into strings the module can use.
  switch(newSpeed)
  {
    case BC127::s9600bps:
      stringSpeed = "9600";
      break;
    case BC127::s19200bps:
      stringSpeed = "19200";
      break;
    case BC127::s38400bps:
      stringSpeed = "38400";
      break;
    case BC127::s57600bps:
      stringSpeed = "57600";
      break;
    case BC127::s115200bps:
      stringSpeed = "115200";
      break;
    default:
      return INVALID_PARAM;
  }
  
  // If we've made it to here, we had a valid input to the function and should
  //  send it off to the set parameter function.
  intSpeed = atoi(stringSpeed);
  
  // So, there are three possibilities here: SUCCESS, MODULE_ERROR, and
  //  TIMEOUT_ERROR. SUCCESS indicates that you just set the baud rate to the
  //  same baud rate which is currently in use; MODULE_ERROR indicates that
  //  something weird happened to the string before it was sent (honestly, after
  //  I'm done hammering the dents out, I can't imagine that coming up), and
  //  TIMEOUT_ERROR indicates one of two things: an actual timeout, OR success
  //  but we couldn't read it b/c the baud rate was broken. Since we're using
  //  the inheritance of the Stream class to manipulate our serial ports, we
  //  can't change the baud rate. The user should probably just interpret 
  //  TIMEOUT_ERROR as success, and call it good.
  return stdSetParam("BAUD", stringSpeed);
}