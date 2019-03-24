// TicTacToe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

class Desk 
{
	int x, y;
	char Array[3][3];
public:
	Desk() 
	{
		x = 0;
		y = 0;
		for (int i = 0; i < 3;i++)
			for (int j = 0; j < 3; j++)
			{
				Array[i][j] = ' ';
			}

	}
	~Desk() {}
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
		if (!(Array[x][y] == ' ')) cout <<"Cell is not free"<<endl;
		return (Array[x][y] == ' ');
	}
	bool IsOnBroad(int iInside)
	{
		if (!((iInside < 3) and (iInside >= 0))) cout << "Out of broad" << endl;
		return ((iInside<3) and (iInside>=0));
	}

};

int main()
{
	Desk Broad;
	Broad.ShowDesk();
	Broad.SetX();
	Broad.ShowDesk();
	Broad.SetO();
	Broad.ShowDesk();
}