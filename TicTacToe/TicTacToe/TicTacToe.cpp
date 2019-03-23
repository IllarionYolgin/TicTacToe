// TicTacToe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

class Desk 
{
	char Array[3][3];
public:
	Desk() 
	{
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
	void SetX() 
	{ 
		cout << "x="; 
		int x = 1; 
		int y = 1; 
		cin >> x; 
		cout << "y="; 
		cin >> y; 
		Array[y - 1][x - 1] = 'x'; 
	}
	void SetO() 
	{ 
		cout << "x="; 
		int x = 1; 
		int y = 1; 
		cin >> x; 
		cout << "y="; 
		cin >> y; 
		Array[y - 1][x - 1] = 'o';
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