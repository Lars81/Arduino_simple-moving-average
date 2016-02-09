// Simple Moving Average


#ifndef SMA_h
#define SMA_h
#include <arduino.h>

class SMA {
  public:
    SMA(int);
    void addValue(int);
    int getAverage();
    long getSum();
    void clr();

  private:
    byte _sampleSize, _tempSamples, _sampleIndex;
    long _sum;
    //  int _samples[];
    int *_samples;
    int _average;
};
#endif
