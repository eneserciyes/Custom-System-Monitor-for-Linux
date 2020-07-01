#include <fstream>
#include <string>

#include "Time.h"

class Util {
 public:
  static Time convertToTime(long int input_seconds);
  static std::string getProgressBar(std::string percent);
  static std::ifstream getStream(std::string path);
};

Time Util::convertToTime(long int input_seconds) {
  long minutes = input_seconds / 60;
  long hours = minutes / 60;
  long seconds = int(input_seconds % 60);
  minutes = int(minutes % 60);

  return Time(hours, minutes, seconds);
}

std::string Util::getProgressBar(std::string percent) {
  std::string result = "0% ";
  int size = 50;
  int boundaries = (std::stof(percent) / 100) * size;
  for (int i = 0; i < size; i++) {
    if (i <= boundaries)
      result += "|";
    else
      result += " ";
  }

  result += " " + percent.substr(0, 5) + " /100%";
  return result;
}

std::ifstream Util::getStream(std::string path) {
  std::ifstream stream(path);
  if (!stream) {
    throw std::runtime_error("Non-existing PID!!");
  }
  return stream;
}