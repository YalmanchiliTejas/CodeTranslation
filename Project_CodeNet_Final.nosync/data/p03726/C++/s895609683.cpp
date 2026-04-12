#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

const int MAXN = 100000 + 10000;

int n, m = 0;
vector<int> edg[MAXN];

bool dfs(int x, int fa)
{
	bool ret = false;
	for(int i = 0; i < edg[x].size(); i++)
		if(edg[x][i] != fa)
			if(!dfs(edg[x][i], x) && !ret)
				ret = true, m++;
	// cerr << x << ' ' << ret << endl;
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		edg[x].push_back(y), edg[y].push_back(x);
	}

	dfs(1, 0);
	if(2 * m == n)
		cout << "Second" << endl;
	else
		cout << "First" << endl;


	return 0;
}
