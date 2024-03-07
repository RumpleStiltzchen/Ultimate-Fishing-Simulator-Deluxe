

#include <raylib.h>
#include <rlgl.h>
#include <vector>
#include "SimplexNoise.cpp"
#include "SimplexNoise.h"
#include <iostream>
#include "Utils.cpp"
#include "Fish.cpp"

#define GLSL_VERSION 330






int main()
{

    int width = 1280;
    int height = 720;

    InitWindow(width, height, "Ultimate Fishing Simulator Deluxe");
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);

    

    SetWindowSize(width, height);

    SetTargetFPS(144);
    
    
    std::vector<Fish*> FishTypes = GetFish("E:/Coding/windows/C++/UFSD/build/res/fish");
    for(auto& fish : FishTypes)
    {
        fish->printInfo();
        
    }
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();

    
    while(!WindowShouldClose())
    {

        

    

        
        BeginDrawing();
            ClearBackground(BLACK);
            
            DrawFPS(10, 10);
        EndDrawing();

    }
  

    CloseWindow();
}