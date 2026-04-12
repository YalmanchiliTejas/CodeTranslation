#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <set>
#include <vector>
#include <queue>
using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)

static const double PI = 3.1415926535897932384626433;
static const ll LL_MAX = (ll)1 << 55;
static const ll MOD = 1000000007;
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

/////////////////////////
//Warshal Floyid/////////
/////////////////////////
//initialize
//
//static const ll LL_MAX = (ll)1 << 55;
//static const ll WF_MAX = 300;
//
//ll wf[WF_MAX][WF_MAX];
//void WarshalFloyid(int size) {
//	rep(k, 0, size)rep(i, 0, size)rep(j, 0, size)wf[i][j] = min(wf[i][j], wf[i][k] + wf[k][j]);
//}
//
////Bellmon ford
//// 隣接リストで使う辺を表す型
//struct Edge {
//	ll to, cost;  // 辺の接続先頂点, 辺の重み
//	Edge(ll to, ll cost) : to(to), cost(cost) {}  // コンストラクタ
//};
//typedef vector<vector<Edge> > AdjList;  // 隣接リストの型
//AdjList graph;  // グラフの辺を格納した構造体
//				// graph[v][i]は頂点vから出るi番目の辺Edge
//static const ll INF = (ll)1 << 55;
//vector<ll> dist; // 最短距離
//
//// 戻り値がtrueなら負の閉路を含む
//bool bellman_ford(int n, int s) { // nは頂点数、sは開始頂点
//	dist = vector<ll>(n, INF);
//	dist[s] = 0; // 開始点の距離は0
//	for (int i = 0; i < n; i++) {
//		for (int v = 0; v < n; v++) {
//			for (int k = 0; k < graph[v].size(); k++) {
//				Edge e = graph[v][k];
//				if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
//					dist[e.to] = dist[v] + e.cost;
//					if (i == n - 1) {
//						return true;
//					}
//				}
//			}
//		}
//	}
//	return false;
//}

//RMQ Segment Tree
//const int MAX_N = 1 << 17;
//int n, dat[2 * MAX_N - 1];
//
//void init(int n_) {
//	n = 1;
//	while (n < n_) n *= 2;
//	rep(i, 0, 2 * n - 1) dat[i] = INT_MAX;
//}
//
//void update(int k, int a) {
//	k += n - 1;
//	dat[k] = a;
//	while (k > 0) {
//		k = (k - 1) / 2;
//		dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
//	}
//}
//
//int query(int a, int b, int k, int l, int r) {
//	if (r <= a || b <= l) return INT_MAX;
//
//	if (a <= l && r <= b)return dat[k];
//	else {
//		int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
//		int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
//		return min(vl, vr);
//	}
//}
//
//int main() {
//	init(8);
//
//	update(0, 5);
//	update(1, 3);
//	update(2, 7);
//	update(3, 9);
//	update(4, 6);
//	update(5, 4);
//	update(6, 1);
//	update(7, 2);
//
//	cout << query(0, 6, 0, 0, n - 1) << endl;
//	return 0;
//}

//BIT Binary Index Tree
//int bit[MAX_N + 1], n;
//int sum(int i) {
//	int s = 0;
//	while (i > 0) {
//		s += bit[i];
//		i -= i;
//	}
//	return s;
//}
//void add(int i, int x) {
//	while (i <= n) {
//		bit[i] += x;
//		i += i & -i;
//	}
//}

//union find
//static const ll MAX_N = 200000;
//ll par[MAX_N];
//ll ran[MAX_N];
//
//void init(ll n) {
//	rep(i, 0, n) {
//		par[i] = i;
//		ran[i] = 0;
//	}
//}
//
//ll find(ll x) {
//	if (par[x] == x)  return x;
//	else return par[x] = find(par[x]);
//}
//
//void unite(ll x, ll y) {
//	x = find(x);
//	y = find(y);
//	if (x == y) return;
//
//	if (ran[x] < ran[y]) {
//		par[x] = y;
//	}
//	else {
//		par[y] = x;
//		if (ran[x] == ran[y]) ran[x]++;
//	}
//}
//bool same(ll x, ll y) {
//	return find(x) == find(y);
//}

