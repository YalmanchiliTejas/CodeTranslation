#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 0-indexed
struct dsu {
	int n; // number of connected components
	vector<int> par;
	vector<int> sz;

	dsu(int _n) : n(_n), par(n, -1), sz(n, 1) { }

	int getpar(int a) {
		return par[a] == -1 ? a : (par[a] = getpar(par[a]));
	}

	bool merge(int a, int b) {
		a = getpar(a);
		b = getpar(b);
		if (a == b) return false;
		n--;
		if (sz[a] < sz[b]) swap(a, b);
		par[b] = a;
		sz[a] += sz[b];
		return true;
	}
};

// edge_t is something like pair<weight, pair<a, b>>
template <typename edge_t> ll mst(int n, vector<edge_t> edges) {
	sort(edges.begin(), edges.end());
	dsu conn(n);
	ll res = 0;
	for (const auto& e : edges) {
		int a, b; tie(a, b) = e.second;
		if (conn.merge(a, b)) {
			res += e.first;
		}
	}
	return res;
}

const int MAXN = 2e5;
int N;
int P[MAXN][2];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i][0] >> P[i][1];
	}

	vector<pair<int, pair<int, int>>> edges;
	for (int z = 0; z < 2; z++) {
		vector<int> ord(N);
		iota(ord.begin(), ord.end(), 0);
		sort(ord.begin(), ord.end(), [&](int i, int j) {
			return P[i][z] < P[j][z];
		});
		for (int i = 0; i+1 < N; i++) {
			edges.push_back({P[ord[i+1]][z] - P[ord[i]][z], {ord[i], ord[i+1]}});
		}
	}

	cout << mst(N, edges) << '\n';

	return 0;
}
