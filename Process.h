#include <string>

#include "Time.h"

using namespace std;

class Process {
 private:
  string PID;
  string user;
  string cmd;
  double cpu_percentage;
  double memory;
  Time upTime;

 public:
  Process() {}

  string PID() { return PID; }
  void PID(string pid) { PID = pid; }

  string User() { return user; }
  void User(string user) { this->user = user; }

  string Cmd() { return cmd; }
  void Cmd(string cmd) { this->cmd = cmd; }

  double CPU_Percentage() { return cpu_percentage; }
  void CPU_Percentage(double cpu) { cpu_percentage = cpu; }

  double Memory() { return memory; }
  void Memory(double memory) { this->memory = memory; }

  Time UpTime() { return upTime; }
  void UpTime(Time time) { upTime = time; }
};