//////////
//dijkstra
/////////
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
//cin >> n;
//rep(i, 0, n - 1) {
//	ll a, b, c; cin >> a >> b >> c;
//	adj[a].push_back(make_pair(b, c));
//	adj[b].push_back(make_pair(a, c));
//}
//Topological Sort
//
//ll n, m, x, y, bit[20];
//ll dp[1 << 20];
//int main() {
//	cin >> n >> m; dp[0] = 1;
//	rep(i, 0, m) {
//		cin >> x >> y;
//		bit[y - 1] |= (1 << (x - 1));
//	}
//
//	rep(i, 1, 1 << n) {
//		rep(j, 0, n) {
//			if ((i & (i << j)) && (i | bit[j]) == i) {
//				dp[i] += dp[i - (i << j)];
//			}
//		}
//	}
//
//	return 0;
//}
//vector<int> L[101010];
//vector<int> T[101010];
//
//void createTree(int v, int p) {
//	for (int ne : L[v]) {
//		if (ne == p)continue;
//		T[v].push_back(ne);
//		createTree(ne, v);
//	}
//}
//
//ll dp[101010][2];
//int rec(int v, int color) {
//	if (dp[v][color] != -1)return dp[v][color];
//
//	int res = 1;
//	for (int ne : T[v]) {
//		if (color == 0) {
//			res *= rec(ne, 1);
//		}
//		else {
//			res *= rec(ne, 0) + rec(ne, 1);
//		}
//		res %= MOD;
//	}
//	return dp[v][color] = res;
//}
//
//int main() {
//	ll N; cin >> N;
//	rep(i, 0, N - 1) {
//		ll a, b; cin >> a >> b;
//		a--; b--;
//		L[a].push_back(b);
//		L[b].push_back(a);
//	}
//
//	createTree(0, -1);
//
//	rep(i, 0, 101010)rep(j, 0, 2)dp[i][j] = -1;
//	cout << (rec(0, 0) + rec(0, 1)) % MOD << endl;
//
//	return 0;
//}
//Combination
//ll POW(ll n, ll p) {
//	if (p == 0)return 1;
//	if (p == 1)return n;
//
//	ll t = POW(n, p / 2);
//	if (p & 1) return (t * t % MOD) * n % MOD;
//	else return t * t % MOD;
//}
//ll fact[1000001] = {};
//static const ll COMB_SIZE = 1000000;
//void factorial(ll f) {
//	fact[0] = fact[1] = 1;
//	rep(i, 1, COMB_SIZE) fact[i] = fact[i - 1] * i % MOD;
//}
//ll Combination(ll n, ll r) {
//	return ((fact[n] * (POW(fact[r], MOD - 2) % MOD)) % MOD * POW(fact[n - r], MOD - 2)) % MOD;
//}
//factorial(500000);
//
//static const ll MAX_N = 200000;
//ll par[MAX_N];
//ll ran[MAX_N];
//
//void init(ll n) {
//	rep(i, 0, n) {
//		par[i] = i;
//		ran[i] = 0;
//	}
//}
//
//ll find(ll x) {
//	if (par[x] == x)  return x;
//	else return par[x] = find(par[x]);
//}
//
//void unite(ll x, ll y) {
//	x = find(x);
//	y = find(y);
//	if (x == y) return;
//
//	if (ran[x] < ran[y]) {
//		par[x] = y;
//	}
//	else {
//		par[y] = x;
//		if (ran[x] == ran[y]) ran[x]++;
//	}
//}
//bool same(ll x, ll y) {
//	return find(x) == find(y);
//}
//
//ll A[200001] = {};
//ll B[200001] = {};
//ll S[200001] = {};
//int main() {
//	ll N; cin >> N;
//	rep(i, 0, N) {
//		ll a; cin >> a;
//		A[i] = a;;
//		S[i] = S[i - 1] + a;
//	}
//
//	ll minv = LL_MAX;
//	rep(k, 1, N - 1) {
//		ll m = S[k] / 2;
//		ll ub = k, lb = 0;
//		ll mid1;
//		rep(b, 0, 100) {
//			mid1 = (lb + ub) / 2;
//			if (S[mid1] - m > 0) {
//				ub = mid1;
//			}
//			else {
//				lb = mid1;
//			}
//		}
//		ll t = S[k] - S[mid1];
//		ll s = S[mid1];
//		//cout << "k " << k << " S[k] " << S[k] << " mid " << mid1 << " S[k] - S[mid - 1] " << t << " S[mid] " << s << endl;
//		cout << "k " << k << " S[k]: " << S[k] << " mid : " << mid1 << " t: " << t << " s: " << s << endl;
//
//		//debug
//		rep(i, 0, N) {
//			if (i <= k) B[i] = 0;
//			else  B[i] = S[i] - S[k];
//		}
//		//debug
//
//		m = B[N - 1] / 2;
//		ub = N, lb = k;
//		ll mid2;
//		rep(b, 0, 100) {
//			mid2 = (lb + ub) / 2;
//			if (B[mid2] - m > 0) {
//				ub = mid2;
//			}
//			else {
//				lb = mid2;
//			}
//		}
//		mid2++;
//		ll q = B[N - 1] - B[mid2];
//		ll r = B[mid2];
//		cout << "k " << k << " S[k]: " << S[k] << " mid2: " << mid2 << " q: " << q << " r: " << r << endl;
//
//		ll z = max(max(max(s, t), q), r) - min(min(min(s, t), q), r);
//		cout << "diff : " << z << endl;
//		minv = min(max(max(max(s, t), q), r) - min(min(min(s, t), q), r), minv);
//		cout << "minv : " << minv << endl;
//		cout << endl;
//	}
//	cout << minv << endl;
//
//	return 0;
//}

string s;
string t;
ll N;

ll check() {
	rep(i, 1, N) {
		if (s[i] == 'o') {
			if (t[i - 1] == 'S' && t[i] == 'S') t += 'S';
			else if (t[i - 1] == 'S' && t[i] == 'W') t += 'W';
			else if (t[i - 1] == 'W' && t[i] == 'W') t += 'S';
			else if (t[i - 1] == 'W' && t[i] == 'S') t += 'W';
		}
		else if (s[i] == 'x') {
			if (t[i - 1] == 'S' && t[i] == 'S') t += 'W';
			else if (t[i - 1] == 'S' && t[i] == 'W') t += 'S';
			else if (t[i - 1] == 'W' && t[i] == 'W') t += 'W';
			else if (t[i - 1] == 'W' && t[i] == 'S') t += 'S';
		}
	}

	if (t[0] == t[N]) {
		if (s[0] == 'o') {
			if (t[0] == 'S' && t[1] == t[N - 1] || t[0] == 'W' && t[1] != t[N - 1]) {
				cout << t.substr(0, N) << endl;
				exit(0);
			}
		}
		else if (s[0] == 'x') {
			if (t[0] == 'S' && t[1] != t[N - 1] || t[0] == 'W' && t[1] == t[N - 1]) {
				cout << t.substr(0, N) << endl;
				exit(0);
			}
		}
	}
}

int main() {
	cin >> N;
	cin >> s;

	t = "SS";
	check();
	t = "SW";
	check();
	t = "WS";
	check();
	t = "WW";
	check();

	cout << -1 << endl;

	return 0;
}