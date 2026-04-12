#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;

bool graph[8][8];
int ans;
int n, m;
bool reached[8];
int dfs(int x)
{
	bool allReached = true;
	for (int i = 0; i < n; i++) {
		if (!reached[i])
			allReached = false;
	}

	if (allReached)
		return 1;

	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (!graph[x][i])
			continue;
		if (reached[i])
			continue;

		reached[i] = true;
		ret += dfs(i);
		reached[i] = false;
	}

	return ret;

}

int main()
{

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
	}


	for (int i = 0; i < n; i++) {
		reached[i] = false;
	}
	reached[0] = true;
	cout << dfs(0) << endl;

	return 0;

}