#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <locale.h>

using namespace std;

#define fill_size_x 50
#define fill_size_y 10

int frame(short int &Player_pos_y, short int Player_pos_x, short int &acceleration, char fill[][fill_size_x],ifstream &myfile, string line)
{
    int numlines = 0;
    while (getline(myfile, line))
        numlines++;
    myfile.close();
    myfile.open("level.txt");

    char line_char[numlines][line.length() + 1];
    for(int j = 0; j < numlines; j++){
        for (int i = 0; i < sizeof(line_char); i++) { 
            line_char[j][i] = line[i]; 
        }
        getline(myfile, line);
    }
    
    

    for(int i = 0; i< fill_size_y; i++){
        for(int j = 0; j < fill_size_x; j++){
            fill[i][j] = line_char[i][j];
        }
    }

    if(acceleration > 0)
        Player_pos_y -=2;
    
    if(acceleration > 0)
        acceleration--;
    
    cout << acceleration;
    if(fill[Player_pos_y+1][Player_pos_x] != '=')
        Player_pos_y++;
    return 0;
}

void render(short int Player_pos_x, short int Player_pos_y, char fill[][fill_size_x])
{
    for(int i = 0; i < 10; i++)
        cout << endl;

    fill[Player_pos_y][Player_pos_x] = '@';

    for(int i = 0; i< fill_size_y; i++)
    {
        for(int j = 0; j < fill_size_x; j++)
        {
            cout << fill[i][j];
        }
        cout << endl;
    }
}

int main()
{
    short int Player_pos_x = 5;
    short int Player_pos_y = fill_size_y-2;
    short int acceleration = 0;

    string line;
    ifstream myfile ("level.txt");

    char fill[fill_size_y][fill_size_x];
    while(true)
    {
        if(kbhit() and fill[Player_pos_y+1][Player_pos_x] == '=')
        {
            switch(getch())
            {
                case 'w': acceleration += 5; break;
                case 's': acceleration += 5; break;
                default: break;
            }
        }
        frame(Player_pos_y, Player_pos_y, acceleration, fill, myfile, line);
        Sleep(200);
        render(Player_pos_x, Player_pos_y, fill);
    }
    
    return 0;
}