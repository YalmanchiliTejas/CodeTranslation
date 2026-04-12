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
#define MOD 1000000007
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

using PII = pair<ll, int>;
const int N = 200 * 1000 + 5;
vector <pair<int, int>> v[N];
void dijkstra(int s, vector <ll> &dist) {
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({0, s});
	dist[s] = 0;
	while(!pq.empty()) {
		int x = pq.top().ss;
		pq.pop();
		for (auto g : v[x]) {
			if(dist[g.ff] > dist[x] + g.ss) {
				dist[g.ff] = dist[x] + g.ss;
				pq.push({dist[g.ff], g.ff});
			}
		}
	}
}
void count_paths(int s, vector <ll> &cnt, vector<ll> &d2, ll mn) {
	vector <int> vis(N, false);
	vector <ll> dist(N, INF);
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({0, s});
	dist[s] = 0;
	cnt[s] = 1;
	while(!pq.empty()) {
		int x = pq.top().ss;
		pq.pop();
		if(vis[x])
			continue;
		vis[x] = true;
		for (auto g : v[x]) {
			if(dist[x] + g.ss + d2[g.ff] == mn) {
				cnt[g.ff] += cnt[x];
				cnt[g.ff] %= MOD;
			}
			if(dist[g.ff] > dist[x] + g.ss) {
				dist[g.ff] = dist[x] + g.ss;
				pq.push({dist[g.ff], g.ff});
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	int S, T;
	cin >> S >> T;
	vector <tuple<int, int, int>> ed;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		v[x].push_back({y, w});
		v[y].push_back({x, w});
		ed.push_back(make_tuple(x, y, w));
		ed.push_back(make_tuple(y, x, w));
	}
	vector <ll> ds(n + 1, INF);
	dijkstra(S, ds);
	vector <ll> dt(n + 1, INF);
	dijkstra(T, dt);
	ll mn = ds[T];
	vector <ll> cs(n + 1, 0);
	count_paths(S, cs, dt, mn);
	vector <ll> ct(n + 1, 0);
	count_paths(T, ct, ds, mn);
	ll total = (cs[T] * cs[T]) % MOD;
	for (int i = 1; i <= n; i++) {
		if(2 * ds[i] == mn && 2 * dt[i] == mn) {
			ll go = (cs[i] * ct[i]) % MOD;
			total -= (go * go) % MOD;
			total = (total + MOD) % MOD;
		} 
	}
	for (int i = 0; i < 2 * m; i++) {
		int x, y, w;
		tie(x, y, w) = ed[i];
		if(ds[x] + w + dt[y] == mn) {
			if(2 * ds[x] < mn && 2 * dt[y] < mn) {
				ll go = (cs[x] * ct[y]) % MOD;
				total -= (go * go) % MOD;
				total = (total + MOD) % MOD;
			}
		}
	}
	cout << total;
}
