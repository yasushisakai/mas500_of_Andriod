#pragma once

class Ball{

public:

    int id;

    ofPoint position;
    ofPoint velocity;
    float radius;
    ofColor color;

    Ball(){

        id = -1;

        position.set(ofRandomWidth(),ofRandomHeight(),0);
        velocity.set(0,0,0);
        radius = 60;

        color.r = 255;
        color.g = 187;
        color.b = 0;
        color.a = 255;
    }

    void moveTo(const ofPoint &newPos){
        position = newPos;
    }

    float distanceTo(const ofPoint &test_pos){
        return ofDist(position.x,position.y,test_pos.x,test_pos.y);
    }

    float distanceTo(const Ball &other_ball){
        return ofDist(position.x,position.y,other_ball.position.x,other_ball.position.y);
    }

    void flipVelocity(){
        velocity = -velocity*0.9;
    }

    void update(){
        velocity.x += ofxAccelerometer.getForce().x*0.5;
        //??
        velocity.y -= ofxAccelerometer.getForce().y*0.5;

        position += velocity;

        if(position.x < radius){
            position.x = radius;
            velocity.x = -velocity.x*0.9;
        }else if(position.x > ofGetWidth() - radius){
            position.x = ofGetWidth() - radius;
            velocity.x = -velocity.x*0.9;
        }

        if(position.y < radius){
            position.y = radius;
            velocity.y = - velocity.y;
        }else if(position.y > ofGetHeight() - radius){
            position.y = ofGetHeight() - radius;
            velocity.y = - velocity.y;
        }

    }

    void draw(){
        ofSetColor(color.r,color.g,color.b,color.a);
        ofCircle(position.x,position.y,radius);
    }

};