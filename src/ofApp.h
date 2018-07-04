#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

// demonstrates receiving and processing OSC messages with an ofxOscReceiver,
// use in conjunction with the oscSenderExample
class ofApp : public ofBaseApp{
	public:

		void setup();
		void update();
		void draw();

		void addPoint(ofxOscMessage& m);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofTrueTypeFont font;
		std::vector<ofxOscReceiver> receivers;

		float mouseXf = 0;
		float mouseYf = 0;
		int mouseButtonInt = 0;
		string mouseButtonState = "";

		ofImage receivedImage;

		std::vector<ofVec3f> face;

		ofEasyCam easyCam;
};
