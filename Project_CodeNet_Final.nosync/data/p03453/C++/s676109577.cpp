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
void dijkstra(int s, vector<ll> &cnt, vector <ll> &dist) {
	set<PII> st;
	st.insert({0, s});
	cnt[s] = 1;
	dist[s] = 0;
	while(!st.empty()) {
		int x = (st.begin())->ss;
		st.erase(st.begin());
		for (auto g : v[x]) {
			if(dist[g.ff] > dist[x] + g.ss) {
				st.erase({dist[g.ff], g.ff});
				dist[g.ff] = dist[x] + g.ss;
				st.insert({dist[g.ff], g.ff});
				cnt[g.ff] = 0;
			}
			if(dist[g.ff] == dist[x] + g.ss) {
				cnt[g.ff] = (cnt[g.ff] + cnt[x]) % MOD;
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
	
	vector <ll> cs(n + 1, 0);
	vector <ll> ds(n + 1, INF);
	dijkstra(S, cs, ds);
	
	vector <ll> ct(n + 1, 0);
	vector <ll> dt(n + 1, INF);
	dijkstra(T, ct, dt);
	
	ll mn = ds[T];
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
