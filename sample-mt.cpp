// to compile:
//  g++ sample-mt.cpp -L/usr/lib -L/usr/local/lib -I/usr/include -lboost_thread -lboost_system -lboost_date_time
//
// to run
//  a.out [SAMPLING RATE]
#include <iostream>
#include <fstream>  // to write a log

// Include Boost headers for system time and threading
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/thread.hpp"

using namespace std;
using namespace boost::posix_time;

// function for sampling thread
void captureFunc(void* data){
    //loop infinitely
    for(;;){
        ///////////////////////////////////////////////////////////////////////

        // sample your signal and save it to data
        //
        // ADD YOUR CODE HERE
        //
        ///////////////////////////////////////////////////////////////////////

    }
}


//#define MAX_DURATION_IN_MIN 1
#define MAX_DURATION_IN_MIN 5


//main
int main (int argc, char *argv[]) {
    // determine filename based on recording time
    string recordingTime = to_iso_string(second_clock::local_time());
    // http://www.boost.org/doc/libs/1_43_0/doc/html/date_time/posix_time.html
    cout << "recording time=" << recordingTime << endl;

    // open log file
    ostringstream logFilename;
    logFilename << recordingTime << "_log.txt";
    ofstream logfile (logFilename.str());
    if (!logfile.is_open()) {
        cout << "Unable to open logfile";
        return -1;
    }

    // log basic info
    logfile << "recording time=" << recordingTime << endl;

    //vars
    time_duration td, td1;
    ptime nextFrameTimestamp, currentFrameTimestamp, initialLoopTimestamp, finalLoopTimestamp;
    int delayFound = 0;
    int totalDelay= 0;


    // set samplingRate for recoding
    int samplingRate = 10;    // 0.1 s
    //int samplingRate = 100;    // 0.01 s
    //int samplingRate = 1000;    // 0.001 s
    if (argc>1) {	// you can specify rate with input argument
        samplingRate = atoi(argv[1]);
    }
    cout << "Sampling rate=" << samplingRate << endl;
    logfile << "Sampling rate=" << samplingRate << endl;




    // initialize initial timestamps
    nextFrameTimestamp = microsec_clock::local_time();
    currentFrameTimestamp = nextFrameTimestamp;
    td = (currentFrameTimestamp - nextFrameTimestamp);

    // start thread to begin capture and populate Mat frame

    int grab[256];
    boost::thread captureThread(captureFunc, &grab);

    // loop infinitely
    int cnt = 0;
    for(cnt=0; cnt<MAX_DURATION_IN_MIN*60*samplingRate; cnt++) {

        // wait for X microseconds until 1second/samplingRate time has passed after previous frame write
        while(td.total_microseconds() < 1000000/samplingRate){
            //determine current elapsed time
            currentFrameTimestamp = microsec_clock::local_time();
            td = (currentFrameTimestamp - nextFrameTimestamp);
        }

        //   determine time at start of write
        initialLoopTimestamp = microsec_clock::local_time();

        //write previous and current frame timestamp to console
        cout << nextFrameTimestamp << " " << currentFrameTimestamp << " ";

        // add 1second/samplingRate time for next loop pause
        nextFrameTimestamp = nextFrameTimestamp + microsec(1000000/samplingRate);

        // reset time_duration so while loop engages
        td = (currentFrameTimestamp - nextFrameTimestamp);

        //determine and print out delay in ms, should be less than 1000/Sampling rate
        //occasionally, if delay is larger than said value, correction will occur
        //if delay is consistently larger than said value, then CPU is not powerful
        // enough to capture/decompress/record/compress that fast.
        finalLoopTimestamp = microsec_clock::local_time();
        td1 = (finalLoopTimestamp - initialLoopTimestamp);
        delayFound = td1.total_milliseconds();
        cout << delayFound << endl;

        //output will be in following format
        //[TIMESTAMP OF PREVIOUS FRAME] [TIMESTAMP OF NEW FRAME] [TIME DELAY OF WRITING]

    }


    logfile << "numSamples=" << cnt << endl;
    logfile.close();

    // Exit
    return 0;
}
