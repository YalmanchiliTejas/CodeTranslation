#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<stack>
#include<unordered_map>
#include<bitset>
#include<limits>
#include<complex>
#include<array>
using namespace std;
#define rrep(i,m,n) for(int (i)=(int)(m);(i)>=(int)(n);(i)--)
#define rep(i,m,n) for(int (i)=(int)(m);i<(int)(n);i++)
#define REP(i,n) rep(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
#define M_PI 3.1415926535897932LL;
typedef pair<ll, ll> P;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;
constexpr long double EPS = 1e-10;
typedef vector<ll> Array;
typedef vector<Array> Matrix;
string operator*(const string& s, int k) {
	if (k == 0) return "";
	string p = (s + s) * (k / 2);
	if (k % 2 == 1) p += s;
	return p;
}

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

struct Edge {//グラフ
	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {//最大フロー求める Ford-fulkerson
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));//最小カットの場合逆辺は0にする
}

ll max_flow_dfs(Graph& G, ll v, ll t, ll f, vector<bool>& used)
{
	if (v == t)
		return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); ++i) {
		Edge& e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
			ll d = max_flow_dfs(G, e.to, t, min(f, e.cap), used);
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
//二分グラフの最大マッチングを求めたりも出来る　また二部グラフの最大独立集合は頂点数-最大マッチングのサイズ
ll max_flow(Graph& G, ll s, ll t)//O(V(V+E))
{
	ll flow = 0;
	for (;;) {
		vector<bool> used(G.size());
		REP(i, used.size())used[i] = false;
		ll f = max_flow_dfs(G, s, t, INF, used);
		if (f == 0) {
			return flow;
		}
		flow += f;
	}
}
void BellmanFord(Graph& G, ll s, Array& d, Array& negative) {//O(|E||V|)
	d.resize(G.size());
	negative.resize(G.size());
	REP(i, d.size())d[i] = INF;
	REP(i, d.size())negative[i] = false;
	d[s] = 0;
	REP(k, G.size() - 1) {
		REP(i, G.size()) {
			REP(j, G[i].size()) {
				if (d[i] != INF && d[G[i][j].to] > d[i] + G[i][j].cap) {
					d[G[i][j].to] = d[i] + G[i][j].cap;
				}
			}
		}
	}
	REP(k, G.size() - 1) {
		REP(i, G.size()) {
			REP(j, G[i].size()) {
				if (d[i] != INF && d[G[i][j].to] > d[i] + G[i][j].cap) {
					d[G[i][j].to] = d[i] + G[i][j].cap;
					negative[G[i][j].to] = true;
				}
				if (negative[i] == true)negative[G[i][j].to] = true;
			}
		}
	}
}

void Dijkstra(Graph& G, ll s, Array& d) {//O(|E|log|V|)
	d.resize(G.size());
	REP(i, d.size())d[i] = INF;
	d[s] = 0;
	priority_queue<P, vector<P>, greater<P>> q;
	q.push(make_pair(0, s));
	while (!q.empty()) {
		P a = q.top();
		q.pop();
		if (d[a.second] < a.first)continue;
		REP(i, G[a.second].size()) {
			Edge e = G[a.second][i];
			if (d[e.to] > d[a.second] + e.cap) {
				d[e.to] = d[a.second] + e.cap;
				q.push(make_pair(d[e.to], e.to));
			}
		}
	}
}
void WarshallFloyd(Graph& G, Matrix& d) {//O(V^3)
	d.resize(G.size());
	REP(i, d.size())d[i].resize(G.size());
	REP(i, d.size()) {
		REP(j, d[i].size()) {
			d[i][j] = ((i != j) ? INF : 0);
		}
	}
	REP(i, G.size()) {
		REP(j, G[i].size()) {
			chmin(d[i][G[i][j].to], G[i][j].cap);
		}
	}
	REP(i, G.size()) {
		REP(j, G.size()) {
			REP(k, G.size()) {
				chmin(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}
}
bool tsort(Graph& graph, vector<int>& order) {//トポロジカルソートO(E+V)
	int n = graph.size(), k = 0;
	Array in(n);
	for (auto& es : graph)
		for (auto& e : es)in[e.to]++;
	priority_queue<ll, Array, greater<ll>> que;
	REP(i, n)
		if (in[i] == 0)que.push(i);
	while (que.size()) {
		int v = que.top();
		que.pop();
		order.push_back(v);
		for (auto& e : graph[v])
			if (--in[e.to] == 0)que.push(e.to);
	}
	if (order.size() != n)return false;
	else return true;
}
class lca {
public:
	const int n = 0;
	const int log2_n = 0;
	std::vector<std::vector<int>> parent;
	std::vector<int> depth;

	lca() {}

	lca(const Graph& g, int root)
		: n(g.size()), log2_n(log2(n) + 1), parent(log2_n, std::vector<int>(n)), depth(n) {
		dfs(g, root, -1, 0);
		for (int k = 0; k + 1 < log2_n; k++) {
			for (int v = 0; v < (int)g.size(); v++) {
				if (parent[k][v] < 0)
					parent[k + 1][v] = -1;
				else
					parent[k + 1][v] = parent[k][parent[k][v]];
			}
		}
	}

	void dfs(const Graph& g, int v, int p, int d) {
		parent[0][v] = p;
		depth[v] = d;
		for (auto& e : g[v]) {
			if (e.to != p) dfs(g, e.to, v, d + 1);
		}
	}

	int get(int u, int v) {
		if (depth[u] > depth[v]) std::swap(u, v);
		for (int k = 0; k < log2_n; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				v = parent[k][v];
			}
		}
		if (u == v) return u;
		for (int k = log2_n - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
};
void visit(const Graph& g, int v, Matrix& scc, stack<ll>& S, Array& inS, Array& low, Array& num, int& time) {
	low[v] = num[v] = ++time;
	S.push(v); inS[v] = true;
	FOR(e, g[v]) {
		int w = e->to;
		if (num[w] == 0) {
			visit(g, w, scc, S, inS, low, num, time);
			low[v] = min(low[v], low[w]);
		}
		else if (inS[w])
			low[v] = min(low[v], num[w]);
	}
	if (low[v] == num[v]) {
		scc.push_back(Array());
		while (1) {
			int w = S.top(); S.pop(); inS[w] = false;
			scc.back().push_back(w);
			if (v == w) break;
		}
	}
}
void stronglyConnectedComponents(const Graph& g, Matrix& scc) {//強連結成分分解 O(E+V)
	const int n = g.size();
	Array num(n), low(n);
	stack<ll> S;
	Array inS(n);
	int time = 0;
	REP(u, n) if (num[u] == 0)
		visit(g, u, scc, S, inS, low, num, time);
}

class UnionFind {
	vector<int> data;
	ll num;
public:
	UnionFind(int size) : data(size, -1), num(size) { }
	bool unite(int x, int y) {//xとyの集合を統合する
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		num -= (x != y);
		return x != y;
	}
	bool findSet(int x, int y) {//xとyが同じ集合か返す
		return root(x) == root(y);
	}
	int root(int x) {//xのルートを返す
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	ll size(int x) {//xの集合のサイズを返す
		return -data[root(x)];
	}
	ll numSet() {//集合の数を返す
		return num;
	}
};
class SumSegTree {
private:

	ll _sum(ll a, ll b, ll k, ll l, ll r) {
		if (r <= a || b <= l)return 0;    // 交差しない
		if (a <= l && r <= b)return dat[k];   // a,l,r,bの順で完全に含まれる
		else {
			ll s1 = _sum(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子
			ll s2 = _sum(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子
			return s1 + s2;
		}
	}
public:
	ll n, height;
	vector<ll> dat;

	// 初期化（_nは最大要素数）
	SumSegTree(ll _n) {
		n = 1;
		height = 1;
		while (n < _n) {
			n *= 2;
			height++;
		}
		dat = vector<ll>(2 * n - 1, 0);
	}

	// 場所i(0-indexed)にxを足す
	void add(ll i, ll x) {
		i += n - 1; // i番目の葉ノードへ
		dat[i] += x;
		while (i > 0) { // 下から上がっていく
			i = (i - 1) / 2;
			dat[i] += x;
		}
	}

	// 区間[a,b)の総和。ノードk=[l,r)に着目している。
	ll sum(ll a, ll b) {
		return _sum(a, b, 0, 0, n);
	}
};
class RmqTree {
private:

	ll _find(ll a, ll b, ll k, ll l, ll r) {
		if (r <= a || b <= l)return INF;    // 交差しない
		if (a <= l && r <= b)return dat[k];   // a,l,r,bの順で完全に含まれる
		else {
			ll s1 = _find(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子
			ll s2 = _find(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子
			return min(s1, s2);
		}
	}
public:
	ll n, height;
	vector<ll> dat;

	// 初期化（_nは最大要素数）
	RmqTree(ll _n) {
		n = 1;
		height = 1;
		while (n < _n) {
			n *= 2;
			height++;
		}
		dat = vector<ll>(2 * n - 1, INF);
	}

	// 場所i(0-indexed)をxにする
	void update(ll i, ll x) {
		i += n - 1; // i番目の葉ノードへ
		dat[i] = x;
		while (i > 0) { // 下から上がっていく
			i = (i - 1) / 2;
			dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
		}
	}

	// 区間[a,b)の最小値。ノードk=[l,r)に着目している。
	ll find(ll a, ll b) {
		return _find(a, b, 0, 0, n);
	}
};


//約数求める //約数
void divisor(ll n, vector<ll>& ret) {
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(ret.begin(), ret.end());
}

void divisor_prime(ll n, vector<P>& ret) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back({ i,0 });
			while (n % i == 0) {
				n /= i;
				ret[ret.size() - 1].second++;
			}
		}
	}
	if (n != 1)ret.push_back({ n,1 });
}


ll mod_pow(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

ll mod_inv(ll x, ll mod) {
	return mod_pow(x, mod - 2, mod);
}
//nCrとか
class Combination {
public:
	Array fact;
	Array inv;
	ll mod;
	ll mod_inv(ll x) {
		ll n = mod - 2LL;
		ll res = 1LL;
		while (n > 0) {
			if (n & 1) res = res * x % mod;
			x = x * x % mod;
			n >>= 1;
		}
		return res;
	}
	//if n >= mod use lucas 
	ll nCr(ll n, ll r) {
		if (n < r)return 0;
		if (n < mod)return ((fact[n] * inv[r] % mod) * inv[n - r]) % mod;
		
		ll ret = 1;
		while (n || r) {
			ll _n = n % mod, _r = r % mod;
			n /= mod; r /= mod;
			(ret *= nCr(_n, _r)) %= mod;
		}
		return ret;
	}
	ll nPr(ll n, ll r) {
		return (fact[n] * inv[n - r]) % mod;
	}
	ll nHr(ll n, ll r) {
		return nCr(r + n - 1, r);
	}
	Combination(ll _n, ll _mod) {
		mod = _mod;
		ll n = min(_n+1, mod);
		fact.resize(n);
		fact[0] = 1;
		REP(i, n-1) {
			fact[i + 1] = (fact[i] * (i + 1LL)) % mod;
		}
		inv.resize(n);
		inv[n-1] = mod_inv(fact[n-1]);
		for (int i = n-1; i > 0; i--) {
			inv[i - 1] = inv[i] * i % mod;
		}
	}
};

ll gcd(ll m, ll n) {
	if (n == 0)return m;
	return gcd(n, m % n);
}//gcd

ll lcm(ll m, ll n) {
	return m / gcd(m, n) * n;
}

ll popcount(ll x) {
	x = (x & 0x5555555555555555) + (x >> 1 & 0x5555555555555555);
	x = (x & 0x3333333333333333) + (x >> 2 & 0x3333333333333333);
	x = (x & 0x0F0F0F0F0F0F0F0F) + (x >> 4 & 0x0F0F0F0F0F0F0F0F);
	x = (x & 0x00FF00FF00FF00FF) + (x >> 8 & 0x00FF00FF00FF00FF);
	x = (x & 0x0000FFFF0000FFFF) + (x >> 16 & 0x0000FFFF0000FFFF);
	x = (x & 0x00000000FFFFFFFF) + (x >> 32 & 0x00000000FFFFFFFF);

	return x;
}




ll dp[3030][6030];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	

	constexpr ll mod = 998244353;
	ll n, s;
	cin >> n >> s;
	Array a(n);
	REP(i, n)cin >> a[i];
	ll ans = 0;
	dp[0][0] = 1;
	REP(i, n) {
		REP(j, 3030) {
			if(j==0)(dp[i + 1][j + a[i]] += dp[i][j] * (i + 1) % mod) %= mod;
			else (dp[i + 1][j + a[i]] += dp[i][j] % mod) %= mod;
			(dp[i + 1][j] += dp[i][j]) %= mod;
			if (j + a[i] == s) {
				if (j != 0)(ans += dp[i][j] * (n - i) % mod) %= mod;
				else (ans += (i + 1) * (n - i)) %= mod;
			}
		}
	}
	cout << ans << endl;

	return 0;
}
