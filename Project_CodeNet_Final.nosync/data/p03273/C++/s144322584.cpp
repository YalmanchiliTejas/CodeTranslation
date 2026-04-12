#include <iostream>
#include <cstring>

using namespace std;

int h, w;
char grid[101][101];
bool check[101][101];
bool erasedJ[101];
bool erasedI[101];


int main()
{
	memset(check, true, sizeof(check));
	memset(check, false, sizeof(erasedJ));
	memset(check, false, sizeof(erasedI));

	scanf("%d %d", &h, &w);

	for (int j = 1; j <= h; ++j)
		for (int i = 1; i <= w; ++i)
			scanf("\n%c", &grid[j][i]);

	for (int j = 1; j <= h; ++j)
	{
		bool canErase = true;
		for (int i = 1; i <= w; ++i)
		{
			if (grid[j][i] == '#')
			{
				canErase = false;
				break;
			}
		}
		if (canErase)
		{
			for (int i = 1; i <= w; ++i)
				check[j][i] = false;
			erasedJ[j] = true;
		}


	}

	for (int i = 1; i <= w; ++i)
	{
		bool canErase = true;
		for (int j = 1; j <= h; ++j)
		{
			if (grid[j][i] == '#')
			{
				canErase = false;
				break;
			}
		}
		if (canErase)
		{
			for (int j = 1; j <= h; ++j)
				check[j][i] = false;
			erasedI[i] = true;
		}


	}

	for (int j = 1; j <= h; ++j)
	{
		if (erasedJ[j])
			continue;

		for (int i = 1; i <= w; ++i)
		{
			if (erasedI[i])
				continue;

			if (check[j][i] == true)
				cout << grid[j][i];
		}


		cout << endl;
	}
		
}