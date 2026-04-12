#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 10;

bool used[MAX_N];
int n;
vector<int> G[MAX_N];

void add_edge(int s, int t){
	G[s].push_back(t);
	G[t].push_back(s);
}

int dfs(int v) {
	bool tf = true;
	used[v] = true;
	for (int i = 0; i < n && tf; ++i)
	{
		if (used[i]==false) tf = false;
	}
	if (tf) return 1;

	int ans = 0;

	for (int i = 0; i < G[v].size(); ++i)
	{
		int u = G[v][i];
		if (used[u]) continue;
		ans += dfs(u);
		used[u] = false;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		add_edge(a, b);
	}

	fill(used, used + n, 0);

	cout << dfs(0) << endl;

	return 0;
}