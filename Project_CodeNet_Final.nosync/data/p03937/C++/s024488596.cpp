
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

int h, w;
int a[10][10];

bool answer = true;
void dfs(int x,int y)
{
	a[x][y] = 0;
	if (x == h - 1 && y == w - 1)return;
	bool nex1 = a[x + 1][y];
	bool nex2 = a[x][y + 1];
	if (nex1 ^ nex2)
	{
		if (nex1)
		{
			dfs(x + 1, y);
		}
		else
		{
			dfs(x, y + 1);
		}
	}
	else
	{
		answer = false;
		return;
	}
}

int main(void)
{
	scanf("%d %d", &h, &w);
	memset(a, 0, sizeof(a));
	for (int i = 0; i < h; ++i)
	{
		char s[10];
		scanf("%s", s);
		for (int j = 0; j < w; ++j)
		{
			a[i][j] = s[j] == '.' ? 0 : 1;
		}
	}
	dfs(0, 0);

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (a[i][j] == 1)answer = false;
		}
	}
	if(answer)printf("Possible\n");
	else printf("Impossible\n");
	return 0;
}
