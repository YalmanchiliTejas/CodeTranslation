#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<ll, ll>;
using vi = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

constexpr int INF = 2000000000;
constexpr ll LLINF = 9000000000000000000;

struct UnionFind {
	vi par, rank, size; int c;
	UnionFind(int n) : par(n), rank(n,0), size(n,1), c(n) {
		for (int i = 0; i < n; ++i) par[i] = i;
	}

	int find(int i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
	bool same(int i, int j) { return find(i) == find(j); }
	int get_size(int i) { return size[find(i)]; }
	int count() { return c; }

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		c--;
		if (rank[i] > rank[j]) swap(i, j);
		par[i] = j; size[j] += size[i];
		if (rank[i] == rank[j]) rank[j]++;
	}
};

// Edges are given as (weight, (u, v)) triples.
struct E {int u, v; ll weight;};
bool operator<(const E &l, const E &r){return l.weight < r.weight;}
ll kruskal(vector<E> &edges, int V) {
	sort(edges.begin(), edges.end());
	ll cost = 0;
	int count = 0;
	UnionFind uf(V);
	for (auto &e : edges) {
		if (!uf.same(e.u, e.v)) {
			// (w, (u, v)) is part of the MST
			cost += e.weight;
			uf.merge(e.u, e.v);
			if ((++count) == V - 1) break;
		}
	}
	return cost;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	vii byx(N, {0, 0}), byy(N, {0, 0});
	for (int i = 0; i < N; ++i) {
		cin >> byx[i].first >> byy[i].first;
		byx[i].second = byy[i].second = i;
	}
	
	sort(byx.begin(), byx.end());
	sort(byy.begin(), byy.end());
	
	vector<E> edges;
	for (int i = 0; i + 1 < N; ++i)
		edges.push_back({
			(int)byx[i].second,
			(int)byx[i+1].second, 
			byx[i+1].first - byx[i].first});
	for (int i = 0; i + 1 < N; ++i)
		edges.push_back({
			(int)byy[i].second,
			(int)byy[i+1].second, 
			byy[i+1].first - byy[i].first});
	
	cout << kruskal(edges, N) << endl;
	
	return 0;
}
