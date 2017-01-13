#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <time.h>       /* time */
using namespace std;

int numar_bombe, verifx, verify;
const int sizex = 10, sizey = 10;

bool lose;

class Grid {
public:
	bool has_bomb, marked;
	Grid(void) {
		has_bomb = false;
		marked = false;
	}
};

void drawBoad(Grid board[sizex][sizey])
{
	//  _0_1_2_3_4_5_6_7_8_9_
	// 0|_|_|_|_|_|_|_|_|_|_|
	// 1|_|_|_|_|_|_|_|_|_|_|
	// 2|_|_|_|_|_|_|_|_|_|_|
	// 3|_|_|_|_|_|_|_|_|_|_|
	// 4|_|_|_|_|_|_|_|_|_|_|
	// 5|_|_|_|_|_|_|_|_|_|_|
	// 6|_|_|_|_|_|_|_|_|_|_|
	// 7|_|_|_|_|_|_|_|_|_|_|
	// 8|_|_|_|_|_|_|_|_|_|_|
	// 9|_|_|_|_|_|_|_|_|_|_|
    system("CLS");
	//This draws the top line
	unsigned int nr=0;
	cout << " _";
	for (int i = 0; i < sizex; i++)
	{
		cout << i << "_";
	}
	cout << endl;

	//This draws the body
	for (int y = 0; y < sizey; y++)
	{
		cout << y << "|";
		for (int x = 0; x < sizex; x++)
		{
			if (board[x][y].has_bomb)
			{
				if(board[x][y].marked)
                    {cout << "!|";
                    }
                else
				cout << "_|";
			}
				else if (board[x][y].marked)
			{
				if(x>0&&x<9&&y>0&&y<9)
				{nr=0;
                    if(board[x-1][y].has_bomb)
                        nr++;
                    if(board[x-1][y-1].has_bomb)
                        nr++;
                    if(board[x-1][y+1].has_bomb)
                        nr++;
                    if(board[x][y-1].has_bomb)
                        nr++;
                    if(board[x][y+1].has_bomb)
                        nr++;
                    if(board[x+1][y].has_bomb)
                        nr++;
                    if(board[x+1][y-1].has_bomb)
                        nr++;
                    if(board[x+1][y+1].has_bomb)
                        nr++;
                    cout<< nr<<"|";}
                    else if(x==0&&y>0&&y<9)
                    {
                        nr=0;
                    if(board[x][y-1].has_bomb)
                        nr++;
                    if(board[x][y+1].has_bomb)
                        nr++;
                    if(board[x+1][y].has_bomb)
                        nr++;
                    if(board[x+1][y-1].has_bomb)
                        nr++;
                    if(board[x+1][y+1].has_bomb)
                        nr++;
                        cout<< nr<<"|";
                    }
                    else if(x==9&&y>0&&y<9)
                    {
                        nr=0;
                    if(board[x][y-1].has_bomb)
                        nr++;
                    if(board[x][y+1].has_bomb)
                        nr++;
                    if(board[x-1][y].has_bomb)
                        nr++;
                    if(board[x-1][y-1].has_bomb)
                        nr++;
                    if(board[x-1][y+1].has_bomb)
                        nr++;
                        cout<< nr<<"|";
                    }
                    else if(y==0&&x>0&&x<9)
                    {
                        nr=0;
                    if(board[x+1][y].has_bomb)
                        nr++;
                    if(board[x-1][y].has_bomb)
                        nr++;
                    if(board[x][y+1].has_bomb)
                        nr++;
                    if(board[x-1][y+1].has_bomb)
                        nr++;
                    if(board[x+1][y+1].has_bomb)
                        nr++;
                        cout<< nr<<"|";
                    }
                     else if(y==9&&x>0&&x<9)
                    {
                        nr=0;
                    if(board[x+1][y].has_bomb)
                        nr++;
                    if(board[x-1][y].has_bomb)
                        nr++;
                    if(board[x][y-1].has_bomb)
                        nr++;
                    if(board[x-1][y-1].has_bomb)
                        nr++;
                    if(board[x+1][y-1].has_bomb)
                        nr++;
                        cout<< nr<<"|";
                    }
                    else if(x==0&&y==0)
                    {
                        nr=0;
                    if(board[x][y+1].has_bomb)
                        nr++;
                    if(board[x+1][y].has_bomb)
                        nr++;
                    if(board[x+1][y+1].has_bomb)
                        nr++;
                        cout<< nr<<"|";
                    }
                    else if(x==9&&y==0)
                    {
                        nr=0;
                    if(board[x-1][y+1].has_bomb)
                        nr++;
                    if(board[x][y+1].has_bomb)
                        nr++;
                    if(board[x-1][y].has_bomb)
                        nr++;
                        cout<< nr<<"|";
                    }
                    else if(x==0&&y==9)
                    {
                        nr=0;
                    if(board[x][y-1].has_bomb)
                        nr++;
                    if(board[x+1][y].has_bomb)
                        nr++;
                    if(board[x+1][y-1].has_bomb)
                        nr++;
                        cout<< nr<<"|";
                    }
                    else if(x==9&&y==9)
                    {
                        nr=0;
                    if(board[x][y-1].has_bomb)
                        nr++;
                    if(board[x-1][y].has_bomb)
                        nr++;
                    if(board[x-1][y-1].has_bomb)
                        nr++;
                        cout<< nr<<"|";
                    }
			}
			else
			{
				cout << "_|";
			}
		}
		cout << endl;
	}
}

int main()
{
    srand(time(NULL));
	lose = false;
	numar_bombe = 10;
	verifx = 0;
	verify = 0;
	Grid gameboard[sizex][sizey];
	for (int i = 0; i < numar_bombe; i++)
	{

		int xpos = rand() % 10+1;
		int ypos = rand() % 10+1;
		if (gameboard[xpos][ypos].has_bomb == false) {
			gameboard[xpos][ypos].has_bomb = true;
		}
		else
		{
			i--;
		}
	}
	drawBoad(gameboard);
	cout << endl;
	while (lose != true)
	{

		cout << "Input x grid to check." << endl;
		cin >> verifx;
		while (verifx>9||verifx<0)
{
            cout<<"Input x grid again!"<<endl;
            cin>>verifx;
		}
		cout << endl << "Input y grid to check." << endl;
		cin >> verify;

		while (verify>9||verify<0)
        {
            cout<<"Input y grid again!"<<endl;
            cin>>verify;
		}
		if (gameboard[verifx][verify].has_bomb == true) {
			cout << "Boom!";
			lose = true;
		}
		else {
			cout << "Continue!" << endl;
		}
		gameboard[verifx][verify].marked = true;

		cout << endl;
		drawBoad(gameboard);
		cout << endl;
		int i=0,ok=1;
		while(i<=9&&ok)
        {
            for(int j=0;j<=9;j++)
                if(!(gameboard[i][j].marked))
                    if(!(gameboard[i][j].has_bomb))
                        ok=0;
            i++;
        }
        if(ok)
        {

            cout<<"Felicitari!";
            lose=true;
        }

	}

	return 0;
}
