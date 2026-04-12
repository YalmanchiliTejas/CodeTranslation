#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <time.h>
#include <assert.h>
#include <cmath>
#include <stack>
#include <string.h>
#include <sstream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 100000;
const int M = 1000000007;
int n, m, s, t;
vector<vector<pair<int, int> > > g;
vector<int> p[N];
vector<vector<int> > lg, rg;
ll cost[N];
ll len;
bool vis[N];
int dp[2][N];
void Dijkstra() {
	priority_queue<pair<ll, int> > q;
	q.push({ 0,s });
	for (int i = 0; i < n; ++i)
		cost[i] = 1e18;
	cost[s] = 0;
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = true;
		for (int i = 0; i < g[u].size(); ++i) {
			int v = g[u][i].first;
			if (vis[v])
				continue;
			ll cst = cost[u] + g[u][i].second;
			if (cost[v] == cst)
				p[v].push_back(u);
			else if (cost[v] > cst) {
				p[v].clear();
				p[v].push_back(u);
				cost[v] = cst;
				q.push({ -cst,v });
			}
		}
	}
}
void buildGraphs(int u) {
	if (u == s)
		return;
	if (vis[u])
		return;
	vis[u] = true;
	for (int i = 0; i < p[u].size(); ++i) {
		int a = p[u][i];
		int b = u;
		lg[a].push_back(b);
		rg[b].push_back(a);
		buildGraphs(a);
	}
}
int calc(int u, bool f) {
	if (!f && u == t)
		return 1;
	if (f && u == s)
		return 1;
	int &ret = dp[f][u];
	if (ret != -1)
		return ret;
	ret = 0;
	if (!f) {
		for (int i = 0; i < lg[u].size(); ++i) {
			ret += calc(lg[u][i], f);
			if (ret >= M)
				ret -= M;
		}
	}
	else {
		for (int i = 0; i < rg[u].size(); ++i) {
			ret += calc(rg[u][i], f);
			if (ret >= M)
				ret -= M;
		}
	}
	return ret;
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &t);
	--s; --t;
	g.resize(n);
	for (int i = 0, a, b, c; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		--a; --b;
		g[a].push_back({ b,c });
		swap(a, b);
		g[a].push_back({ b,c });
	}
	Dijkstra();
	lg.resize(n);
	rg.resize(n);
	len = cost[t];
	memset(vis, 0, sizeof(vis));
	buildGraphs(t);
	memset(dp, -1, sizeof(dp));
	ll res = calc(s, false);
	calc(t, true);
	res = ((ll)res*res % M + M) % M;
	for (int i = 0; i < n; ++i) {
		if (cost[i] * 2 == len) {
			ll cur = (ll)calc(i, true)*calc(i, false) % M;
			res -= cur*cur%M;
			res = ((ll)res%M + M) % M;
		}
		for (int j = 0; j < lg[i].size(); ++j) {
			int u = i;
			int v = lg[i][j];
			if (cost[u] < (len + 1) / 2 && len - cost[v] < (len + 1) / 2) {
				ll cur= (ll)calc(u, true)*calc(v, false) % M;
				res -= cur*cur%M;
				res = ((ll)res%M + M) % M;
			}
		}
	}
	printf("%lld\n", res);
	return 0;
}