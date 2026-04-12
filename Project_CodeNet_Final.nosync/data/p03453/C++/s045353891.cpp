#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

#define fst first
#define snd second

using namespace std;

template<class T>bool chmax(T &a, const T &b) { return (a < b) ? (a = b, 1) : 0;}
template<class T>bool chmin(T &a, const T &b) { return (b < a) ? (a = b, 1) : 0;}

using ll = long long;
using R = long double;
const R EPS = 1e-9L; // [-1000,1000]->EPS=1e-8 [-10000,10000]->EPS=1e-7
inline int sgn(const R& r) {return (r > EPS) - (r < -EPS);}
inline R sq(R x) {return sqrt(max(x, 0.0L));}

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

// Problem Specific Parameter:

//Appropriately Changed
using W = ll;
using edge = struct {int to; W cost;};
using G = vector<vector<edge>>;

//Appropriately Changed
void add_edge(G &graph, int from, int to, W cost) {
	graph[from].push_back({to, cost});
	graph[to].push_back({from, cost});
}

auto dijkstra(const G &graph, int s) {
	const W inf = 1LL << 60;
	const int n = graph.size();

	vector<W> dist(n, inf);
	using state = tuple<W, int>;

	priority_queue<state, vector<state>, greater<state>> q;
	dist[s] = 0, q.push(state(0, s));

	while (!q.empty()) {
		W c; int v;
		tie(c, v) = q.top(); q.pop();
		for (auto &e : graph[v]) {
			W nc = c + e.cost; int nv = e.to;
			if (chmin(dist[nv], nc)) q.push(state(nc, nv));
		}
	}
	return dist;
}

const ll mod = 1000000007LL;

const int limit = 100010;
ll sdp[limit], tdp[limit];

int main(void) {
	ll n, m;
	cin >> n >> m;

	ll s, t;
	cin >> s >> t;
	s--, t--;

	G graph(n);
	rep(i, m) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		add_edge(graph, a, b, c);
	}

	auto sdist = dijkstra(graph, s);
	auto tdist = dijkstra(graph, t);

	using state = pair<ll, ll>;
	vector<state> ary;

	rep(i, n) ary.push_back(state(sdist[i], i));
	sort(begin(ary), end(ary));

	sdp[s] = 1LL;
	rep(i, n) {
		const int v = ary[i].snd;
		for (auto &e : graph[v]) {
			if (sdist[v] + e.cost != sdist[e.to]) continue;
			sdp[e.to] = (sdp[e.to] + sdp[v]) % mod;
		}
	}

	ary.clear();
	rep(i, n) ary.push_back(state(tdist[i], i));
	sort(begin(ary), end(ary));

	tdp[t] = 1LL;
	rep(i, n) {
		const int v = ary[i].snd;
		for (auto &e : graph[v]) {
			if (tdist[v] + e.cost != tdist[e.to]) continue;
			tdp[e.to] = (tdp[e.to] + tdp[v]) % mod;
		}
	}

	const ll shortest = sdist[t];
	ll cur = 0LL;

	rep(v, n) {
		if (sdist[v] + tdist[v] != shortest) continue;
		if (2LL * sdist[v] > shortest) continue;
		if (2LL * tdist[v] > shortest) continue;
		ll spath = 1LL * sdp[v] * tdp[v] % mod;
		ll tpath = 1LL * tdp[v] * sdp[v] % mod;
		ll add = 1LL * spath * tpath % mod;
		cur = (cur + add) % mod;
	}


	rep(v, n) {
		for (auto &e : graph[v]) {
			if (sdist[v] + e.cost + tdist[e.to] != shortest) continue;
			if (2LL * sdist[v] >= shortest) continue;
			if (2LL * tdist[e.to] >= shortest) continue;
			ll spath = 1LL * sdp[v] * tdp[e.to] % mod;
			ll tpath = 1LL * tdp[e.to] * sdp[v] % mod;
			ll add = 1LL * spath * tpath % mod;
			cur = (cur + add) % mod;
		}
	}

	const ll all = (1LL * sdp[t] * sdp[t]) % mod;
	const ll ans = (all + mod - cur) % mod;
	cout << ans << endl;
	return 0;
}