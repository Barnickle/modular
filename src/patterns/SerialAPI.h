#include <Arduino.h>

#ifndef SerialAPI_h
#define SerialAPI_h

#define HANDMIN   0
#define HANDMAX  65
#define ARMMIN   10 // 200 has Colissionwith Caterpillar
#define ARMMAX  110

class SerialAPI
{
  public:
    SerialAPI();
    void run();
    void handleSerialInstruction(String task, String value);
  protected:
    String apiBuffer;
};

#endif
