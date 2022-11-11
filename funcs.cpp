#include <iostream>
#include "class.h"
#include "funcs.h"

//TASK A
void printTime(Time time, std::string& result, bool print) {
    if (print == true){
        std::cout << time.h << ":" << time.m;
    }else{
        result += std::to_string(time.h) + ":" + std::to_string(time.m);
    }
}

//GIVEN^

int minutesSinceMidnight(Time time){    //The first function should return the number of minutes from 0:00AM until time.
    int result;
    result = time.m + time.h*60;
    return result;
}

int minutesUntil(Time earlier, Time later){
    int first; int second;
    second = minutesSinceMidnight(later);
    first = minutesSinceMidnight(earlier);

    return second - first;
}

//TASK B

Time addMinutes(Time time0, int min){
    time0.m += min;
    while (time0.m >= 60){
        time0.m -= 60;
        time0.h += 1;
    }
    return time0;
}

//TASK C

void printMovie(Movie mv, std::string& result){
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    //std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
    result += mv.title + ' ' + g + " (" + std::to_string(mv.duration) + " min)";
}

//GIVEN^

std::string getTimeSlot(TimeSlot ts){
    std::string result = ""; bool noprint = false;
    printMovie(ts.movie, result);
    result += " [starts at ";
    printTime(ts.startTime, result, noprint);
    result += " , ends by ";
    printTime(addMinutes(ts.startTime, ts.movie.duration), result, noprint);
    result += " ]\n";
    return result;
}

//TASK D
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot next;
    next.startTime = addMinutes(ts.startTime, ts.movie.duration);
    next.movie = nextMovie;
    return next;
}

//TASK E
bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    TimeSlot first; TimeSlot second;
    if (ts1.startTime.h > ts2.startTime.h){
        first = ts2;
        second = ts1;
    }
    else{
        first = ts1;
        second = ts2;
    }

    if (second.startTime.h < addMinutes(first.startTime, first.movie.duration).h){
        return true;
    }
    else if(second.startTime.m < addMinutes(first.startTime,first.movie.duration).m){
        return true;
    }
    return false;
}


// int main(){ //EXAMPLE MAIN
//     Time now;    // creates a new variable (or object)
//     now.h = 17;  // assigns its hours field
//     now.m = 45;  // assigns its minutes field 

//     Time t = { 17, 45 };

//     Time morningLecture = {8, 10};

//     Time myAlarm;              // make another variable

//     myAlarm = morningLecture;    // copying

//     printTime(morningLecture);   // will print 8:10
//     printTime(myAlarm);        // will print 8:10 as well
//                             // You may be late for the class tho
// }