#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = (1e+9)+7;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
struct edge { int to; ll cost; };
int V;
vector<edge> G[100000];
ll dt[100000];
void dijkstrat(int s) {
	priority_queue<LP, vector<LP>, greater<LP>>que;
	fill(dt, dt + V, INF);
	dt[s] = 0;
	que.push(LP(0, s));
	while (!que.empty()) {
		LP p = que.top(); que.pop();
		int v = p.second;
		if (dt[v] < p.first)continue;
		for (int i = 0; i < (int)G[v].size(); i++) {
			edge e = G[v][i];
			if (dt[e.to] > dt[v] + e.cost) {
				dt[e.to] = dt[v] + e.cost;
				que.push(P(dt[e.to], e.to));
			}
		}
	}
}
ll ds[100000];
void dijkstras(int s) {
	priority_queue<LP, vector<LP>, greater<LP>>que;
	fill(ds, ds + V, INF);
	ds[s] = 0;
	que.push(LP(0, s));
	while (!que.empty()) {
		LP p = que.top(); que.pop();
		int v = p.second;
		if (ds[v] < p.first)continue;
		for (int i = 0; i < (int)G[v].size(); i++) {
			edge e = G[v][i];
			if (ds[e.to] > ds[v] + e.cost) {
				ds[e.to] = ds[v] + e.cost;
				que.push(P(ds[e.to], e.to));
			}
		}
	}
}
ll cnts[100000] = {}; ll cntt[100000] = {};
pair<ll, int> ps[100000], pt[100000];
struct edge2 { int from, to; ll cost; };
edge2 G2[200000];
int main() {
	int n, m; cin >> n >> m; V = n;
	int s, t; cin >> s >> t; s--; t--;
	int u, v; ll c;
	rep(i, m) {
		cin >> u >> v >> c; u--; v--;
		G[u].push_back({ v,c });
		G[v].push_back({ u,c });
		G2[i] = { u,v,c };
	}
	dijkstras(s); dijkstrat(t);
	ll sum = ds[t];
	cnts[s] = 1; cntt[t] = 1;
	rep(i, n) {
		ps[i] = { ds[i],i };
		pt[i] = { dt[i],i };
	}
	sort(ps, ps + n); sort(pt, pt + n);
	rep(i, n) {
		int as = ps[i].second; ll cs = ps[i].first;
		int at = pt[i].second; ll ct = pt[i].first;
		int lens = G[as].size(); int lent = G[at].size();
		rep(j, lens) {
			int vs = G[as][j].to; ll ccs = G[as][j].cost;
			if (cs - ccs == ds[vs]) {
				(cnts[as] += cnts[vs]) %= MOD;
			}
		}
		rep(j, lent) {
			int vt = G[at][j].to; ll cct = G[at][j].cost;
			if (ct - cct == dt[vt]) {
				(cntt[at] += cntt[vt]) %= MOD;
			}
		}
	}
	if (cnts[t] != cntt[s])cout << "wow?" << endl;
	ll out = cnts[t] * cntt[s] % MOD;
	rep(i, n) {
		if (ds[i] == dt[i]) {
			ll dimi = cnts[i] * cntt[i] % MOD;
			dimi = dimi * dimi%MOD;
			out = (out - dimi + MOD) % MOD;
		}
	}
	ll hasum = (sum + (ll)1) / (ll)2;
	rep(i, m) {
		int x1 = G2[i].from; int x2 = G2[i].to; ll xc = G2[i].cost;
		if (ds[x1] > ds[x2])swap(x1, x2);
		if (ds[x1] + xc + dt[x2] == sum) {
			if (ds[x1] < hasum && dt[x2] < hasum) {
				ll dimi = cnts[x1] * cntt[x2] % MOD;
				dimi = dimi * dimi%MOD;
				out = (out - dimi + MOD) % MOD;
			}
		}
	}
	cout << out << endl;
	return 0;
}