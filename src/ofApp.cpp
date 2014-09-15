#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(100);
	wiringPiSetup();

	LEDstate = false;
	LEDpin = 0;

	pinMode(LEDpin, OUTPUT);

	pinMode(7, INPUT);
	pinMode(9, INPUT);
	pinMode(8, INPUT);

	digitalWrite(LEDpin, HIGH);
	digitalWrite(LEDpin, LOW);
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	seconds = ofGetSeconds();
	ofLog() << "seconds: " << seconds << " state: " << LEDstate;

	if(digitalRead(7))
	{
		LEDstate = true;
		ofSetColor(255,0,0);
		ofEllipse(200,200,100,100);
	} 
	else
	{
		LEDstate = false;
	}

	
	if(true == LEDstate)
	{
		digitalWrite(LEDpin, HIGH);
	}
	else if(false == LEDstate)
	{
		digitalWrite(LEDpin, LOW);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	
	ofDrawBitmapString(ofToString(seconds), 20, 15);

	
	if(true == LEDstate)
	{
		ofSetColor(0,255,0);
		ofDrawBitmapString("LED On!", 20, 30);
	}
	else if(false == LEDstate)
	{
		ofSetColor(255,0,0);
		ofDrawBitmapString("LED Off!", 20, 30);
	}
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}