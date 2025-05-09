
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Header.h"


int main()
{
    
    //SETUP

    Player cj;

    Input input = Input::NONE;

    cj.playerPos.x = 3;
    cj.playerPos.y = 3;
    cj.playerDir = Direction::UP;

    std::ifstream config("config.txt");

    if (config.is_open())
    {

        while (config >> x >> y) {}

    }
    config.close();

    Cell** map = new Cell* [x];

    for (int i = 0; i < x; ++i)
    {
        map[i] = new Cell[y];
    }

    initMap(map, cj);

    //-------GAMELOOP------

    while (true)
    {
        system("CLS");

        //INPUT

        if (GetAsyncKeyState(VK_UP))
        {
            input = Input::UP;
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            input = Input::DOWN;
        }
        else if (GetAsyncKeyState(VK_LEFT))
        {
            input = Input::LEFT;
        }
        else if (GetAsyncKeyState(VK_RIGHT))
        {
            input = Input::RIGHT;
        }
        else
        {
            input = Input::NONE;
        }

        //UPDATE

        setPosition(cj, input, map);
        movePlayer(cj, map, input);

        //RENDER

        printMap(map, cj);

        //FRAMECONTROL 
        Sleep(1000);
    }
    

}

