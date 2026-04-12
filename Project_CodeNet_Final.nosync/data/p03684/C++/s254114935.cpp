#include <bits/stdc++.h>
using namespace std;
//#define cerr if (false) cerr
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& x) {
	return os << "(" << x.first << "," << x.second << ")";
}
typedef long long ll;
typedef long double ld;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> X(n), Y(n), id(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &X[i], &Y[i]);
		id[i] = i;
	}
	vector<pair<int, pair<int, int>>> edges;
	sort(id.begin(), id.end(), [&](int a, int b) {
		return X[a] < X[b];
	});
	for (int i = 0; i + 1 < n; ++i) {
		edges.push_back({min(abs(X[id[i]] - X[id[i + 1]]), abs(Y[id[i]] - Y[id[i + 1]])), {id[i], id[i + 1]}});
	}
	sort(id.begin(), id.end(), [&](int a, int b) {
		return Y[a] < Y[b];
	});
	for (int i = 0; i + 1 < n; ++i) {
		edges.push_back({min(abs(X[id[i]] - X[id[i + 1]]), abs(Y[id[i]] - Y[id[i + 1]])), {id[i], id[i + 1]}});
	}
	sort(edges.begin(), edges.end());
	vector<int> par(n);
	iota(par.begin(), par.end(), 0);
	function<int(int)> getRoot = [&](int a) {
		if (par[a] == a) return a;
		return par[a] = getRoot(par[a]);
	};
	ll ans = 0;
	for (int i = 0; i < edges.size(); ++i) {
		int a, b;
		tie(a, b) = edges[i].second;
		int pa = getRoot(a), pb = getRoot(b);
		if (pa == pb) continue;
		par[pa] = pb;
		ans += edges[i].first;
	}
	printf("%lld\n", ans);
}
