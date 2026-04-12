#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)

static const double PI = 3.1415926535897932384626433;
static const ll INF = (ll)1 << 55;
static const ll MOD = 1000000007;
//static const ll MOD = 1;

///////////////////////////////////////////////
//Graph
/////////////////////////
//Warshal Floyid/////////
/////////////////////////
//initialize`
//rep(i, 0, N)rep(j, 0, N) wf[i][j] = 1 << 29;
//static const ll WF_MAX = 300;
//ll wf[WF_MAX][WF_MAX];
//void WarshalFloyid(int size) {
//	rep(k, 0, size)rep(i, 0, size)rep(j, 0, size)wf[i][j] = min(wf[i][j], wf[i][k] + wf[k][j]);
//}

////////////
///dijkstra
///////////
//ll N;
//static const ll MAX = 100001;
//static const ll INFTY = (ll)1 << 55;
//static const int WHITE = 1;
//static const int GRAY = 2;
//static const int BLACK = 3;
//vector<pair<int, int>>adj[MAX];
//ll d[MAX];
//ll pre[MAX];
//
//priority_queue<pair<int, int>>PQ;
//int color[MAX];
//ll n;
//void dijkstra(ll x) {
//	repe(i, 1, n) {
//		d[i] = INFTY;
//		color[i] = WHITE;
//	}
//
//	d[x] = 0;
//	PQ.push(make_pair(x, x));
//	color[x] = GRAY;
//	while (!PQ.empty()) {
//		pair<ll, ll> f = PQ.top(); PQ.pop();
//		ll u = f.second;
//		color[u] = BLACK;
//
//		if (d[u] < f.first * (-1))continue;
//
//		rep(j, 0, adj[u].size()) {
//			ll v = adj[u][j].first;
//			if (color[v] == BLACK)continue;
//			if (d[v] > d[u] + adj[u][j].second) {
//				d[v] = d[u] + adj[u][j].second;
//				pre[v] = u;
//				PQ.push(make_pair(d[v] * (-1), v));
//
//				color[v] = GRAY;
//			}
//		}
//	}
//}
//vector<ll> get_path(ll t) {
//	vector<ll> path;
//	for (; t != -1; t = pre[t])path.push_back(t);
//	reverse(path.begin(), path.end());
//	return path;
//}

//Belmonford
// 隣接リストで使う辺を表す型
//
//struct Edge {
//	ll to, cost;  // 辺の接続先頂点, 辺の重み
//	Edge(int to, int cost) : to(to), cost(cost) {}  // コンストラクタ
//};
//
//typedef vector<vector<Edge>> AdjList;  // 隣接リストの型
//
//AdjList graph;  // グラフの辺を格納した構造体
//				// graph[v][i]は頂点vから出るi番目の辺Edge
//
//vector<ll> dist; // 最短距離
//				  // 戻り値がtrueなら負の閉路を含む
//bool bellman_ford(ll n, ll s) { // nは頂点数、sは開始頂点
//	dist = vector<ll>(n, INF);
//	dist[s] = 0; // 開始点の距離は0
//	for (int i = 0; i < n; i++) {
//		for (int v = 0; v < n; v++) {
//			for (int k = 0; k < graph[v].size(); k++) {
//				Edge e = graph[v][k];
//				if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
//					dist[e.to] = dist[v] + e.cost;
//					//	cout << "update" << endl;
//					if (i == n - 1) {
//						//cout << "inf" << endl;
//						return true;
//						//return true; // n回目にも更新があるなら負の閉路が存在
//					}
//				}
//			}
//		}
//	}
//	return false;
//}

//Prim
//Krascal

///////////////////////////
////Prime Creator//////////
///////////////////////////
//bool Prime[100001] = {};
//void createPrime() {
//	ll n = 100001;
//	rep(i, 0, n) Prime[i] = true;
//	Prime[0] = false;
//	Prime[1] = false;
//	rep(i, 2, n) {
//		if (Prime[i]) {
//			rep(j, 2, n) {
//				if (j*i >= n)break;
//				Prime[j*i] = false;
//			}
//		}
//	}
//}
///////////////////////////
///////////////////////////

