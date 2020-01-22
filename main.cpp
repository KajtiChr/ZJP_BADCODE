#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

int main()
{
    const int N = 12;
    int maze_Values[N][N];
    char maze_Char[N][N];
    char movement;
    bool check = true;
    int player_x = N/2;
    int player_y = 1;
    srand(time(0));
    int maze_exit_x = rand()%(N-2)+1;
    int maze_exit_y = N-2;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if((i!= player_x && j != player_y) || i!= 0 || j!= 0 || i!= N - 1 || j!= N - 1  || (i!= maze_exit_x && j!= maze_exit_y))
            {
                maze_Values[i][j] = 0;
                maze_Char[i][j] = '?';
            }
            if(i == 0 || j == 0 || i == N-1 || j == N-1)
            {
                maze_Values[i][j] = 1;
                maze_Char[i][j] = 'x';
            }
            if(i == player_x && j == player_y)
            {
                maze_Values[i][j] = 2;
                maze_Char[i][j] = 'P';
            }
            if(i == maze_exit_x && j == maze_exit_y)
            {
                maze_Values[i][j] = 3;
                maze_Char[i][j] = 'E';
            }

        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout<< maze_Char[i][j];
            cout<< ' ';
            if(j == N-1) cout<<endl;
        }
    }

    while(player_x != maze_exit_x || player_y != maze_exit_y)

    {
        cout << "Wybierz strone w ktora chcesz sie udac, uzywajac WSADu: ";
        cin >> movement;
        if(movement == 'w' && maze_Values[player_x-1][player_y]!= 1)
        {
            maze_Values[player_x-1][player_y] = 2;
            maze_Values[player_x][player_y] = 4;
            player_x = player_x -1;
        }
        if(movement == 'a' && maze_Values[player_x][player_y-1]!= 1)
        {
            maze_Values[player_x][player_y-1] = 2;
            maze_Values[player_x][player_y] = 4;
            player_y = player_y -1;
        }
        if(movement == 's' && maze_Values[player_x+1][player_y]!= 1)
        {
            maze_Values[player_x+1][player_y] = 2;
            maze_Values[player_x][player_y] = 4;
            player_x = player_x + 1;
        }
        if(movement == 'd' && maze_Values[player_x][player_y+1]!= 1)
        {
            maze_Values[player_x][player_y+1] = 2;
            maze_Values[player_x][player_y] = 4;
            player_y = player_y + 1;
        }

        for (int a = 0; a < N; a++)
        {
            for(int b = 0; b < N; b++)
            {
                if(maze_Values[a][b] == 0)
                {
                    maze_Char[a][b] = '?';
                }
                if(maze_Values[a][b] == 1)
                {
                    maze_Char[a][b] = 'x';
                }
                if(maze_Values[a][b] == 2)
                {
                    maze_Char[a][b] = 'P';
                }
                if(maze_Values[a][b] == 3)
                {
                    maze_Char[a][b] = 'E';
                }
                if(maze_Values[a][b] == 4)
                {
                    maze_Char[a][b] = ' ';
                }
            }
        }

        for(int a = 0; a < N; a++)
        {
            for(int b = 0; b < N; b++)
            {
                cout<< maze_Char[a][b];
                cout<< ' ';
                if(b == N-1) cout<<endl;
            }
        }

    }
    return 0;
}




