#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>
#include<iomanip>
#include<limits>
#include<deque>
#include<map>
#include<list>
#include<set>
#include <unordered_set>
#include<vector>
#include<cmath>
#include<cstdio>
#include<memory>
#include<bitset>
#include<stack>
#include<functional>
#include<queue>
#include<regex>
#include<time.h>
#include<type_traits>
#include<cstdlib>
#include <utility>

using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;//良く出てくるMOD
constexpr ll INF = 1050000000;//intで使うでかい数
constexpr ll LONGINF = 1050000000000000000;//longlongで使うでかい数
const int nCk_MAX = 510000;//nCkの前計算で使うかもしれない 普段は入ってないよ

struct all_init {
	//初期化のためだけの構造体
	//コンストラクタが呼ばれ、cin,cout高速化がされる
	//ついでに少数も出力できるようにしている
	all_init() {
		cout.tie(nullptr);
		cin.tie(nullptr);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(15);
	};
}ALL_INIT;
struct edge {
	//辺の重みを管理できるような構造体
	//コンストラクタによって簡単に値を入れられるようにしている
	//operatorは辺の重みでソート出来るようにしている

	int from, to;
	ll cost;
	ll capa;

	edge(int s, int d) : from(s), to(d) {
		cost = 0; capa = 0; 
	}
	edge(int s, int d, ll w) : from(s), to(d), cost(w) { capa = 0;}
	edge(int s, int d, ll x, ll y) :from(s), to(d), cost(x), capa(y) {  }

	bool operator < (const edge& x) const {
		return cost < x.cost;
	}
};

#define CIN(vector_array_etc,n) for(int loop=0;loop<n;loop++){cin>>vector_array_etc[loop];}
#define COUT(vector_array_etc,n) for(int LOOP=0;LOOP<n;LOOP++){cout<<vector_array_etc[LOOP]<<(LOOP == n-1 ?'\n':' ');}
#define VC(Type_name) vector<Type_name>//1次元ならあまり意味ないかも
#define VCVC(Type_name) vector<vector<Type_name>>//2次元配列定義怠過ぎ問題
#define SORT(vector_etc) sort(vector_etc.begin(),vector_etc.end())
#define ALL(vec_etc) vec_etc.begin(),vec_etc.end()

template<class T>bool chmax(T &a, const T &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}//aに最大値が入る
template<class T>bool chmin(T &a, const T &b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}//aに最小値が入る
template<typename T>
istream& operator >> (istream& is, vector<T>& Vec) {
	for (T& x : Vec) { is >> x; }
	return is;
}
template<typename V, typename H>
void resize(vector<V>& vec, const H head) {
	vec.resize(head);
}
template<typename V, typename H, typename ... T>
void resize(vector<V>& vec, const H& head, const T ... tail) {
	vec.resize(head);
	for (auto& v : vec) { resize(v, tail...); }
}

int dx[] = { 0,1,-1, 0,1,-1, 1,-1 };    //i<4:4way i<8:8way
int dy[] = { 1,0, 0,-1,1,-1,-1, 1 };

