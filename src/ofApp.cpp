#include "ofApp.h"

#define NUM_BALL 10

//--------------------------------------------------------------
void ofApp::setup(){

	ofxAccelerometer.setup();

	ofBackground(255,211,0);

	for(int i=0;i<NUM_BALL;++i){
		balls.push_back(Ball());
	}

	ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update() {

	collide_bounce(balls);

	for(vector<Ball>::iterator it = balls.begin();it != balls.end();++it){
		(*it).update();
	}

}

//--------------------------------------------------------------
void ofApp::draw() {
	for(vector<Ball>::iterator it = balls.begin();it != balls.end();++it){
		(*it).draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::touchDown(int x, int y, int id){
	move_closest(ofPoint(x,y),balls);
}

//--------------------------------------------------------------
void ofApp::touchMoved(int x, int y, int id){
}

//--------------------------------------------------------------
void ofApp::touchUp(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(int x, int y, int id){
}

//--------------------------------------------------------------
void ofApp::touchCancelled(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::swipe(ofxAndroidSwipeDir swipeDir, int id){
}

//--------------------------------------------------------------
void ofApp::pause(){

}

//--------------------------------------------------------------
void ofApp::stop(){

}

//--------------------------------------------------------------
void ofApp::resume(){

}

//--------------------------------------------------------------
void ofApp::reloadTextures(){

}

//--------------------------------------------------------------
bool ofApp::backPressed(){
	return false;
}

//--------------------------------------------------------------
void ofApp::okPressed(){
}

//--------------------------------------------------------------
void ofApp::cancelPressed(){
}

void ofApp::move_closest(const ofPoint &pos,vector<Ball> &bs){

	float min_distance = 100000000.f;
	float temp_dist = 0;
	int closest_id = -1;

	for(int i=0;i<bs.size();++i){
		temp_dist = bs[i].distanceTo(pos);

		if(min_distance>temp_dist){
			min_distance = temp_dist;
			closest_id = i;
		}
	}

	bs[closest_id].moveTo(pos);

}

void ofApp::collide_bounce(vector<Ball> &bs){
	float temp_distance;

	for(int i =0;i<bs.size();++i){
		for(int j=i+1;j<bs.size();++j){
			temp_distance = bs[i].distanceTo(bs[j]);
			if(temp_distance < (bs[i].radius+bs[j].radius)){
				bs[i].flipVelocity();
				bs[i].update();
				bs[j].flipVelocity();
				bs[j].update();
			}
		}
	}
}

