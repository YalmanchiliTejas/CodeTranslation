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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
typedef pair<int, bool> sP;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

#include<cstring>
struct edge { int to, cap, rev; };
vector<edge> G[100000];
bool used[100000];
void add_edge(int from, int to, int cap) {
	G[from].push_back(edge{ to, cap, (int)G[to].size() });
	G[to].push_back(edge{ from, 0, (int)G[from].size() - 1 });
}
int dfs(int v, int t, int f) {
	if (v == t)return f;
	used[v] = true;
	for (int i = 0; i < (int)G[v].size(); i++) {
		edge &e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s, int t) {
	int flow = 0;
	for (;;) {
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, mod);
		if (f == 0)return flow;
		flow += f;
	}
}

int h,w,c,m,nw,nc,nm;
void solve() {
	rep(i, 1000) {
		G[i].clear();
	}
	int s = 800; int t = 801;
	rep(i, h) {
		add_edge(s, i, 1);
		add_edge(i, i + 100, 1);
	}
	rep(i, w) {
		add_edge(i + 200, i + 300, 1);
	}
	add_edge(w + 200, w + 300, nw);
	rep(i, c) {
		add_edge(i + 400, i + 500, 1);
	}
	add_edge(c + 400, c + 500, nc);
	rep(i, m) {
		add_edge(i + 600, i + 700, 1);
		add_edge(i + 700, t,1);
	}
	add_edge(m + 600, m + 700, nm);
	rep(i, h) {
		add_edge(i + 100, w + 200, mod);
	}
	rep(i, w) {
		add_edge(i + 300, c + 400,mod);
	}
	rep(i, c) {
		add_edge(i + 500, m + 600, mod);
		add_edge(w + 300, i + 400, mod);
	}
	rep(i, m) {
		add_edge(c + 500, i + 600, mod);
	}
	//add_edge(w + 300, c + 400, mod);
	//add_edge(c + 500, m + 600, mod);
	add_edge(m + 700, t, mod);
	rep(i, w) {
		int x; cin >> x;
		rep(j, x) {
			int u; cin >> u; u--;
			add_edge(u + 100, i+200, 1);
		}
	}
	rep(i, c) {
		int x; cin >> x;
		rep(j, x) {
			int u; cin >> u; u--;
			add_edge(u + 300, i+400, 1);
		}
	}
	rep(i, m) {
		int x; cin >> x;
		rep(j, x) {
			int u; cin >> u; u--;
			add_edge(u + 500, i + 600, 1);
		}
	}
	int ans = max_flow(s, t);
	//cout << "ans is ";
	cout << ans << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	while (cin >> h>>w>>c>>m>>nw>>nc>>nm,h>=0) {
		solve();
	}
	//stop
	return 0;
}


