
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
int main() {

	char a;
	int H, W;
	char A[100][100] = { 0 };
	cin >> H >> W;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> a;
			A[i][j] = a;
		}

	}

	

	for (int i = 0; i < H; i++)
	{
		int count = 0;

		for (int j = 0; j < W; j++)
		{
			if (A[i][j] == '.' || A[i][j] == '*' )
			{
				count++;
			}

		}

		if (W == count)
		{
			for (int j = 0; j < W; j++)
			{
				if (A[i][j] == '.')
				{
					A[i][j] = '*';
				}
			}

		}
	}

	for (int j = 0; j < W; j++)
	
	{
		int count = 0;

		for (int i = 0; i < H; i++)
		{
			if (A[i][j] == '.' || A[i][j] == '*')
			{
				count++;
			}

		}

		if (H == count)
		{
			for (int i = 0; i < H; i++)
			{
				if (A[i][j] == '.')
				{
					A[i][j] = '*';
				}
			}

		}
	}
	
	for (int i = 0; i < H; i++)
	{
		bool f = false;
		for (int j = 0; j < W; j++)
		{
			if ( A[i][j] != '*')
			{
				cout << A[i][j];
				f = true;
			}
		}
		if( f )
			cout << endl;
	}

	
}