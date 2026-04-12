#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<int, P> E;
const LL MOD = 1000000007LL;
int x[100000];
int y[100000];
vector<E> edge;
struct UnionFind {
	int *par;
	int *rank;
	int size;
	UnionFind(int n) :size(n) {
		par = new int[n];
		rank = new int[n];
		for (int i = 0; i < n; i++) {
			par[i] = i;
			rank[i] = 0;
		}
	}
	int find(int x) {
		if (x == par[x]) return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (rank[x] < rank[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};
int main() {
	int N;
	cin >> N;
	vector<P> vx, vy;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
		vx.emplace_back(x[i], i);
		vy.emplace_back(y[i], i);
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	for (int i = 0; i + 1 < N; i++) {
		edge.emplace_back(vx[i + 1].first - vx[i].first, P(vx[i].second, vx[i + 1].second));
		edge.emplace_back(vy[i + 1].first - vy[i].first, P(vy[i].second, vy[i + 1].second));
	}
	sort(edge.begin(), edge.end());
	UnionFind U(N);
	LL ans = 0;
	for (int i = 0; i < edge.size(); i++) {
		if (U.same(edge[i].second.first, edge[i].second.second)) continue;
		ans += edge[i].first;
		U.unite(edge[i].second.first, edge[i].second.second);
	}
	cout << ans << endl;
}