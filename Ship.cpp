//
//  Ship.cpp
//  Masteroids
//
//  Created blocation[1] Lilllocation[1] Fiorino on 5/30/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include "Ship.hpp"
#include <SDL2/SDL.h>
#include <math.h>
#include <iostream>
#include <vector>



Ship::Ship( const int w, const int h){
    SCREEN_WIDTH = w;
    SCREEN_HEIGHT = h;
    angle = 0;
    state = 0;
    moment[0] = 0;
    moment[1] = 0;
    for(int a=0;a<640;a++){
        for(int b=0;b<640;b++){
            map[a][b] = 0;
        }
    }
    vec0[0] = 50;
    vec0[1] = 50;
    vec1[0] = -150;
    vec1[1] = 50;
    vec2[0] = 50;
    vec2[1] = -150;
}

// Location
void Ship::setLocation(int i, double j){
    location[i] = j;
}
void Ship::setLocation(double i, double j){
    location[0] = i;
    location[1] = j;
}
double Ship::getLocation(int i){
    return location[i];
}
double* Ship::getLocation(){
    static double out[2];
    out[0] = location[0];
    out[1] = location[1];
    return out;
}

// Moment
void Ship::setMoment(int i, float j){
    moment[i] = j;
}
void Ship::setMoment(float i, float j){
    moment[0] = i;
    moment[1] = j;
}
double Ship::getMoment(int i){
    return moment[i];
}
double* Ship::getMoment(){
    static double out[2];
    out[0] = moment[0];
    out[1] = moment[1];
    return out;
}

// Angle
void Ship::setAngle(double i){
    angle = i;
}
double Ship::getAngle(){
    return angle;
}

// State
void Ship::setState(int i){
    state = i;
}
int Ship::getState(){
    return state;
}
double temp0[2];
double temp1[2];
double temp2[2];
void Ship::renderShip(SDL_Renderer* &gRenderer){
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    
//    addPoint(location[0]+vec0[0], location[1]+vec0[1]);
//    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0x00, 0xFF );
//    for(int a=0;a<640;a++){
//        for(int b=0;b<640;b++){
//            if(map[a][b] != 0){
//                SDL_RenderDrawPoint(gRenderer, a, b);
//            }
//        }
//    }
    rotatePoint(vec0[0], vec0[1], temp0[0], temp0[1], angle);
    rotatePoint(vec1[0], vec1[1], temp1[0], temp1[1], angle);
    rotatePoint(vec2[0], vec2[1], temp2[0], temp2[1], angle);
    SDL_RenderDrawLine(gRenderer, location[0] + temp0[0], location[1] + temp0[1], location[0] + temp1[0], location[1] + temp1[1]);
    SDL_RenderDrawLine(gRenderer, location[0] + temp0[0], location[1] + temp0[1], location[0] + temp2[0], location[1] + temp2[1]);
    SDL_RenderDrawLine(gRenderer, location[0] + temp1[0], location[1] + temp1[1], location[0] + temp2[0], location[1] + temp2[1]);
    SDL_RenderDrawLine(gRenderer, location[0], location[1], location[0] + temp0[0], location[1] + temp0[1]);
    SDL_RenderDrawLine(gRenderer, location[0], location[1], location[0] + temp1[0], location[1] + temp1[1]);
    SDL_RenderDrawLine(gRenderer, location[0], location[1], location[0] + temp2[0], location[1] + temp2[1]);
}

void Ship::addPoint(double x, double y){
    map[(int)x][(int)y] = 1;
}
void Ship::iterate(){
    location[0] = location[0] + moment[0];
    location[1] = location[1] + moment[1];
    
    if (angle > 3.1415*2){angle = 0;}

    if(location[0] > SCREEN_WIDTH){ location[0] = 0; }
    if(location[1] > SCREEN_HEIGHT){ location[1] = 0; }
    if(location[0] < 0){ location[0] = SCREEN_WIDTH; }
    if(location[1] < 0){ location[1] = SCREEN_HEIGHT; }
    
}

void Ship::rotatePoint(double v1, double v2, double &out1, double &out2, double angle){
    out1 = ( cos(angle) * v1 ) - ( sin(angle) * v2);
    out2 = ( sin(angle) * v1 ) + ( cos(angle) * v2);
}

void Ship::thrust(double thr){
    double ves0;
    double ves1;
    rotatePoint(thr, thr, ves0, ves1, angle);
    moment[0] = moment[0] + ves0;
    moment[1] = moment[1] + ves1;
}

//    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//    SDL_RenderDrawLine( gRenderer, location[0] - 20, location[1] - 20, location[0] + 20, location[1] - 20 );
//    SDL_RenderDrawLine( gRenderer, location[0] + 20, location[1] - 20, location[0] + 20, location[1] - 40 );
//    SDL_RenderDrawLine( gRenderer, location[0] + 20, location[1] - 40, location[0] + 60, location[1] );
//    SDL_RenderDrawLine( gRenderer, location[0] + 60, location[1], location[0] + 20, location[1] );
//    SDL_RenderDrawLine( gRenderer, location[0] + 20, location[1], location[0] + 20, location[1] + 20 );
//    SDL_RenderDrawLine( gRenderer, location[0] + 20, location[1] + 20, location[0],   location[1] + 20 );
//    SDL_RenderDrawLine( gRenderer, location[0], location[1] + 20, location[0],   location[1] + 60 );
//    SDL_RenderDrawLine( gRenderer, location[0], location[1] + 60, location[0] - 40, location[1] + 20 );
//    SDL_RenderDrawLine( gRenderer, location[0] - 40, location[1] + 20, location[0] - 20, location[1] + 20 );
//    SDL_RenderDrawLine( gRenderer, location[0] - 20, location[1] + 20, location[0] - 20, location[1] - 20 );
//    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
//    SDL_RenderDrawLine( gRenderer, location[0] - 20, location[1] + 40, location[0], location[1] + 40 );
//    SDL_RenderDrawLine( gRenderer, location[0] + 40, location[1] - 20, location[0] + 40, location[1] );
//    SDL_RenderDrawLine( gRenderer, location[0], location[1] + 20, location[0] + 20, location[1] );


