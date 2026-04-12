#include <iostream>
#include <vector>
#include <algorithm>

#define int long long
#define MAXN 200000

int par[MAXN];

int root(int u) {
	if(par[u] < 0)
		return u;

	return par[u] = root(par[u]);
}

void merge(int u, int v) {
	u = root(u); v = root(v);
	if(u == v)
		return;

	if(par[u] > par[v])
		u ^= v ^= u ^= v;

	par[u] += par[v];
	par[v] = u;
}

signed main() {
	int n;
	std::cin >> n;

	std::pair<int, int> helpx[n], helpy[n];

	for(int i = 0; i < n; i++) {
		par[i] = -1;
		int x, y;
		std::cin >> x >> y;
		helpx[i] = {x, i};
		helpy[i] = {y, i};
	}

	std::sort(helpx, helpx+n);
	std::sort(helpy, helpy+n);

	std::vector<std::pair<int, std::pair<int, int> > > edges;

	for(int i = 1; i < n; i++) {
		edges.push_back({helpx[i].first - helpx[i-1].first, {helpx[i].second, helpx[i-1].second}});
		edges.push_back({helpy[i].first - helpy[i-1].first, {helpy[i].second, helpy[i-1].second}});
	}

	std::sort(edges.begin(), edges.end());

	int ans = 0;
	
	for(int i = 0; i < edges.size(); i++) {
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		int w = edges[i].first;

		if(root(u) != root(v))
			ans += w;

		merge(u, v);
	}

	std::cout << ans << std::endl;

	return 0;
}

