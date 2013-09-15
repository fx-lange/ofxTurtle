#include "ofApp.h"
#include "ofxTurtle.h"

ofxTurtle turtle;

//--------------------------------------------------------------
void ofApp::setup(){
	turtle.addMovement(BACK,100);
	turtle.addMovement(FORWARD,100);
	for(int i=0;i<3;++i){
		turtle.addMovement(RIGHT,90);
		turtle.addMovement(FORWARD,100);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	turtle.move();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofPushMatrix();
	turtle.draw();
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
