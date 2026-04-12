#include <iostream>
using namespace std;

int dice[6];

void North()
{
	int d[6];
	d[0] = dice[1];
	d[1] = dice[5];
	d[5] = dice[3];
	d[3] = dice[0];
	d[2] = dice[2];
	d[4] = dice[4];
	for ( int i = 0; i < 6; ++i )
		dice[i] = d[i];
}

void East()
{
	int d[6];
	d[0] = dice[4];
	d[4] = dice[5];
	d[5] = dice[2];
	d[2] = dice[0];
	d[1] = dice[1];
	d[3] = dice[3];
	for ( int i = 0; i < 6; ++i )
		dice[i] = d[i];
}

void West()
{
	int d[6];
	d[0] = dice[2];
	d[2] = dice[5];
	d[5] = dice[4];
	d[4] = dice[0];
	d[1] = dice[1];
	d[3] = dice[3];
	for ( int i = 0; i < 6; ++i )
		dice[i] = d[i];
}

void South()
{
	int d[6];
	d[0] = dice[3];
	d[3] = dice[5];
	d[5] = dice[1];
	d[1] = dice[0];
	d[2] = dice[2];
	d[4] = dice[4];
	for ( int i = 0; i < 6; ++i )
		dice[i] = d[i];
}

void Right()
{
	int d[6];
	d[1] = dice[2];
	d[2] = dice[3];
	d[3] = dice[4];
	d[4] = dice[1];
	d[0] = dice[0];
	d[5] = dice[5];
	for ( int i = 0; i < 6; ++i )
		dice[i] = d[i];
}

void Left()
{
	int d[6];
	d[1] = dice[4];
	d[4] = dice[3];
	d[3] = dice[2];
	d[2] = dice[1];
	d[0] = dice[0];
	d[5] = dice[5];
	for ( int i = 0; i < 6; ++i )
		dice[i] = d[i];
}

int main( void )
{
	while (1)
	{
		dice[0] = 1;
		dice[1] = 2;
		dice[2] = 3;
		dice[3] = 5;
		dice[4] = 4;
		dice[5] = 6;

		int answer = 1;
		int n;
		cin >> n;

		if ( n == 0 )
			break;

		for ( int i = 0; i < n; ++i )
		{
			string o;
			cin >> o;

			if ( o[0] == 'N' )
				North();
			else if ( o[0] == 'E' )
				East();
			else if ( o[0] == 'W' )
				West();
			else if ( o[0] == 'S' )
				South();
			else if ( o[0] == 'R' )
				Right();
			else if ( o[0] == 'L' )
				Left();

			answer += dice[0];
		}

		cout << answer << endl;
	}

	return 0;
}