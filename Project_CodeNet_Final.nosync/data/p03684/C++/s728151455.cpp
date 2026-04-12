#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
typedef pair<ll, ll> P;
typedef pair<ll, P> E;
struct UnionFind {
	vector<int> par;
	vector<int> rank;
	vector<int> cmp;
	int size;
	UnionFind(int n) :size(n) {
		par.resize(size);
		rank.resize(size);
		cmp.resize(size);
		for (int i = 0; i < size; i++) {
			par[i] = i;
			rank[i] = 0;
			cmp[i] = 1;
		}
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (rank[x] < rank[y]) {
			par[x] = y;
			cmp[y] += cmp[x];
		}
		else {
			par[y] = x;
			cmp[x] += cmp[y];
			if (rank[x] == rank[y]) rank[x]++;
		}
	}
	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}
	bool same(int x, int y) {
		x = find(x);
		y = find(y);
		return x == y;
	}
};
int main() {
	int N;
	cin >> N;
	vector<P> vx, vy;
	for (int i = 0; i < N; i++) {
		ll x, y;
		cin >> x >> y;
		vx.emplace_back(x, i);
		vy.emplace_back(y, i);
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	priority_queue<E, vector<E>, greater<E>> Q;
	for (int i = 1; i < N; i++) {
		Q.push(E(vx[i].first - vx[i - 1].first, P(vx[i].second, vx[i - 1].second)));
		Q.push(E(vy[i].first - vy[i - 1].first, P(vy[i].second, vy[i - 1].second)));
	}
	UnionFind U(N);
	ll ans = 0;
	while (!Q.empty()) {
		E e = Q.top(); Q.pop();
		if (!U.same(e.second.first, e.second.second)) {
			ans += e.first;
			U.unite(e.second.first, e.second.second);
		}
	}
	cout << ans << endl;
 }