#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fst first
#define snd second
const ll mod = 1000000007;
const ll INF = mod * mod;
#define MAX_N 100000

int main() {
	int n, m; cin >> n >> m;
	int s, t; cin >> s >> t; s--; t--;
	vector<pair<int,ll> > E[MAX_N];
	for (int i = 0; i < m; i++) {
		int p, q;
		ll r; cin >> p >> q >> r; p--; q--;
		E[p].push_back(make_pair(q, r));
		E[q].push_back(make_pair(p, r));
	}
	ll cost[MAX_N];
	/* cost initialize */
	for (int i = 0; i < n; i++) {
		cost[i] = INF;
	}
	/* djikstra */
	cost[s] = 0;
	bool used[MAX_N] = {};
	priority_queue<pair<ll, int>,vector<pair<ll,int>>, greater<pair<ll,int> > > pq;
	pq.push(make_pair(0LL, s));
	while (!pq.empty()) {
		int id = pq.top().snd; pq.pop();
		if (used[id])continue;
		for (auto &&e : E[id]) {
			if (cost[e.fst] > cost[id] + e.snd) {
				cost[e.fst] = cost[id] + e.snd;
				pq.push(make_pair(cost[e.fst], e.first));
			}
		}
		used[id] = true;
	}
	ll route[MAX_N],route_r[MAX_N];
	pair<ll, int> cost_id[MAX_N];
	for (int i = 0; i < n; i++) {
		cost_id[i] = make_pair(cost[i], i);
	}
	sort(cost_id, cost_id + n);
	for (int i = 0; i < n; i++) {
		route[i] = route_r[i] = 0LL;
	}
	route[s] = 1LL;
	for (int i = 1; i < n; i++) {
		int id = cost_id[i].snd;
		for (auto &&e : E[id]) {
			if (cost[e.fst] == cost[id] - e.snd) {
				route[id] += route[e.fst];
				route[id] %= mod;
			}
		}
	}
	route_r[t] = 1LL;
	for (int i = n-2; i >=0; i--) {
		if (cost_id[i].fst >= cost[t])continue;
		int id = cost_id[i].snd;
		for (auto &&e : E[id]) {
			if (cost[e.fst] == cost[id] + e.snd) {
				route_r[id] += route_r[e.fst];
				route_r[id] %= mod;
			}
		}
	}
	int ans = route[t] * route[t] % mod;/* include collision */
	for (int i = 0; i < n; i++) {
		if (2LL * cost[i] == cost[t] ) {
			ll sub= route[i] * route_r[i] % mod;
			ans -= sub * sub%mod;
		}
		if (ans < 0)ans += mod;
	}
	for (int i = 0; i < n; i++) {
		if (cost[i] * 2LL < cost[t]) {
			for (auto &&e : E[i]) {
				if (cost[i]+e.snd==cost[e.fst] && cost[e.fst] * 2LL > cost[t]) {
					ll sub = route[i] * route_r[e.fst] % mod;
					ans -= sub *sub % mod;
				}
				if (ans < 0)ans += mod;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
