#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
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
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int pow_mod(ll x, ll n, int m) {
	ll res = 1;
	for (; n > 0; n >>= 1) {
		if (n & 1) res = (res * x) % m;
		x = (x * x) % m;
	}
	return res;
}

struct union_find {
	vector<int> v;
	union_find(int n) : v(n, -1) {}
	int find(int x) { return (v[x] < 0) ? x : (v[x] = find(v[x])); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x != y) {
			if (-v[x] < -v[y]) swap(x, y);
			v[x] += v[y]; v[y] = x;
		}
	}
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};

int main() {
	for (;;) {
		int N, M; cin >> N >> M;
		if (N == 0) break;
		union_find uf(N);
		int k = N;
		while (M--) {
			int a, b; cin >> a >> b;
			a--; b--;
			if (uf.same(a, b)) continue;
			uf.unite(a, b);
			k--;
		}
		if (k == N) cout << pow_mod(2, N, MOD) << endl;
		else cout << (pow_mod(2, k, MOD) + 1) % MOD << endl;
	}
}