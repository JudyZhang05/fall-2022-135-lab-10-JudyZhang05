#include <iostream>
#include "class.h"
#pragma once


void printTime(Time time, std::string& result, bool print);
void printMovie(Movie mv, std::string& result);

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
std::string getTimeSlot(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 
