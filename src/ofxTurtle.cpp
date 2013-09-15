/*
 * ofxTurtle.cpp
 *
 *  Created on: Sep 15, 2013
 *      Author: felix
 */

#include "ofxTurtle.h"

ofxTurtle::ofxTurtle() {
	stepsToGo = 0;
	bForward = true;
	direction.set(0,-1);
	position.set(200,200);
	painting.push_back(ofPolyline());

	angle = 180;
}

ofxTurtle::~ofxTurtle(){}

void ofxTurtle::addMovement(TurtleDirection dir, int amount){
	TurtleMove move;
	move.dir = dir;
	move.amount = amount;
	actions.push_back(move);
}

void ofxTurtle::move(){

	if(stepsToGo == 0 && !actions.empty()){
		TurtleMove & move = actions.front();
		switch(move.dir){
			case FORWARD:
				stepsToGo = move.amount;
				bForward = true;
				break;
			case BACK:
				stepsToGo = move.amount;
				bForward = false;
				break;
			case LEFT:
				direction.rotate(-move.amount);
				angle -= move.amount;
				break;
			case RIGHT:
				direction.rotate(move.amount);
				angle += move.amount;
				break;
		}
		actions.pop_front();
	}else if(stepsToGo > 0){
		if(bForward){
			position += direction;
		}else{
			position -= direction;
		}

		painting.back().addVertex(position);

		stepsToGo--;
	}else{
		stepsToGo = 0;
	}

}

void ofxTurtle::draw(){
	ofPushMatrix();
	ofPushStyle();

	ofTranslate(position);
	ofRotate(angle);

	ofSetColor(0,0,0);
	ofTriangle(0,0,-5,-5,5,-5);
	ofPopMatrix();

	ofSetColor(255,0,0);
	list<ofPolyline>::iterator it = painting.begin();
	for(;it!=painting.end();++it){
		it->draw();
	}

	ofPopStyle();
}

