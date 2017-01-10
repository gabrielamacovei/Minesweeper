#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>

//#include <stdio.h>      /* printf, NULL */
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
			/*if (board[x][y].has_bomb && board[x][y].marked)
			{
                cout << "!|";
			}*/
			if (board[x][y].has_bomb)
			{
				if(board[x][y].marked)
                    {cout << "!|";
                    }
                else
				cout << "b|";
			}
				else if (board[x][y].marked)
			{
				cout << "x|";
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
		cout << endl << "Input y grid to check." << endl;
		cin >> verify;
		if (gameboard[verifx - 1][verify - 1].has_bomb == true) {
			cout << "Boom!";
			lose = true;
		}
		else {
			cout << "Try again." << endl;
		}
		gameboard[verifx - 1][verify - 1].marked = true;

		cout << endl;
		drawBoad(gameboard);
		cout << endl;
	}

	return 0;
}
