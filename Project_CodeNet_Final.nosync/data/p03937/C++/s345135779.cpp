#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <bitset>
#include <algorithm>
#include <string>
#include <fstream>
#include <assert.h>
#include <list>
#include <cstring>
#include <numeric>
using namespace std;

const int N = 100;

char c[N][N];

int dfs(int x, int y)
{
	if (c[x + 1][y] == '#')
		return dfs(x + 1, y) + 1;
	if (c[x][y + 1] == '#')
		return dfs(x, y + 1) + 1;
	return 1;
}

int main()
{
	int h, w;
	cin >> h >> w;
	int cnt = 0;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			cin >> c[i][j],
			cnt += (c[i][j] == '#');
	int cnt2 = c[0][0] == '#' ? dfs(0, 0) : 0;
	if (cnt2 == cnt && c[h - 1][w - 1] == '#')
		cout << "Possible";
	else
		cout << "Impossible";
	
	return 0;
}