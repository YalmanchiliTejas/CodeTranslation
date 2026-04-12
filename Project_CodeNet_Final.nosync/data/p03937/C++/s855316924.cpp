#include<stdio.h>
#include<vector>
#include<algorithm>
int map[100][100];
int main()
{
	int mx, my;
	scanf("%d%d", &mx, &my);
	int c = 0;
	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			char z;
			scanf(" %c", &z);
			if (z == '#')map[i][j] = 1, c++;;
		}
	}
	int x = 0, y = 0;
	bool f = false;
	for (;;)
	{
		if (x == mx - 1 && y == my - 1)
		{
			f = true;
			break;
		}
		if (map[x + 1][y] + map[x][y + 1] == 1)
		{
			if (map[x + 1][y])x++;
			else y++;
		}
		else break;
	}
	if (f && (c == mx + my - 1))printf("Possible\n");
	else printf("Impossible\n");
}