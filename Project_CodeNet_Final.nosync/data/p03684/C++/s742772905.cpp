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

struct DisjointSet
{
	VI parent, rank;
	DisjointSet(int n) : parent(n), rank(n, 1)
	{
		for(int i = 0; i < n; ++i)
			parent[i] = i;
	}
	int find(int u)
	{
		if(parent[u] == u)
			return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v)
	{
		u = find(u), v = find(v);
		if(u == v) return;

		if(rank[u] > rank[v]) swap(u, v);

		parent[u] = v;
		if(rank[v] == rank[u])
			++rank[v];
	}
};

int n;
VPII X, Y;
LL kruskal(vector<pair<LL, PII>>& edges)
{
	LL ret = 0;
	sort(ALL(edges));

	DisjointSet ds(n);
	for(int i = 0; i < sz(edges); ++i)
	{
		LL cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		if(ds.find(u) == ds.find(v))
			continue;
		
		ds.merge(u, v);
		ret += cost;
	}
	return ret;
}

LL minCost()
{
	sort(ALL(X));
	sort(ALL(Y));

	vector<pair<LL, PII>> edges;
	for(int i = 1; i < n; ++i)
	{
		LL cost = abs(X[i - 1].first - X[i].first);
		int u = X[i - 1].second, v = X[i].second;
		edges.emplace_back(pair<LL, PII>(cost, PII(u, v)));

		cost = abs(Y[i - 1].first - Y[i].first);
		u = Y[i - 1].second, v = Y[i].second;
		edges.emplace_back(pair<LL, PII>(cost, PII(u, v)));
	}
	
	return kruskal(edges);	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("tmp.in", "r", stdin);
//	freopen("tmp.out", "w", stderr);
#endif
	cin >> n;

	X = Y = VPII(n);
	for(int i = 0; i < n; ++i)
	{
		X[i].second = Y[i].second = i;
		cin >> X[i].first >> Y[i].first;
	}

	cout << minCost() << endl;
	return 0;
}