ll PowMod(ll n, ll k, ll mod) {
	//繰り返し2乗法
	//n^kをmodで求める
	ll r = 1;

	for (; k > 0; k >>= 1) {
		if (k & 1) {
			r = (r * n) % mod;
		}
		n = (n * n) % mod;
	}
	return r;
}
ll Gcd(ll a, ll b) {//最大公約数
	return b != 0 ? Gcd(b, a % b) : a;
}
ll Lcm(ll a, ll b) {//最小公倍数
	return a / Gcd(a, b) * b;
}
bool isPrime(ll n) {
	//素数かどうかを判定
	//true 素数
	if (n < 2)return false;
	for (ll i = 2; i*i <= n; i++)if (!(n%i))return false;
	return true;
}
ll MergeCount(vector<int> &a) {
	//反転数を数える
	ll count = 0;
	int n = a.size();
	if (n > 1) {
		vector<int> b(a.begin(), a.begin() + n / 2);
		vector<int> c(a.begin() + n / 2, a.end());
		count += MergeCount(b);
		count += MergeCount(c);
		for (int i = 0, j = 0, k = 0; i < n; ++i)
			if (k == c.size())       a[i] = b[j++];
			else if (j == b.size())  a[i] = c[k++];
			else if (b[j] <= c[k])   a[i] = b[j++];
			else { a[i] = c[k++]; count += n / 2 - j; }
	}
	return count;
}
bool  WarshallFloyd(vector<vector<ll>> &c) {
	//ワーシャルフロイド法
	//全ての頂点間の最短距離を求める
	//falseの時、負の閉路検出
	int V = c.size();
	for (int i = 0; i < V; i++) {
		c[i][i]=0;
	}

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			for (int k = 0; k < V; k++) {
				if (c[j][k] > c[j][i] + c[i][k]) {
					c[j][k] = c[j][i] + c[i][k];
				}
			}
		}
	}

	for (int i = 0; i < V; i++) {
		if (c[i][i] < 0) {
			return false;
		}
	}



	return true;
}
vector<ll> Dijkstra(int i, vector<vector<edge>> graph) {
	//i:始点
	//graph:重み付きグラフ
	int n = graph.size();
	vector<ll> d(n, LONGINF);
	d[i] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
	q.push(make_pair(0, i));//第一引数:コスト 第二引数:頂点
	while (!q.empty()) {
		pair<ll, int> p = q.top();
		q.pop();
		int v = p.second;
		if (d[v] < p.first) {
			continue;
		}
		for (auto x : graph[v]) {
			if (d[x.to] > d[v] + x.cost) {
				d[x.to] = d[v] + x.cost;
				q.push(make_pair(d[x.to], x.to));
			}
		}
	}
	return d;
}
bool BellmanFord(int start, int V, int E, vector<edge> Edge, vector<ll> &d) {
	//第一引数:start 始点
	//第二引数:V 頂点数
	//第三引数:E 辺の数
	//第四引数:Edge 辺の重み付きのグラフ
	//第五引数:d 各頂点への距離を入れる配列(答えが入る)
	resize(d, V);
	fill(d.begin(), d.end(), LONGINF);
	d[start] = 0;
	vector<bool> t(V, false);

	for (int i = 0; i < V - 1; i++) {
		for (int j = 0; j < E; j++) {
			edge e = Edge[j];
			if (d[e.from] == LONGINF) { continue; }
			if (d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
			}
		}
	}

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < E; j++) {
			edge e = Edge[j];
			if (d[e.from] == LONGINF) { continue; }
			if (d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				t[e.to] = true;
				/*
				if (i == V - 1) {//どこかに閉路があることを感知する
					return false;
				}
				*/
			}
			if (t[e.from]) {
				t[e.to] = true;
			}
		}
	}

	if (t[V - 1]) {
	//V-1は頂点番号n-1で、始点からn-1までに負の閉路を検出したい場合には、
	//コメントアウトを解除すること。
		return false;
	}

	return true;
}
bool TopologicalSort(const vector<vector<edge>> &g, vector<int> &ans) {
	//トポロジカルソート
	//trueが帰る時、トポロジカルソートが成功し、その結果がansに渡される
	//falseはトポロジカルソートの失敗
	int n = g.size(), k = 0;
	vector<int> ord(n), in(n);
	for (auto &es : g) {
		for (auto &e : es) {
			in[e.to]++;
		}
	}
	queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (in[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		ord[k++] = v;
		for (auto &e : g[v]) {
			if (--in[e.to] == 0) q.push(e.to);
		}
	}
	ans = ord;
	if (*max_element(in.begin(), in.end()) == 0) { return true; }
	return false;
}
vector<int> ArticulationNode(const vector<vector<edge>>& g) {
	//グラフの関節点を列挙する
	//最後の2行で、erace uniqueをしない場合は、その分割によって何個のグラフに分かれるかを判定できる(要チェック)。
	int n = g.size(), idx;
	vector<int> low(n), ord(n), art;
	function<void(int)> DFS = [&](int v) {
		low[v] = ord[v] = ++idx;
		for (auto& e : g[v]) {
			int w = e.to;
			if (ord[w] == 0) {
				DFS(w);
				low[v] = min(low[v], low[w]);
				if ((ord[v] == 1 && ord[w] != 2) || (ord[v] != 1 && low[w] >= ord[v])) {
					art.push_back(v);
				}
			}
			else {
				low[v] = min(low[v], ord[w]);
			}
		}
	};
	for (int u = 0; u < n; u++) {
		if (ord[u] == 0) {
			idx = 0;
			DFS(u);
		}
	}

	sort(art.begin(), art.end());//与えられた関節点をソート
	art.erase(unique(art.begin(), art.end()), art.end());//同じ関節点が複数存在することがある,

	return art;
}
vector<vector<edge>> to_roottree(const vector<vector<edge>> &g, int r) {
	int n = g.size();
	vector<vector<edge>> G(n);
	vector<int> ord(n, -1);

	queue<int> q;

	q.push(r);
	int k = 0;

	while (q.size()) {
		int u = q.front(); q.pop();

		for (auto &e : g[u]) {
			int v = e.to;
			if (ord[v] == -1) {
				ord[v] = k; k++;
				q.push(v);
				G[u].emplace_back(e);
			}
		}
	}

	return G;
}
edge TreeDiameter(const vector<vector<edge>> &g) {
	//重み付きグラフ(木)を受け取り、その木の直径を求める
	//返り値はfrom,to,costを持った構造体

	int start = 0;//どの始点から始めても良いので、0から始める

	static const auto bfs = [](const vector<vector<edge>> &g, int s, queue<int> &q, vector<ll> &dist) {
		while (!q.empty()) { q.pop(); }
		q.push(s);
		int n = g.size();
		dist.assign(n, LONGINF);
		dist[s] = 0;
		while (q.size()) {
			int u = q.front();
			q.pop();
			for (auto &e : g[u]) {
				int v = e.to;
				if (dist[v] == LONGINF) {
					dist[v] = dist[u] + e.cost;
					q.push(v);
				}
			}
		}
		return dist;
	};
	vector<ll> dist;
	queue<int> q;
	bfs(g, start, q, dist);
	int n = g.size(), u = -1, v = -1;
	for (int i = 0; i < n; i++)
		if (dist[i] != LONGINF && (u == -1 || dist[i] > dist[u])) u = i;
	bfs(g, u, q, dist);
	for (int i = 0; i < n; i++)
		if (dist[i] != LONGINF && (v == -1 || dist[i] > dist[v])) v = i;
	ll d = dist[v];
	if (u > v) swap(u, v);//念のため辞書順
	return edge(u, v, d);
}
void add_edge(vector<vector<edge>> &g, int a, int b, ll cost, ll cap) {
	g[a].emplace_back(a, b, cost, cap);
	g[b].emplace_back(b, a, cost, cap);
}

class UnionFind {
	//satanicさん作 UnionFind
	//追加機能:forest forestは、全体に含まれる木の数を表す
private:
	std::vector<int> parent;
	std::vector<int> height;
	std::vector<int> m_size;
	int forest_num;
public:
	UnionFind(int size_) : parent(size_), height(size_, 0), m_size(size_, 1) {
		forest_num = size_;
		for (int i = 0; i < size_; ++i) parent[i] = i;
	}
	void init(int size_) {
		parent.resize(size_);
		height.resize(size_, 0);
		m_size.resize(size_, 1);
		forest_num = size_;
		for (int i = 0; i < size_; ++i) parent[i] = i;
	}
	int find(int x) {
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		int t = size(x) + size(y);
		m_size[x] = m_size[y] = t;
		if (height[x] < height[y]) parent[x] = y;
		else parent[y] = x;
		if (height[x] == height[y]) ++height[x];
		forest_num--;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int size(int x) {
		if (parent[x] == x) return m_size[x];
		return size(parent[x] = find(parent[x]));
	}
	int forest() {
		return forest_num;
	}
};
class Dinic {
	//最大流を求める
private:
	int n, s, t;
	vector<int> level, prog, que;
	vector<vector<ll>> cap, flow;
	vector<vector<int>> g;
	ll inf;
public:
	Dinic(const vector<vector<edge>> &graph) :
		n(graph.size()),
		cap(n, vector<ll>(n)),//
		flow(n, vector<ll>(n)),
		g(n, vector<int>()),
		inf(LONGINF) {
		for (int i = 0; i < n; i++) {
			for (auto &e : graph[i]) {
				int u = e.from, v = e.to;
				ll c = e.capa;
				cap[u][v] += c;
				cap[v][u] += c;
				flow[v][u] += c;
				g[u].push_back(v);
				g[v].push_back(u);
			}
		}
	}
	inline ll residue(int u, int v) { return cap[u][v] - flow[u][v]; }
	ll solve(int s_, int t_) {
		this->t = t_, this->s = s_;
		que.resize(n + 1);
		ll res = 0;
		while (levelize()) {
			prog.assign(n, 0);
			res += augment(s, inf);
		}
		return res;
	}
	bool levelize() {
		int l = 0, r = 0;
		level.assign(n, -1);
		level[s] = 0;
		que[r++] = s;
		while (l != r) {
			int v = que[l++];
			if (v == t) break;
			for (const int &d : g[v])
				if (level[d] == -1 && residue(v, d) != 0) {
					level[d] = level[v] + 1;
					que[r++] = d;
				}
		}
		return level[t] != -1;
	}
	ll augment(int v, ll lim) {
		ll res = 0;
		if (v == t) return lim;
		for (int &i = prog[v]; i < (int)g[v].size(); i++) {
			const int &d = g[v][i];
			if (residue(v, d) == 0 || level[v] >= level[d]) continue;
			const ll aug = augment(d, min(lim, residue(v, d)));
			flow[v][d] += aug;
			flow[d][v] -= aug;
			res += aug;
			lim -= aug;
			if (lim == 0) break;
		}
		return res;
	}
};
class MinimumCostFlow {
private:

	using Flow = ll;
	using Cost = ll;
	struct Edge {
		int d;
		Flow c, f;
		Cost w;
		int r, is_r;
		Edge(int d_, Flow c_, Flow f_, Cost w_, int r_, bool is_r_)
			: d(d_), c(c_), f(f_), w(w_), r(r_), is_r(is_r_) {}
	};
	int n;
	vector<vector<Edge>> g;

public:

	MinimumCostFlow(int n_) : n(n_), g(vector<vector<Edge>>(n_)) {}

	void add_edge(int src, int dst, Flow cap, Cost cost) {  // 有向辺
		int rsrc = g[dst].size();
		int rdst = g[src].size();
		g[src].emplace_back(dst, cap, 0, cost, rsrc, false);
		g[dst].emplace_back(src, cap, cap, -cost, rdst, true);
	}

	Cost solve(int s, int t, Flow f) {
		Cost res = 0;

		vector<Cost> h(n + 10), dist(n);
		vector<int> prevv(n + 10), preve(n + 10);

		using pcv = pair<Cost, int>;
		priority_queue<pcv, vector<pcv>, greater<pcv> > q;
		fill(h.begin(), h.end(), 0);
		while (f > 0) {
			fill(dist.begin(), dist.end(), LONGINF);
			dist[s] = 0;
			q.emplace(0, s);
			while (q.size()) {
				Cost cd;
				int v;
				tie(cd, v) = q.top();
				q.pop();
				if (dist[v] < cd) continue;
				for (int i = 0; i < (int)(g[v].size()); ++i) {
					Edge &e = g[v][i];
					if (residue(e) == 0) continue;
					if (dist[e.d] + h[e.d] > cd + h[v] + e.w) {
						dist[e.d] = dist[v] + e.w + h[v] - h[e.d];
						prevv[e.d] = v;
						preve[e.d] = i;
						q.emplace(dist[e.d], e.d);
					}
				}
			}

			if (dist[t] == LONGINF) return -1;  // 経路が見つからなかった

			// s-t 間を最短路に沿って目一杯流す
			for (int i = 0; i < n; ++i) h[i] += dist[i];
			Flow d = f;
			for (int v = t; v != s; v = prevv[v]) {
				chmin(d, residue(g[prevv[v]][preve[v]]));
			}
			f -= d;
			res += d * h[t];
			for (int v = t; v != s; v = prevv[v]) {
				Edge &e = g[prevv[v]][preve[v]];
				e.f += d;
				g[v][e.r].f -= d;
			}
		}
		return res;
	}

	Flow residue(const Edge &e) { return e.c - e.f; }

	// 流量を表示
	void show() {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < (int)(g[i].size()); ++j) {
				Edge &e = g[i][j];
				if (e.is_r) continue;
				cout << i << "->" << e.d << "(flow:" << e.f << ")" << endl;
			}
		}
	}
};
class BipartiteMatching {
private:
	int V;
	vector<int> match;
	vector<bool> used;
	vector<vector<int>> g;
	vector<pair<int, int>> match_pair;

