#include "ofApp.h"

#define NUM_BALL 6

//--------------------------------------------------------------
void ofApp::setup(){

	ofxAccelerometer.setup();

	tick.loadSound("sound/tick.mp3");

	for(int i=0;i<15;i++){
		string n = "";
		if(i<10){
			notes[i].loadSound("notes/0"+ofToString(i)+".mp3");
		}else{
			notes[i].loadSound("notes/"+ofToString(i)+".mp3");
		}

		notes[i].setVolume(0.5f);
		notes[i].setMultiPlay(true);
	}

	//http://jetcityorange.com/musical-notes/
	tick.setVolume(0.5f);
	tick.setMultiPlay(true);

	ofBackground(255,211,0);

	for(int i=0;i<NUM_BALL;++i){
		balls.push_back(Ball());
	}

	ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update() {



	for(vector<Ball>::iterator it = balls.begin();it != balls.end();++it){
		(*it).update();
	}
	collide_bounce(balls);
}

//--------------------------------------------------------------
void ofApp::draw() {


	//draw balls
	ofFill();
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

	int note_num = 0;
	for(int i =0;i<bs.size();++i){
		for(int j=i+1;j<bs.size();++j){
			temp_distance = bs[i].distanceTo(bs[j]);
			if(temp_distance < (bs[i].radius+bs[j].radius)){
				bs[i].flipVelocity();
				bs[j].flipVelocity();
				//tick.play();
				notes[note_num].play();
			}
			note_num++;
		}
	}
}

