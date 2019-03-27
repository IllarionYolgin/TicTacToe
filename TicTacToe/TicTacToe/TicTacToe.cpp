// TicTacToe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

class Game 
{
	int x, y;
	char Array[3][3];
public:
	Game() 
	{
		x = 0;
		y = 0;
		for (int i = 0; i < 3;i++)
			for (int j = 0; j < 3; j++)
			{
				Array[i][j] = ' ';
			}

	}
	~Game() {}
	void ShowDesk()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << Array[i][j];
				if (j < 3) cout << '|';
			}
			cout << endl;
			for (int i = 0; i < 6; i++)
				if (i % 2 == 0) cout << '-';
				else cout << '+';
			cout << endl;
		}
	}
	void GetTurn()
	{
		do
		{
			do
			{
				cout << "x=";
				cin >> x;
				x--;
			} while (!IsOnBroad(x));
			do
			{
				cout << "y=";
				cin >> y;
				y--;
			} while (!IsOnBroad(y));
		} while (!IsFree());
	}
	void SetX() 
	{ 
		GetTurn();
		Array[y][x] = 'x'; 
	}
	void SetO() 
	{ 
		GetTurn(); 
		Array[y][x] = 'o';
	}
	bool IsFree()
	{
		if (Array[x][y] != ' ') cout <<"Cell is not free"<<endl;
		return (Array[x][y] == ' ');
	}
	bool IsOnBroad(int iInside)
	{
		if (!((iInside < 3) and (iInside >= 0))) cout << "Out of broad" << endl;
		return ((iInside<3) and (iInside>=0));
	}
	void WinCheck(char Key)
	{
		int count(0);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (Array[i][j] != Key)
				{
					count = 0;
					break;
				}
				count++;
			}
			if (count == 3)
			{
				cout << "Win " << Key << endl;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (Array[j][i] != Key)
				{
					count = 0;
					break;
				}
				count++;
			}
			if (count == 3)
			{
				cout << "Win " << Key << endl;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (Array[i][i] != Key)
			{
				count = 0;
				break;
			}
			count++;
			if (count == 3)
			{
				cout << "Win " << Key << endl;
			}
		}
		for (int i = 0; i <3; i++)
		{
			if (Array[i][2-i] != Key)
			{
				count = 0;
				break;
			}
			count++;
			if (count == 3)
			{
				cout << "Win " << Key << endl;
			}
		}
	}
	void Start() 
	{
		for (int i = 0; i < 9; i++)
		{
			ShowDesk();
			if (i % 2 == 0)
			{
				SetX();
				WinCheck('x');
			}
			if (i % 2 == 1)
			{
				SetO();
				WinCheck('o');
			}
		}
	}
};

int main()
{
	Game Broad;
	Broad.Start();
}