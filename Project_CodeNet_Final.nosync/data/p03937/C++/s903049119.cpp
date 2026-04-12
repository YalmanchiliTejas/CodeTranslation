#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <ctime>
#include <stdio.h>
#include <memory.h>
#include <sstream>
#include <iterator>
bool used[9][9];
char map[9][9];
int n, m;
void dfs (int x, int y) {
	used[x][y] = true;
	if (x + 1 < n && map[x + 1][y] == '#')
		dfs (x + 1, y);
	else if (y + 1 < m && map[x][y + 1] == '#')
		dfs(x, y + 1);
}
int main ()
{
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> map[i][j];
	dfs (0, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == '#' && used[i][j] == false)
			{
				std::cout << "Impossible";
				return 0;
			}
	std::cout << "Possible";
}