#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

const int MOD = 1e9 + 7;
double EPS = 1e-10;

struct union_find {
	vector<int> v;
	union_find(int n) : v(n, -1) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		if (-v[x] < -v[y]) swap(x, y);
		v[x] += v[y]; v[y] = x;
	}
	bool root(int x) { return v[x] < 0; }
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};

bool kr_cmp(const edge& l, const edge& r) { return l.w < r.w; }

ll kruskal(int N, vector<edge> E) {
	sort(E.begin(), E.end(), kr_cmp);
	union_find uf(N);
	ll sum = 0;
	for (edge e: E)
		if (!uf.same(e.u, e.v)) {
			uf.unite(e.u, e.v);
			sum += e.w;
		}
	return sum;
}

int main() {
	int N; cin >> N;
	vector<int> x(N), y(N);
	rep(u, N) scanf("%d%d", &x[u], &y[u]);
	vector<i_i> xu(N), yu(N);
	rep(u, N) {
		xu[u] = i_i(x[u], u);
		yu[u] = i_i(y[u], u);
	}
	sort(xu.begin(), xu.end());
	sort(yu.begin(), yu.end());
	vector<edge> E;
	rep(i, N - 1) E.pb(edge{xu[i].second, xu[i + 1].second, xu[i + 1].first - xu[i].first});
	rep(i, N - 1) E.pb(edge{yu[i].second, yu[i + 1].second, yu[i + 1].first - yu[i].first});
	cout << kruskal(N, E) << endl;
}