	bool dfs(int v) {
		used[v] = true;
		for (int i = 0; i < (int)g[v].size(); i++) {
			int u = g[v][i];
			int w = match[u];
			if (w < 0 || !used[w] && dfs(w)) {
				match[v] = u;
				match[u] = v;
				match_pair.emplace_back(make_pair(u, v));
				return true;
			}
		}
		return false;
	}

public:
	BipartiteMatching(int n) {
		V = n;
		resize(match, n);
		resize(used, n);
		resize(g, n);
	}

	void add_edge(int u, int v) {
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}

	int MatchingSolve() {
		int res = 0;
		fill(match.begin(), match.end(), -1);

		for (int v = 0; v < V; v++) {
			if (match[v] < 0) {
				fill(used.begin(), used.end(), false);
				if (dfs(v)) {
					res++;
				}
			}
		}
		return res;
	}

	vector<pair<int, int>> get_pair() {
		for (auto x : match_pair) {
			cout << x.first << "  " << x.second << endl;
		}
		return match_pair;
	}

};
class Lca {
private:
	int n;
	int log2_n;
	vector<vector<int>> parent;
	vector<int> depth;

	void dfs(const vector<vector<edge>> &g, int v, int p, int d) {
		parent[0][v] = p;
		depth[v] = d;
		for (auto &e : g[v]) {
			if (e.to != p) { dfs(g, e.to, v, d + 1); }
		}
	}

public:

