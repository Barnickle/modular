#include <patterns/SerialAPI.h>

SerialAPI::SerialAPI() {
  apiBuffer = "";
};

void SerialAPI::handleSerialInstruction(String task, String value) {
   // Implemnation need to be done in the derived class for now
   Serial.println("Task revieced: " + task + " : " + value);
}

void SerialAPI::run() {
  while (Serial.available() > 0) {
    //workstate:'workstate',rate:'blinkrate'\n
    //workstate:1, rate:30\n

    if (Serial.available() > 0) {
         char c = Serial.read();
         apiBuffer += c;
         //Serial.println(apiBuffer);
        if (c == ';') {
          //Serial.println("Task revieced: " + apiBuffer);
          String order = apiBuffer.substring(0, apiBuffer.length() - 1);
          int j = order.indexOf(':');
          String task = order.substring(0, j);
          String value = order.substring(j+1);
          task.trim();
          value.trim();
          handleSerialInstruction(task, value);
          apiBuffer = "";
        }
    }
  }
}
