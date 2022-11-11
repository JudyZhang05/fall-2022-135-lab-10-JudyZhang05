#include <iostream>
#include "funcs.h"
#include "class.h"

int main(){
    std::string temp; bool doprint = true;

    //TASK A
    
    std::cout << "\nTASK A\n";
    Time second; Time first;
    first.h = 10;
    first.m = 30;
    second.h = 13;
    second.m = 40;

    std::cout << "Enter first time: ";
    printTime(first,temp, doprint); 
    std::cout << "\nEnter second time: "; 
    printTime(second,temp, doprint);

    std::cout << "\nThese moments of time are " << minutesSinceMidnight(first) << " and " << minutesSinceMidnight(second) << " minutes after midnight.\nThe interval between them is " << minutesUntil(first,second) << " minutes.";

    //TASK B

    Time addition;
    addition.h = 8;
    addition.m = 10;
    std::cout << "\n\nTASK B\nCurent Time: ";
    printTime(addition,temp, doprint);
    std::cout << "\nTime after adding more time: ";
    printTime(addMinutes(addition, 75),temp, doprint);
    std::cout << '\n';

    //TASK C
    
    std::cout << "\nTASK C\n";

    TimeSlot morning;
    morning.movie.title = "Graveyard of the Fireflies";
    Genre d = Genre::DRAMA;
    morning.movie.genre = d;
    morning.movie.duration = 89;
    morning.startTime.h = 3;
    morning.startTime.m = 20;

    std::cout << getTimeSlot(morning);


    TimeSlot late_morning;
    late_morning.movie.title = "Train To Busan";
    Genre de = Genre::ACTION;
    late_morning.movie.genre = de;
    late_morning.movie.duration = 118;
    late_morning.startTime.h = 6;
    late_morning.startTime.m = 10;

    std::cout << getTimeSlot(late_morning);


    TimeSlot lunch;
    lunch.movie.title = "50 first dates";
    Genre dec = Genre::ROMANCE;
    lunch.movie.genre = dec;
    lunch.movie.duration = 99;
    lunch.startTime.h = 9;
    lunch.startTime.m = 35;

    std::cout << getTimeSlot(lunch);


    TimeSlot daytime;
    daytime.movie.title = "VIOLET EVERGARDEN";
    Genre decl = Genre::THRILLER;
    daytime.movie.genre = decl;
    daytime.movie.duration = 140;
    daytime.startTime.h = 12;
    daytime.startTime.m = 15;

    std::cout << getTimeSlot(daytime);

    TimeSlot evening;    
    evening.movie.title = "TITANIC";
    Genre declare = Genre::ROMANCE;
    evening.movie.genre = declare;
    evening.movie.duration = 194;
    evening.startTime.h = 16;
    evening.startTime.m = 45;
    
    std::cout << getTimeSlot(evening);

    //TASK D
    std::cout << "\nTASK D\nThe next scheduled movie is  " << getTimeSlot(scheduleAfter(morning, evening.movie));

    //TASK E
    std::cout << "\nTASK E\n" << timeOverlap(daytime, lunch) << std::endl;
    
    return 0;
}