	Lca(const vector<vector<edge>> &g, int root) {
		n = g.size();
		log2_n = (int)log2(n) + 1;
		resize(parent, log2_n, n);
		resize(depth, n);

		dfs(g, root, -1, 0);

		for (int k = 0; k + 1 < log2_n; k++) {
			for (int v = 0; v < (int)g.size(); v++) {
				if (parent[k][v] < 0) {
					parent[k + 1][v] = -1;
				}
				else {
					parent[k + 1][v] = parent[k][parent[k][v]];
				}
			}
		}

	}

	int get_lca(int u, int v) {
		if (depth[u] > depth[v]) { swap(u, v); }//u≦v

		for (int k = 0; k < log2_n; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				v = parent[k][v];
			}
		}
		if (u == v) { return u; }

		for (int k = log2_n - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}

	int get_depth(int v) {
		return depth[v];
	}
};

vector<int> Lis(const vector<int>& a) {
	//#define index_of(as, x) distance(as.begin(), lower_bound(as.begin(), as.end(), x))
	#define index_of(as, x) distance(as.begin(), upper_bound(as.begin(), as.end(), x))
	//upper_boundを使用すると、重複を許した最長増加部分列になる
	//-1倍した値を入れれば、最長減少部分列になる
	const int n = a.size();
	vector<int> A(n, INF);
	vector<int> id(n);
	for (int i = 0; i < n; ++i) {
		id[i] = index_of(A, a[i]);
		A[id[i]] = a[i];
	}
	int m = *max_element(id.begin(), id.end());
	vector<int> b(m + 1);
	for (int i = n - 1; i >= 0; --i)
		if (id[i] == m) b[m--] = a[i];
	return b;//最長部分列のどれか1つ
}

int main() {
	int n; cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		b[i] = -a;
	}

	cout << Lis(b).size() << endl;



	return 0;
}
