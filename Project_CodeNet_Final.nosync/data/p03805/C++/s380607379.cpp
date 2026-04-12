#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>
#include <map>
#include <stack>
#include <sstream>
#include <set>
#include <cmath>
#include <functional>

using namespace std;
int res = 0;
vector <vector <int>> adj(9);
int n;
void dfs(int i, vector <bool> visited)
{
	visited[i] = true;

	bool flag = false;
	for (auto iter : adj[i])
	{
		if (visited[iter] == false)
		{
			flag = true;
			dfs(iter, visited);
		}
	}

	if (flag == false)
	{
		for (int i = 1; i <= n; i++)
		{
			if (visited[i] == false)
			{
				return;
			}
		}
		res++;
		return;
	}
}
int main(void)
{
	int m, a, b;
	vector <bool> visited(9, false);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, visited);
	cout << res << endl;
	return 0;
}