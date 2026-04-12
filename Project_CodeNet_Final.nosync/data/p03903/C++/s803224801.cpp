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
const ll MOD = 998244353;
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
int par[100000];
int rank1[100000];
void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		rank1[i] = 0;
	}
}
int find1(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find1(par[x]);
	}
}
void unite1(int x, int y) {
	x = find1(x);
	y = find1(y);
	if (x == y)return;
	if (rank1[x] < rank1[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (rank1[x] == rank1[y])rank1[x]++;
	}
}
bool same(int x, int y) {
	return find1(x) == find1(y);
}
struct edge { int u, v;ll cost; };
//最大全域木にしたい場合は<を>にする
bool comp(const edge&e1, const edge&e2) {
	return e1.cost < e2.cost;
}
edge es[400000];
int V, E;
struct edge2 { int to; ll cost; };
vector<edge2> G[4000];
ll kruskal() {
	sort(es, es + E, comp);
	init(V);
	ll res = 0;
	for (int i = 0; i < E; i++) {
		edge e = es[i];
		if (!same(e.u, e.v)) {
			unite1(e.u, e.v);
			res += e.cost;
			G[e.u].push_back({ e.v,e.cost });
			G[e.v].push_back({ e.u,e.cost });
		}
	}
	return res;
}
ll d[4000][4000];
int main() {
	cin >> V >> E;
	rep(i, E) {
		int a, b; ll c; cin >> a >> b >> c; a--; b--;
		es[i] = { a,b,c };
	}
	ll sum = kruskal();
	rep(i, V) {
		int used[4000] = {}; used[i] = 1;
		d[i][i] = 0;
		queue<int> q; q.push(i);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			int len = G[x].size();
			rep(j, len) {
				int v = G[x][j].to;
				if (used[v])continue;
				used[v] = true; q.push(v);
				d[i][v] = max(d[i][x], G[x][j].cost);
			}
		}
	}
	int q; cin >> q;
	rep(i, q) {
		int s, t; cin >> s >> t; s--; t--;
		cout << sum - d[s][t] << endl;
	}
	return 0;
}