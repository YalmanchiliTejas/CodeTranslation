#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <functional>
#include <ctime>
#include <random>

using namespace std;

#if _DEBUG
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

const int MAXN = 1010;
int n, m, in, k, x, y;
char a[10][10];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == '#')
				k++;
		}
	}
	if (a[x][y] != '#')
	{
		cout << "Impossible";
		return 0;
	}
	k--;
	while (true)
	{
		if (a[x][y + 1] == '#')
		{
			y++;
			k--;
			continue;
		}
		if (a[x + 1][y] == '#')
		{
			x++;
			k--;
			continue;
		}
		break;
	}
	if (x != n - 1 || y != m - 1 || k != 0)
	{
		cout << "Impossible";
	}
	else
	{
		cout << "Possible";
	}
	return 0;
}