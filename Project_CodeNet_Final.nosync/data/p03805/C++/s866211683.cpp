#include <bits/stdc++.h>

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VD = vector<double>;
using VVD = vector<VD>;
using VS = vector<string>;
using PII = pair<int, int>;
using VPII = vector<PII>;
using VL = vector<long long>;
using VVL = vector<VL>;

#define sz(var) (int)var.size()
#define REP(var, start, end) for(int var = start; var < (int)end; ++var)
#define CLEAR(var, with) memset(var, with, sizeof(var))
#define ALL(x) x.begin(), x.end()
#define LL long long
#define ULL unsigned long long
#define TIME cout << "Time elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << endl;

int n, m;
VVI adj;
int pathCount(int here, VB visited)
{
	visited[here] = true;
	if(count(ALL(visited), true) == n)
		return 1;

	int ret = 0;
	for(auto there : adj[here])
		if(!visited[there])
			ret += pathCount(there, visited);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	//freopen("tmp.in", "r", stdin);
//	freopen("tmp.out", "w", stderr);
#endif
	cin >> n >> m;

	adj = VVI(n);
	VB visited(n, false);
	int u, v;
	for(int i = 0; i < m; ++i)
	{
		cin >> u >> v;
		--u; --v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}

	cout << pathCount(0, visited) << endl;

	return 0;
}