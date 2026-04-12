#include <iostream>
#include <string>

using namespace std;

struct Dice
{
	int top;
	int bottom;
	int north;
	int east;
	int west;
	int south;
};

void init(Dice& dice)
{
	dice.top = 1;
	dice.bottom = 6;
	dice.north = 5;
	dice.east = 3;
	dice.west = 4;
	dice.south = 2;
}

int North(Dice& dice)
{
	int temp = dice.top;
	dice.top = dice.south;
	dice.south = dice.bottom;
	dice.bottom = dice.north;
	dice.north = temp;
	return(dice.top);
}

int East(Dice& dice)
{
	int temp = dice.top;
	dice.top = dice.west;
	dice.west = dice.bottom;
	dice.bottom = dice.east;
	dice.east = temp;
	return(dice.top);
}

int West(Dice& dice)
{
	int temp = dice.top;
	dice.top = dice.east;
	dice.east = dice.bottom;
	dice.bottom = dice.west;
	dice.west = temp;
	return(dice.top);
}

int South(Dice& dice)
{
	int temp = dice.top;
	dice.top = dice.north;
	dice.north = dice.bottom;
	dice.bottom = dice.south;
	dice.south = temp;
	return(dice.top);
}

int Right(Dice& dice)
{
	int temp = dice.north;
	dice.north = dice.west;
	dice.west = dice.south;
	dice.south = dice.east;
	dice.east = temp;
	return(dice.top);
}

int Left(Dice& dice)
{
	int temp = dice.north;
	dice.north = dice.east;
	dice.east = dice.south;
	dice.south = dice.west;
	dice.west = temp;
	return(dice.top);
}

void solve()
{
	int n;
	while (cin >> n, n)
	{
		int ans = 1;
		Dice dice;
		init(dice);
		for (int i = 0; i < n; ++i)
		{
			string command;
			cin >> command;
			if (command == "North")
			{
				ans += North(dice);
			}
			else if (command == "East")
			{
				ans += East(dice);
			}
			else if (command == "West")
			{
				ans += West(dice);
			}
			else if (command == "South")
			{
				ans += South(dice);
			}
			else if (command == "Right")
			{
				ans += Right(dice);
			}
			else if (command == "Left")
			{
				ans += Left(dice);
			}
		}
		cout << ans << endl;
	}
}

int main()
{
	solve();
	return(0);
}