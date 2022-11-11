#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "class.h"

Time tA; Time tB; Time tC; Time tD;
TimeSlot taska; TimeSlot taskb; TimeSlot taskc; TimeSlot taskd; std::string temp; bool print = true; 

void movieStorageArea(){
    
    tA.h = 12; tA.m = 15;
    tB.h = 7; tB.m = 55;
    tC.h = 9; tC.m = 10;
    tD.h = 11; tD.m = 20;

    taska.movie.title = "VIOLET EVERGARDEN";
    Genre decl = Genre::THRILLER;
    taska.movie.genre = decl;
    taska.movie.duration = 140;
    taska.startTime.h = 12;
    taska.startTime.m = 15;
    
    taskb.movie.title = "Creep";
    Genre dec = Genre::ACTION;
    taskb.movie.genre = dec;
    taskb.movie.duration = 160;
    taskb.startTime.h = 7;
    taskb.startTime.m = 55;

    taskc.movie.title = "SMILE";
    Genre de = Genre::ROMANCE;
    taskc.movie.genre = de;
    taskc.movie.duration = 220;
    taskc.startTime.h = 9;
    taskc.startTime.m = 10;

    taskd.movie.title = "WRONG TURN";
    Genre d = Genre::COMEDY;
    taskd.movie.genre = d;
    taskd.movie.duration = 180;
    taskd.startTime.h = 11;
    taskd.startTime.m = 20;


}

TEST_CASE("TASK A"){
    CHECK(minutesSinceMidnight(tA) == 0);    //735
    CHECK(minutesSinceMidnight(tB) == 0);    //475
    CHECK(minutesSinceMidnight(tC) == 0);    //550
    CHECK(minutesSinceMidnight(tD) == 0);    //680

    CHECK(minutesUntil(taskb.startTime, taskc.startTime) == 0);    //75
    CHECK(minutesUntil(taskd.startTime, taska.startTime) == 0);    //55
    CHECK(minutesUntil(taskb.startTime, taskd.startTime) == 0);   //205
    CHECK(minutesUntil(taskb.startTime, taska.startTime) == 0);   //260
}

TEST_CASE("TASK B"){
    CHECK(addMinutes(taska.startTime,40).m == 40);
    CHECK(addMinutes(taska.startTime,140).h == 2);
    CHECK(addMinutes(taska.startTime,140).m == 20);
    CHECK(addMinutes(taskb.startTime,560).h == 9);
    CHECK(addMinutes(taskb.startTime,560).m == 20);
}

// TEST_CASE("TASK C"){
//     CHECK(getTimeSlot(taska) == "VIOLET EVERGARDEN THRILLER (0 min) [starts at 0:0 , ends by 0:0 ]");
//     CHECK(getTimeSlot(taskb) == "Creep ACTION (0 min) [starts at 0:0 , ends by 0:0 ]");
//     CHECK(getTimeSlot(taskc) == "SMILE ROMANCE (0 min) [starts at 0:0 , ends by 0:0 ]");
//     CHECK(getTimeSlot(taskd) == "WRONG TURN COMEDY (0 min) [starts at 0:0 , ends by 0:0 ]");
// }

TEST_CASE("TASK D"){
    CHECK(scheduleAfter(taska, taska.movie).startTime.h == 0);
    CHECK(scheduleAfter(taskb, taskb.movie).startTime.h == 0);
    CHECK(scheduleAfter(taskc, taskc.movie).startTime.h == 0);
    CHECK(scheduleAfter(taskd, taskd.movie).startTime.h == 0);    
}

TEST_CASE("TASK E"){
    CHECK(timeOverlap(taska, taskb) == false);
    CHECK(timeOverlap(taskc, taskd) == false);
    CHECK(timeOverlap(taska, taskc) == false);
    CHECK(timeOverlap(taskb, taskd) == false);
}