#pragma once

class Time {
 private:
  int hour{0};
  int minute{0};
  int second{0};

 public:
  Time() {}
  Time(int h, int m, int s) : hour(h), minute(m), second(s) {}
  int Hour() { return hour; }
  int Minute() { return minute; }
  int Second() { return second; }
  void Hour(int h) { hour = h; }
  void Minute(int m) { minute = m; }
  void Second(int s) { second = s; }
};
