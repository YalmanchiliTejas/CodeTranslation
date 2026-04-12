#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define INF 1000000000000000000
#define MOD 1000000000
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

/*
 * (1 2) (1 3) (1 4) (2 4)
 * . . . . . . . 
 * . . . . . . .
 * . . . . . . .
 * . . . . . . .
 */
const int N = 400 * 1000 + 5;
pair <ll, pair<ll, ll>> p[N];
map <ll, ll> id;
int sz = 0;
void add_edge(ll x1, ll y1, ll x2, ll y2) {
	p[sz++] = {min(abs(x1 - x2), abs(y1 - y2)), {x1 * MOD + y1, x2 * MOD + y2}};
}
ll root(ll x) {
	if (x == id[x])
		return x;
	return id[x] = root(id[x]);
}
void union1(ll x, ll y) {
	ll pp = root(x);
	ll qq = root(y);
	id[pp] = qq;
}
int main() {
	int n;
	cin >> n;
	vector <pair<ll, ll>> vx, vy;
	vector <ll> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		vx.push_back({x[i], i});
		vy.push_back({y[i], i});
	}
	sort(all(vx));
	sort(all(vy));
	for (ll i = 0; i < n; i++) {
		auto itx = lower_bound(all(vx), make_pair(x[i], i));
		if (next(itx) != vx.end()) {
			add_edge(x[i], y[i], x[next(itx)->ss], y[next(itx)->ss]);
		}
		if (itx != vx.begin()) {
			add_edge(x[i], y[i], x[prev(itx)->ss], y[prev(itx)->ss]);
		}
		auto ity = lower_bound(all(vy), make_pair(y[i], i));
		if (next(ity) != vy.end()) {
			add_edge(x[i], y[i], x[next(ity)->ss], y[next(ity)->ss]);
		}
		if (ity != vy.begin()) {
			add_edge(x[i], y[i], x[prev(ity)->ss], y[prev(ity)->ss]);
		}
		id[x[i] * MOD + y[i]] = x[i] * MOD + y[i];
	}
	sort(p, p + sz);
	ll ans = 0;
	for (int i = 0; i < sz; i++) {
		ll w = p[i].ff;
		ll u = p[i].ss.ff;
		ll v = p[i].ss.ss;
		if (root(u) != root(v)) {
			union1(u, v);
			ans += w;
		}
	}
	cout << ans;
}	
