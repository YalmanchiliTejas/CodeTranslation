#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MOD (int)(1e9+7)
#define INF 1e9+1;

struct UnionFind
{
	vector<int> par;
	vector<int> sizes;

	UnionFind(int n) : par(n), sizes(n, 1) {
		for (int i = 0; i < n; i++) par[i] = i;
	}

	int find(int x) {
		if (x == par[x])return x;
		return par[x] = find(par[x]);
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y) return;

		if (sizes[x] < sizes[y]) swap(x, y);

		par[y] = x;
		sizes[x] += sizes[y];
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	int size(int x) {
		return sizes[find(x)];
	}
};

int main()
{
	int N; cin >> N;
	vector<pair<int, int>>X(N),Y(N);
	vector<pair<int,pair<int,int>>>dist;

	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		X[i] = make_pair(x, i);
		Y[i] = make_pair(y, i);
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());

	for (int i = 0; i < N; i++) {
		if (i > 0) {
			dist.push_back(make_pair(X[i].first - X[i - 1].first, make_pair(X[i].second, X[i - 1].second)));
			dist.push_back(make_pair(Y[i].first - Y[i - 1].first, make_pair(Y[i].second, Y[i - 1].second)));
		}
		if (i < N - 1) {
			dist.push_back(make_pair(X[i + 1].first - X[i].first, make_pair(X[i].second, X[i + 1].second)));
			dist.push_back(make_pair(Y[i + 1].first - Y[i].first, make_pair(Y[i].second, Y[i + 1].second)));
		}
	}

	sort(dist.begin(), dist.end());

	long long ans = 0;
	UnionFind un(N);
	for (int i = 0; i < dist.size(); i++) {
		if (un.same(dist[i].second.first, dist[i].second.second))continue;

		un.unite(dist[i].second.first, dist[i].second.second);

		ans += dist[i].first;

		if (un.size(0) == N)break;
	}

	cout << ans << endl;

    return 0;
}

