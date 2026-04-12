#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <iostream>
#include <climits>
#include <cfloat>

using namespace std;

int main()
{
	while (true)
	{
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;

		int square[15][15];
		memset(square, 0, sizeof(square));
		int x, y;
		x = n/2;
		y = n/2 + 1;
		for (int i = 1; i <= n*n; ++i)
		{
			if (square[y][x])
			{
				x = (x-1+n) % n;
				y = (y+1+n) % n;
			}
			square[y][x] = i;
			x = (x+1) % n;
			y = (y+1) % n;
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
				printf("% 4d", square[i][j]);
			printf("\n");
		}
	}

	return 0;
}