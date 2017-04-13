#pragma once

#include "ofMain.h"
#include "ofxLeapMotion2.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void playmusic();
    void exit();
    
    int left = 0;
    int vol = 0;
    ofVideoPlayer myPlayer;
    ofSoundPlayer mySound;
    ofImage myImage;
    
    ofxLeapMotion leap;
    vector <ofxLeapMotionSimpleHand> simpleHands;
    
    vector <int> fingersFound;
    ofEasyCam cam;
};

// first point must always be (0,0)
// given a RELATIVE set of ofPoints and a timeout this
// class can coarsely match simple gestures
// BUG: can go unlimited distance beyond if within time limit
class simpleGesture {
public:
    void setup(ofPoint *points, int maxIndex, int msTout);
    bool track1(ofPoint inputPoint);  // given a moving input point returns true if matched
    bool track2(ofPoint inputPoint);
    
    int maxIdx;		// max gesture array index
    int timeout;	// how long do we have to match the gesture before reset
    
private:
    ofPoint *gPts;	// array of key points in our gesture
    int stepStartTime = 0; // when we finished the last step in the whole gesture
    int curIdx;	// current point we are matching to
    ofPoint lastPoint;  // where last point matched
    
}; 
