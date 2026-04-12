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
struct edge { int to;ll cost; };
int V;
vector<edge> G[100000];
ll s1[100000],t1[100000];
void dijkstras(int s) {
	priority_queue<LP, vector<LP>, greater<LP>>que;
	fill(s1, s1 + V, INF);
	s1[s] = 0;
	que.push(P(0, s));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second;
		if (s1[v] < p.first)continue;
		for (int i = 0; i < (int)G[v].size(); i++) {
			edge e = G[v][i];
			if (s1[e.to] > s1[v] + e.cost) {
				s1[e.to] = s1[v] + e.cost;
				que.push(P(s1[e.to], e.to));
			}
		}
	}
}
void dijkstrat(int s) {
	priority_queue<LP, vector<LP>, greater<LP>>que;
	fill(t1, t1 + V, INF);
	t1[s] = 0;
	que.push(P(0, s));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second;
		if (t1[v] < p.first)continue;
		for (int i = 0; i < (int)G[v].size(); i++) {
			edge e = G[v][i];
			if (t1[e.to] > t1[v] + e.cost) {
				t1[e.to] = t1[v] + e.cost;
				que.push(P(t1[e.to], e.to));
			}
		}
	}
}
ll cnts[100000] = {}; ll cntt[100000] = {};
struct edge2 { int fr, to; ll co; };
queue<edge2> memo;
int main() {
	cin >> V; int m; cin >> m;
	int s, t; cin >> s >> t; s--; t--;
	rep(i, m) {
		int u, v; ll d; cin >> u >> v >> d; u--; v--;
		G[u].push_back({ v,d });
		G[v].push_back({ u,d });
		memo.push({ u,v,d });
	}
	dijkstras(s); dijkstrat(t);
	LP sorts[100000],sortt[100000];
	rep(i, V) {
		sorts[i] = { s1[i],i };
		sortt[i] = { t1[i],i };
	}
	sort(sorts, sorts + V); sort(sortt, sortt + V);
	rep(i, V) {
		ll dd = sorts[i].first; int vv = sorts[i].second;
		if(vv == s) {
			cnts[vv] = 1;
		}
		int len = G[vv].size();
		rep(j, len) {
			if (dd + G[vv][j].cost == s1[G[vv][j].to]) {
				(cnts[G[vv][j].to] += cnts[vv]) %= MOD;
			}
		}
	}
	rep(i, V) {
		ll dd = sortt[i].first; int vv = sortt[i].second;
		if (vv == t) {
			cntt[vv] = 1;
		}
		int len = G[vv].size();
		rep(j, len) {
			if (dd + G[vv][j].cost == t1[G[vv][j].to]) {
				(cntt[G[vv][j].to] += cntt[vv]) %= MOD;
			}
		}
	}
	ll wei = s1[t];ll rem = 0;
	ll out = cnts[t] * cntt[s] % MOD;
	if (wei % 2 == 0) {
		ll dd = wei / (ll)2;
		rep(i, V) {
			if (s1[i] == dd && t1[i] == dd) {
				ll csum = cnts[i] * cntt[i] % MOD;
				csum = csum * csum%MOD;
				(rem += csum) %= MOD;
			}
		}
	}
	ll dd = (wei + (ll)1) / (ll)2;
	rep(i, m) {
		edge2 nex = memo.front(); memo.pop();
		int le = nex.fr; int ri = nex.to;
		if (s1[le] > s1[ri])swap(ri, le);
		if (s1[le] + nex.co + t1[ri] == wei && s1[le] < dd&&t1[ri] < dd) {
			ll csum = cnts[le] * cntt[ri] % MOD;
			csum = csum * csum%MOD;
			(rem += csum) %= MOD;
		}
	}
	cout << (out - rem + MOD) % MOD << endl;
	return 0;
}