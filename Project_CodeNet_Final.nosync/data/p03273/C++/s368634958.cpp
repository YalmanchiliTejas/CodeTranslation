#include"bits/stdc++.h"

using namespace std;

char a[100][100];

bool ok_H[100];
bool ok_W[100];

int main()
{
	int H, W;
	cin >> H >> W;
	
	char c;

	for (int i = 0; i < H; i++)
	{
		bool allwhite = true;
		for (int j = 0; j < W; j++)
		{
			cin >> c;
			if (c == '#')
			{
				allwhite = false;
			}
			a[i][j] = c;
		}
		
		ok_H[i] = !allwhite;
	}

	for (int j = 0; j < W; j++)
	{
		bool allwhite = true;
		for (int i = 0; i < H; i++)
		{
			if (a[i][j] == '#')
			{
				allwhite = false;
				break;
			}
		}
		
		ok_W[j] = !allwhite;
	}

	for (int i = 0; i < H; i++)
	{
		if (ok_H[i])
		{
			for (int j = 0; j < W; j++)
			{
				if(ok_W[j]) cout << a[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}