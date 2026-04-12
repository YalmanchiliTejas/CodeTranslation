#include <bits/stdc++.h>
 
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
const int N = 200010;
 
vector <pii> g[N];
int ok[N];
const int mod = 1000*1000*1000+7;
void dijkstra (vector <ll> &dist, vector <ll> &ways, int s) {
	fill (dist.begin(), dist.end(), 100000000000000000LL);
	fill (ways.begin(), ways.end(), 0);
	memset (ok, 0, sizeof ok);
	dist[s] = 0;
	ways[s] = 1;
	priority_queue < pii, vector<pii>, greater<pii> > pq;
	pq.emplace(0, s);
	while(!pq.empty()) {
		ll u, d; tie(d, u) = pq.top();
		pq.pop();
		if (ok[u]) continue;
		ok[u] = 1;
		for (auto w : g[u]) {
			ll v, nd; tie(v, nd) = w;
			if (d + nd < dist[v]) {
				dist[v] = nd + d;
				ways[v] = ways[u];
				pq.emplace(dist[v], v);
			} else if (nd + d == dist[v]) ways[v] = (ways[v] + ways[u]) % mod;
		}
	}
}
int main (void) {
	int n, m; cin >> n >> m;
	int s, t; cin >> s >> t;
	vector < tuple<int, int, int> > edges;
	for (int i = 0; i < m; i++) {
		int u, v, d; cin >> u >> v >> d;
		edges.eb(u, v, d);
		edges.eb(v, u, d);
		g[u].eb(v, d);
		g[v].eb(u, d);
	}
	vector <ll> distST, distTS, waysST, waysTS;
	distST.resize(n+1);
	distTS.resize(n+1);
	waysST.resize(n+1);
	waysTS.resize(n+1);
	dijkstra(distST, waysST, s);
	dijkstra(distTS, waysTS, t);
	ll ans = waysST[t];
	ans = (waysST[t] * waysTS[s]) % mod;
//	1 -> 2 -> 3
//	1 -> 4 -> 3
 
//	3 -> 4 -> 1
//	3 -> 2 -> 1
	//vertice em comum
	for (int i = 1; i <= n; i++) {
		if (distST[i] + distTS[i] == distST[t] and distST[i] == distTS[i]) {
			ll w1 = waysST[i] * waysST[i], w2 = waysTS[i] * waysTS[i];
w1 %= mod; w2 %= mod;
			ans = (ans - w1 * w2) % mod;
			ans = (ans + mod) % mod;
		}
	}
	//aresta em comum
	for (auto e : edges) {
		int u, v, k; tie(u, v, k) = e;
		if (distST[u] + distTS[v] + k == distST[t]) {
			ll a = distST[u], b = distST[u] + k;
			ll c = distTS[v], d = distTS[v] + k;
 
			if (c >= b or d <= a) continue;
			ll w1 = waysST[u] * waysST[u], w2 = waysTS[v] * waysTS[v];
w1 %= mod; w2 %= mod;
			ans = (ans - w1 * w2) % mod;
			ans = (ans + mod) % mod;
		}
	}
	cout << ans << endl;
	return 0;
}