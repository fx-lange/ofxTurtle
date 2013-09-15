/*
 * ofxTurtle.h
 *
 *  Created on: Sep 15, 2013
 *      Author: felix
 */

#ifndef OFXTURTLE_H_
#define OFXTURTLE_H_

#include "ofMain.h"

enum TurtleDirection {
	FORWARD,
	BACK,
	LEFT,
	RIGHT
};

struct TurtleMove{
	TurtleDirection dir;
	int amount;
};

class ofxTurtle {
public:
	ofxTurtle();
	virtual ~ofxTurtle();

	void move();
	void draw();

	void addMovement(TurtleDirection dir, int amount);
private:
	list<ofPolyline> painting;
	list<TurtleMove> actions;

	int stepsToGo;

	ofVec2f direction;
	float angle;
	ofVec2f position;
	bool bForward;
};

#endif /* OFXTURTLE_H_ */
