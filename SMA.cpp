#include "SMA.h"
#include <arduino.h>


SMA::SMA(int n) {
  _sampleSize = n;
 // _samples[n];
 _samples = (int*) malloc(_sampleSize*sizeof(int));
  clr();
}

void SMA::clr() {
  _sampleIndex = 0;
  _sum = 0;
  for (int i = 0; i < _sampleSize; i++) _samples[i] = 0;
}

void SMA::addValue(int sampleValue) {
  _sum = _sum - _samples[_sampleIndex] + sampleValue;
  _samples[_sampleIndex] = sampleValue;
  _average = _sum / _sampleSize;
//  if (_tempSamples >= _sampleSize) { // if array is filled with samples, then divide by the total number of elements
//    _average = _sum / _sampleSize;
//  }
//  else _average = _sum / ++_tempSamples;
  if (_sampleIndex >= _sampleSize-1) _sampleIndex = 0; // Cycle the position of element to be replaced in the array
  else _sampleIndex++;
}

int SMA::getAverage() {
  return _average;
}

long SMA::getSum(){
  return _sum;
}
