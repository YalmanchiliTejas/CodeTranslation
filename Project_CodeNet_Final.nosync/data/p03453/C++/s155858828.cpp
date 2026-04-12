#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <time.h>
#define int long long
#define endl '\n'
#define INF 1000000000000000000
#define EPS 1e-10
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

ll mod = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n, m, s, t;
	cin >> n >> m >> s >> t;
	s--; t--;
	vector<vector<P>> graph(n, vector<P>());
	vector<P> a;
	vector<int> cost;
	rep(i, m) {
		int u, v, d;
		cin >> u >> v >> d;
		u--; v--;
		graph[u].pb(P(v, d));
		graph[v].pb(P(u, d));
		a.pb(P(u, v));
		cost.pb(d);
	}
	vector<int> dist(n, INF);
	vector<int> cnt(n, 0);
	dist[s] = 0; cnt[s] = 1;
	priority_queue<P, vector<P>, greater<P>> que;
	que.push(P(0, s));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int px = p.first; int py = p.second;
		if (dist[py] < px) continue;
		for (P q : graph[py]) {
			int qx = q.first; int qy = q.second;
			if (dist[py] + qy == dist[qx]) {
				cnt[qx] += cnt[py];
				cnt[qx] %= mod;
			}
			else if (dist[py] + qy < dist[qx]) {
				cnt[qx] = cnt[py];
				dist[qx] = dist[py] + qy;
				que.push(P(dist[qx], qx));
			}
		}
	}
	vector<int> dist2(n, INF);
	vector<int> cnt2(n, 0);
	dist2[t] = 0; cnt2[t] = 1;
	que.push(P(0, t));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int px = p.first; int py = p.second;
		if (dist2[py] < px) continue;
		for (P q : graph[py]) {
			int qx = q.first; int qy = q.second;
			if (dist2[py] + qy == dist2[qx]) {
				cnt2[qx] += cnt2[py];
				cnt2[qx] %= mod;
			}
			else if (dist2[py] + qy < dist2[qx]) {
				cnt2[qx] = cnt2[py];
				dist2[qx] = dist2[py] + qy;
				que.push(P(dist2[qx], qx));
			}
		}
	}
	int ans = cnt[t] * cnt2[s] % mod;
	if (dist[t] % 2 == 0) {
		rep(i, n) {
			if (dist[i] == dist2[i] && dist[i] * 2 == dist[t]) {
				int x = cnt[i] * cnt2[i] % mod;
				ans += mod - x * x%mod;
				ans %= mod;
			}
		}
	}
	rep(i, a.size()) {
		int ax = a[i].first; int ay = a[i].second;
		if (dist[ax] > dist[ay]) swap(ax, ay);
		if (2 * dist[ax] < dist[t] && dist[t] < 2 * dist[ay] && 2 * dist2[ay] < dist[t] && dist[t] < 2 * dist2[ax] && dist[ax] + cost[i] == dist[ay] && dist2[ay] + cost[i] == dist2[ax] && dist[ax] + dist2[ax] == dist[t] && dist[ay] + dist2[ay] == dist[t]) {
			int x = cnt[ax] * cnt2[ay] % mod;
			ans += mod - x * x%mod;
			ans %= mod;
		}
	}
	cout << ans << endl;
}