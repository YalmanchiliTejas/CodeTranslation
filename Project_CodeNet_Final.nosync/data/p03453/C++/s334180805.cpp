#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<ll(n);++i)
#define RREP(i,n) for(ll i=ll(n)-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<ll(n);++i)
#define RFOR(i,m,n) for(ll i=ll(n)-1;i>=ll(m);--i)
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define DUMP(v) REP(aa, (v).size()) { cout << v[aa]; if (aa != v.size() - 1)cout << " "; else cout << endl; }
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };


using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll max(ll a, int b) { return max(a, ll(b)); }
ll max(int a, ll b) { return max(ll(a), b); }
ll min(ll a, int b) { return min(a, ll(b)); }
ll min(int a, ll b) { return min(ll(a), b); }
struct Edge { int from; int to; ll weight; };
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef pair<ll, int> P;


vl dijkstra(const Graph &g, int src) {
	vl dist(g.size(), INF*INF);
	dist[src] = 0;
	//vector<int> prev(g.size());
	priority_queue<P, vector<P>, greater<P>> q;
	q.push({ 0, src });
	while (!q.empty()) {
		auto p = q.top(); q.pop();
		ll v = p.second;
		if (p.first > dist[v]) continue;
		for (int i = 0; i < g[v].size(); ++i) {
			Edge e = g[v][i];
			if (dist[e.to] > dist[v] + e.weight) {
				dist[e.to] = dist[v] + e.weight;
				q.push({ dist[e.to],e.to });
				//prev[e.to] = v;
			}
		}
	}
	return dist;

}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	s--; t--;
	Graph g(n);
	vi u(m), v(m), d(m);
	REP(i, m) {
		cin >> u[i] >> v[i] >> d[i];
		u[i]--;
		v[i]--;
		g[u[i]].push_back(Edge{ u[i],v[i],d[i] });
		g[v[i]].push_back(Edge{ v[i],u[i],d[i] });
	}
	vl a = dijkstra(g, s), b = dijkstra(g, t);
	vl dpa(n, 0), dpb(n, 0);
	dpa[s] = 1;
	priority_queue<pll> q;
	q.push({ 0,s });
	while (!q.empty()) {
		pll p = q.top(); q.pop();
		REP(i, g[p.second].size()) {
			int to = g[p.second][i].to, cost = g[p.second][i].weight;
			if (a[p.second] + cost == a[to]) {
				if (dpa[to] == 0) {
					q.push({ -a[to],to });
				}
				dpa[to] += dpa[p.second];
				dpa[to] %= MOD;
			}
		}
	}

	dpb[t] = 1;

	q.push({ 0,t });
	while (!q.empty()) {
		pll p = q.top(); q.pop();
		REP(i, g[p.second].size()) {
			int to = g[p.second][i].to, cost = g[p.second][i].weight;
			if (b[p.second] + cost == b[to]) {
				if (dpb[to] == 0) {
					q.push({ -b[to],to });
				}
				dpb[to] += dpb[p.second];
				dpb[to] %= MOD;
			}
		}
	}
	ll ans = dpa[t] * dpb[s] % MOD;
	REP(i, n) {
		if (a[i] == b[i]&&a[i]+b[i]==a[t])ans = (ans - dpa[i] * dpb[i] % MOD*dpa[i]%MOD*dpb[i]%MOD + MOD) % MOD;
	}
	REP(i, m) {
		if (a[u[i]] + b[v[i]] + d[i] == a[t]) {
			
			if (b[v[i]] < a[v[i]] && b[u[i]] > a[u[i]]) {
				//cout << u[i] +1<< " " << v[i] +1<< endl;
				ans = (ans - dpa[u[i]] * dpb[v[i]] % MOD*dpa[u[i]]%MOD*dpb[v[i]]%MOD + MOD) % MOD;

			}
		}
		else if (a[v[i]]+b[u[i]]+d[i]==a[t]) {
			if (b[v[i]] > a[v[i]] && b[u[i]] < a[u[i]]) {
				//cout << u[i] +1<< " " << v[i]+1 << endl;
				ans = (ans - dpb[u[i]] * dpa[v[i]] % MOD*dpb[u[i]]%MOD*dpa[v[i]]%MOD + MOD) % MOD;

			}
		}
	}
	cout << ans << endl;
}
