#pragma once

//----------------

int x;
int y;

int camRad = 20;

struct Postion
{
    int x;
    int y;
};

enum class Cell
{
    CJ,
    PARED,
    PEATON,
    DINERO,
    VACIO
};

enum class Input
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SPACE,
    ESC,
    NONE
};

enum class Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Player
{
    Postion playerPos;
    Direction playerDir;
};

void initMap(Cell** map, Player player)
{
    // Initialize all cells to VACIO
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            map[j][i] = Cell::VACIO;
        }
    }

    // Set the borders to PARED
    for (int i = 0; i < x; i++)
    {
        map[i][0] = Cell::PARED;
        map[i][y - 1] = Cell::PARED;
    }

    for (int i = 0; i < y; i++)
    {
        map[0][i] = Cell::PARED;
        map[x - 1][i] = Cell::PARED;
    }

    for (int i = 1; i < y; i++)
    {
        for (int j = 6; j < x; j++)
        {
            if ( ((x - 4) / 3)%j == 0 && i != (y / 2) && i != ((y / 2) - 1)&& i != ((y / 2) + 1))
            {
                map[j][i] = Cell::PARED;
            }
        }
    }

    map[player.playerPos.x][player.playerPos.y] = Cell::CJ;

}

void printMap(Cell** map, Player player)
{
    char sym;
    for (int i = player.playerPos.y - camRad; i < player.playerPos.y + camRad; i++)
    {
        if (i < 0 || i > y)
            continue;

        for (int j = player.playerPos.x - camRad; j < player.playerPos.x + camRad; j++)
        {

            if (j < 0 || j > x)
                continue;

            switch (map[j][i])
            {
            case Cell::PARED:
                sym = 'X';
                std::cout << sym << " ";
                break;
            case Cell::CJ:
                
                switch (player.playerDir)
                {

                case Direction::UP:
                    std::cout << "^";
                    break;
                case Direction::DOWN:
                    std::cout << "v";
                    break;
                case Direction::RIGHT:
                    std::cout << ">";
                    break;
                case Direction::LEFT:
                    std::cout << "<";
                    break;
                }
                std::cout << " ";

                break;
            case Cell::PEATON:
                sym = 'P';
                std::cout << sym << " ";
                break;
            case Cell::DINERO:
                sym = '$';
                std::cout << sym << " ";
                break;
            default:
                sym = ' ';
                std::cout << sym << " ";
                break;
            }
        }
        std::cout << std::endl;
    }
}

void setPosition(Player& player, Input input, Cell** map)
{
    switch (input)
    {
    case Input::UP:
        if (map[player.playerPos.x][player.playerPos.y - 1] == Cell::PARED)
            break;
        player.playerPos.y--;
        player.playerDir = Direction::UP;
        break;
    case Input::DOWN:
        if (map[player.playerPos.x][player.playerPos.y + 1] == Cell::PARED)
            break;
        player.playerPos.y++;
        player.playerDir = Direction::DOWN;
        break;
    case Input::LEFT:
        if (map[player.playerPos.x - 1][player.playerPos.y] == Cell::PARED)
            break;
        player.playerPos.x--;
        player.playerDir = Direction::LEFT;
        break;
    case Input::RIGHT:
        if (map[player.playerPos.x + 1][player.playerPos.y] == Cell::PARED)
            break;
        player.playerPos.x++;
        player.playerDir = Direction::RIGHT;
        break;
    }
}

void movePlayer(Player player, Cell** map, Input input)
{

    if (input == Input::NONE)
        return;
    switch (input)
    {
    case Input::UP:
        map[player.playerPos.x][player.playerPos.y] = Cell::CJ;
        map[player.playerPos.x][player.playerPos.y+1] = Cell::VACIO;
        break;
    case Input::DOWN:
        map[player.playerPos.x][player.playerPos.y] = Cell::CJ;
        map[player.playerPos.x][player.playerPos.y-1] = Cell::VACIO;
        break;
    case Input::LEFT:
        map[player.playerPos.x][player.playerPos.y] = Cell::CJ;
        map[player.playerPos.x+1][player.playerPos.y] = Cell::VACIO;
        break;
    case Input::RIGHT:
        map[player.playerPos.x][player.playerPos.y] = Cell::CJ;
        map[player.playerPos.x-1][player.playerPos.y] = Cell::VACIO;
        break;
    }

    

}