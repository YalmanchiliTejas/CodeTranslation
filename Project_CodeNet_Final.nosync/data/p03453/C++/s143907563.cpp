#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <ctype.h>
#include <random>
#include <string.h>
#include <cmath>
#include <unordered_map>
#include <cstdio>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long ll;

ll gcd(ll x, ll y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
ll lcm(ll x, ll y) {
	return x / gcd(x, y)*y;
}
ll kai(ll x, ll y, ll m) {
	ll res = 1;
	for (ll i = x - y + 1; i <= x; i++) {
		res *= i; res %= m;
	}
	return res;
}
ll mod_pow(ll x, ll y, ll m) {
	ll res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}

ll comb(ll x, ll y, ll m) {
	if (y > x)return 0;
	return kai(x, y, m) * mod_pow(kai(y, y, m), m - 2, m) % m;
}

const ll mod = 1000000007;
const ll INF = 1000000000000000000;
struct edge { int to, cost; };

int n, m, s, t;
vector<edge> vec[100010];
ll d1[100010], d2[100010];
ll cnt1[100010], cnt2[100010];
ll ans;

void dijkstra(int x, ll *d, ll *cnt) {
	fill(d, d + n + 1, INF);
	d[x] = 0;
	cnt[x] = 1;
	priority_queue<pair<ll,int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
	que.push(make_pair(0, x));
	while (!que.empty()) {
		int v = que.top().second; ll k = que.top().first; que.pop();
		if (d[v] < k)continue;
		for (int i = 0; i < (int)vec[v].size(); i++) {
			edge e = vec[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				cnt[e.to] = cnt[v];
				que.push(make_pair(d[e.to], e.to));
			}
			else if (d[e.to] == d[v] + e.cost) cnt[e.to] = (cnt[e.to] + cnt[v]) % mod;
		}
	}
}

signed main() {
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		vec[u].push_back(edge{ v,c });
		vec[v].push_back(edge{ u,c });
	}
	dijkstra(s, d1, cnt1);
	dijkstra(t, d2, cnt2);
	ans = cnt1[t] * cnt1[t] % mod;
	for (int i = 1; i <= n; i++) {
		if (d1[t] == d1[i] * 2) ans = (ans - cnt1[i] * cnt1[i] % mod*cnt2[i] % mod * cnt2[i] % mod + mod) % mod;
		if (d1[t] <= d1[i] * 2)continue;
		for (int j = 0; j < (int)vec[i].size(); j++) {
			edge e = vec[i][j];
			if (d1[e.to] * 2 <= d1[t])continue;
			if (d1[t] < d1[i] + d2[e.to] + e.cost)continue;
			ans = (ans - cnt1[i] * cnt1[i] % mod*cnt2[e.to] % mod * cnt2[e.to] % mod + mod) % mod;
		}
	}
	cout << ans << endl;
}