//
//  Ship.hpp
//  Masteroids
//
//  Created by Lilly Fiorino on 5/30/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef Ship_hpp
#define Ship_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class Ship {
private:
    double location[2];
    double angle;
    double moment[2];
    int state;
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    int map[640][640];
    double vec0[2];
    double vec1[2];
    double vec2[2];
public:
    Ship(int w, int h);
    void setLocation(int i, double j);
    void setLocation(double i, double j);
    double getLocation(int i);
    double* getLocation();
    void setMoment(int i, float j);
    void setMoment(float i, float j);
    double getMoment(int i);
    double* getMoment();
    void setAngle(double i);
    double getAngle();
    void setState(int i);
    int getState();
    void renderShip( SDL_Renderer* &gRenderer );
    void initialize();
    void iterate();
    void addPoint( double x, double y );
    void rotatePoint(double v1, double v2, double &out1, double &out2, double angle);
    void thrust(double thr);
    
};

#endif /* Ship_hpp */