////Combination 1
//static const long long N = 100000;
//ll Combination(ll n, ll r)
//{
//	ll result = 1;
//	if (n < 0 || r < 0 || r > n) {
//		return -1;
//	}
//
//	if (n - r < r) r = n - r;
//	if (r == 0) return 1;
//	if (r == 1) return n;
//
//	int numerator[N];
//	int denominator[N];
//
//	for (int k = 0; k < r; k++)
//	{
//		numerator[k] = n - r + k + 1;
//		denominator[k] = k + 1;
//	}
//
//	for (int p = 2; p <= r; p++)
//	{
//		int pivot = denominator[p - 1];
//		if (pivot > 1)
//		{
//			int offset = (n - r) % p;
//			for (int k = p - 1; k < r; k += p)
//			{
//				numerator[k - offset] /= pivot;
//				denominator[k] /= pivot;
//			}
//		}
//	}
//
//	for (int k = 0; k < r; k++)
//	{
//		if (numerator[k] > 1) {
//			result *= numerator[k];
//			//result %= 1000000007;
//		}
//	}
//
//	return result;
//}

//Combination 2
//ll fact[1000001] = {};
//static const ll COMB_SIZE = 1000000;
//void factorial(ll f) {
//	fact[0] = fact[1] = 1;
//	rep(i, 1, COMB_SIZE) fact[i] = fact[i - 1] * i % MOD;
//}
//ll POW(ll n, ll p) {
//	if (p == 0)return 1;
//	if (p == 1)return n;
//
//	ll t = POW(n, p / 2);
//	if (p & 1) return (t * t % MOD) * n % MOD;
//	else return t * t % MOD;
//}
//
//ll Combination(ll n, ll r) {
//	return ((fact[n] * (POW(fact[r], MOD - 2) % MOD)) % MOD * POW(fact[n - r], MOD - 2)) % MOD;
//}

//unionfind
//static const ll UF_SIZE = 100000;
//ll par[UF_SIZE];
//ll lev[UF_SIZE];
//
//void init(ll n) {
//	rep(i, 0, n) {
//		par[i] = i;
//		lev[i] = 0;
//	}
//}
//
//ll find(ll x) {
//	if (par[x] == x)return x;
//	else return par[x] = find(par[x]);
//}
//
//void unite(ll x, ll y) {
//	x = find(x);
//	y = find(y);
//	if (x == y)return;
//
//	if (lev[x] < lev[y]) {
//		par[x] = y;
//	}
//	else {
//		par[y] = x;
//		if (lev[x] == lev[y])lev[x]++;
//	}
//}
//
//bool same(ll x, ll y) {
//	return find(x) == find(y);
//}

//DFS

//BFS
//ll fact[1000001] = {};
//static const ll COMB_SIZE = 1000000;
//void factorial(ll f) {
//	fact[0] = fact[1] = 1;
//	rep(i, 1, COMB_SIZE) fact[i] = fact[i - 1] * i % MOD;
//}
//ll POW(ll n, ll p) {
//	if (p == 0)return 1;
//	if (p == 1)return n;
//
//	ll t = POW(n, p / 2);
//	if (p & 1) return (t * t % MOD) * n % MOD;
//	else return t * t % MOD;
//}
//
//ll Combination(ll n, ll r) {
//	return ((fact[n] * (POW(fact[r], MOD - 2) % MOD)) % MOD * POW(fact[n - r], MOD - 2)) % MOD;
//}

int main() {
	ll H, W; cin >> H >> W;
	char a[100][100] = {};
	bool h[100] = {};
	bool w[100] = {};
	char hc[100] = {};
	char wc[100] = {};

	rep(i, 0, H) {
		bool space = true;

		rep(j, 0, W) {
			cin >> a[i][j];
			space &= (a[i][j] == '.');
		}

		h[i] = space;
	}
	rep(i, 0, W) {
		bool space = true;
		rep(j, 0, H) {
			space &= (a[j][i] == '.');
		}
		w[i] = space;
	}
	rep(i, 0, H) {
		bool write = false;
		rep(j, 0, W) {
			if (!h[i] && !w[j]) {
				cout << a[i][j];
				write = true;
			}
		}
		if (write)		cout << endl;
	}

	return 0;
}