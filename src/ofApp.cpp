#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("oscReceiveExample");
	ofSetFrameRate(20); // run at 60 fps
	ofSetVerticalSync(true);

	for (size_t offset = 0; offset < 10; ++offset)
	{
		receivers.push_back({});
		receivers.back().setup(12345 + offset);
		offset++;
	}
}

void ofApp::addPoint(ofxOscMessage& m)
{
	// check for mouse moved message
	if (m.getAddress() == "/custom/face") {
		for (size_t i = 0; i < m.getNumArgs(); i += 3) {
			ofVec3f point;
			point.x = m.getArgAsFloat(i);
			point.y = m.getArgAsFloat(i + 1);
			point.z = m.getArgAsFloat(i + 2);
			face.push_back(point);
		}
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	face.clear();

	for (auto& receiver : receivers)
	{
		while (receiver.hasWaitingMessages()) {
			// get the next message
			ofxOscMessage m;
			receiver.getNextMessage(m);
			addPoint(m);
		}
	}
}


//--------------------------------------------------------------
void ofApp::draw(){
	easyCam.begin();
	ofBackground(0);
	ofSetColor(255);
	for (const auto& point : face)
	{
		ofSphere(point*1000.0, 1);
	}

	easyCam.end();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
