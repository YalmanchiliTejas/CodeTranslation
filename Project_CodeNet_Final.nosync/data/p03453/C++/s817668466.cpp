// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2")

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <chrono>
#include <vector>
#include <map>
#include <random>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <deque>
#include <cassert>
#include <stack>
using namespace std;

#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define ll long long
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline void setin(string s) {
	freopen(s.c_str(), "r", stdin);
}

inline void setout(string s) {
	freopen(s.c_str(), "w", stdout);
}

template <typename T> inline T range(T l, T r) {
	return uniform_int_distribution <T>(l, r)(rng);
}

template <typename T> void Min(T &a, T b) {
    a = min(a, b);
}
 
template <typename T> void Max(T &a, T b) {
    a = max(a, b);
}

#define int long long

const int inf = 2e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 15;
int n, m, a[N];
vector <pii> g[N];
int s, t;

int d[N], ways[N];

inline int add(int a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
	if(a < 0)
		a += mod;
	return a;
}

inline void add_t(int &a, int b) {
	a = add(a, b);
}

set <pii> q;

inline int mt(int a, int b) {
	return 1ll * a * b % mod;
}

inline void dxtra(int s, vector <int> &d, vector <int> &ways) {
	d[s] = 0;
	ways[s] = 1;
	q.insert({0, s});
	while(!q.empty()) {
		int v = q.begin()->se;
		q.erase(q.begin());
		for(pii to : g[v]){
			if(d[to.f] > d[v] + to.se) {
				q.erase({d[to.f], to.f});
				ways[to.f] = ways[v];
				d[to.f] = d[v] + to.se;
				q.insert({d[to.f], to.f});
			}
			else if(d[to.f] == d[v] + to.se)
				add_t(ways[to.f], ways[v]);
		}
	}
}

vector <pair <pii, int>> e;

inline int sq(int x) {
	return mt(x, x);
}

main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	// setin("input.txt");
	cin >> n >> m >> s >> t;
	for(int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].pb({v, w});
		g[v].pb({u, w});
		e.pb({{u, v}, w});
	}
	vector <int> d1(N, inf), d2(N, inf), ways1(N, 0), ways2(N, 0);
	dxtra(s, d1, ways1);
	dxtra(t, d2, ways2);
	int ans = sq(ways1[t]);

	int d = d1[t];
	for(int i = 1; i <= n; ++i)
		if(d1[i] == d2[i] && d1[i] + d2[i] == d)
			add_t(ans, -sq(mt(ways1[i], ways2[i])));

	for(int i = 0; i < e.size(); ++i) {
		int u = e[i].f.f, v = e[i].f.se, w = e[i].se;
		if(d1[u] + w + d2[v] == d && (d1[u] < d / 2 && d2[v] < d / 2))
			add_t(ans, -sq(mt(ways1[u], ways2[v])));
		swap(u, v);
		if(d1[u] + w + d2[v] == d && (d1[u] < d / 2 && d2[v] < d / 2))
			add_t(ans, -sq(mt(ways1[u], ways2[v])));
	}
	cout << ans << endl;
	return 0;
}