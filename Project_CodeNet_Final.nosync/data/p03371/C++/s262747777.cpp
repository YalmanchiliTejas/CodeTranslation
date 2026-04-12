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

using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;//良く出てくるMOD
constexpr ll INF = 1050000000;//intで使うでかい数
constexpr ll LONGINF = 1050000000000000000;//longlongで使うでかい数

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

	edge(int s, int d, ll w) : from(s), to(d), cost(w) {}

	bool operator < (const edge& x) const {
		return cost < x.cost;
	}
};

#define CIN(vector_array_etc,n) for(int loop=0;loop<n;loop++){cin>>vector_array_etc[loop];}
#define COUT(vector_array_etc,n) for(int LOOP=0;LOOP<n;LOOP++){cout<<vector_array_etc[LOOP]<<(LOOP == n-1 ?'\n':' ');}
#define VC(Type_name) vector<Type_name>//1次元ならあまり意味ないかも
#define VCVC(Type_name) vector<vector<Type_name>>//2次元配列定義怠過ぎ問題
#define SORT(vector_etc) sort(vector_etc.begin(),vector_etc.end())

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
template<class T>void swap(T &a, const T &b) {
	T tmp = a;
	a = b;
	b = a;
	return;
}//aとbを入れ替える

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

ll POW_MOD(ll n, ll k, ll mod) {
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
ll gcd(ll a, ll b) {//最大公約数
	return b != 0 ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {//最小公倍数
	return a * b / gcd(a, b);
}
int mergecount(vector<int> &a) {
	//反転数(バブルソートの交換回数)を数える
	int count = 0;
	int n = a.size();
	if (n > 1) {
		vector<int> b(a.begin(), a.begin() + n / 2);
		vector<int> c(a.begin() + n / 2, a.end());
		count += mergecount(b);
		count += mergecount(c);
		for (int i = 0, j = 0, k = 0; i < n; ++i)
			if (k == c.size())       a[i] = b[j++];
			else if (j == b.size())  a[i] = c[k++];
			else if (b[j] <= c[k])   a[i] = b[j++];
			else { a[i] = c[k++]; count += n / 2 - j; }
	}
	return count;
}
bool isPrime(ll n) {
	//素数かどうかを判定
	//true 素数
	if (n < 2)return false;
	for (ll i = 2; i*i <= n; i++)if (!(n%i))return false;
	return true;
}
bool  Warshall_Floyd(vector<vector<ll>> &c, int V) {
	//ワーシャルフロイド法
	//全ての頂点間の最短距離を求める
	//falseの時、負の閉路検出
	for (int i = 0; i < V; i++) {
		c[i][i] = 0;
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
vector<ll> dijkstra(int i, vector<vector<edge>> graph) {
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
bool Bellman_Ford(int start, int E, int V, vector<edge> Edge, vector<ll> &d) {
	//第一引数:start 始点
	//第二引数:E 辺の数
	//第三引数:V 頂点数
	//第四引数:Edge 辺の重み付きのグラフ
	//第五引数:d 各頂点への距離を入れる配列(答えが入る)
	fill(d.begin(), d.end(), LONGINF);
	d[start] = 0;
	vector<bool> t(V, false);
	/*
	for (int i = 0; i < V - 1; i++) {
		for (int j = 0; j < E; j++) {
			edge e = Edge[j];
			if (d[e.from] == LONGINF) { continue; }
			if (d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
			}
		}
	}
	*/

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < E; j++) {
			edge e = Edge[j];
			if (d[e.from] == LONGINF) { continue; }
			if (d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				t[e.to] = true;
				if (i == V - 1) {//どこかに閉路があることを感知する
					return false;
				}
			}
			if (t[e.from]) {
				t[e.to] = true;
			}
		}
	}
	/*
	if (t[V - 1]) {
	//V-1は頂点番号n-1で、始点からn-1までに負の閉路を検出したい場合には、
	//コメントアウトを解除すること。
		return false;
	}
	*/
	return true;
}
bool topological_sort(const vector<vector<edge>> &g, vector<int> &ans) {
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
vector<int> articulationPoint(const vector<vector<edge>>& g) {
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

	sort(art.begin(), art.end());//えられた関節点をソート
	art.erase(unique(art.begin(), art.end()), art.end());//同じ関節点が複数存在することがある,

	return art;
}
edge tree_diameter(const vector<vector<edge>> &g) {
	//重み付きグラフ(木)を受け取り、その木の直径を求める
	//返り値はfrom,to,costを持った構造体

	int start = 0;//どの始点から始めても良いので、0から始める

	static const auto bfs = [](const vector<vector<edge>> &g, int s, queue<ll> &q, vector<ll> &dist) {
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
	queue<ll> q;
	bfs(g, start, q, dist);
	int n = g.size(), u = -1, v = -1;
	for (int i = 0; i < n; i++)
		if (dist[i] != LONGINF && (u == -1 || dist[i] > dist[u])) u = i;
	bfs(g, u, q, dist);
	for (int i = 0; i < n; i++)
		if (dist[i] != LONGINF && (v == -1 || dist[i] > dist[v])) v = i;
	int d = dist[v];
	if (u > v) swap(u, v);//念のため辞書順
	return edge(u, v, d);
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

int main() {
	int a, b, c; cin >> a >> b >> c;
	int x, y; cin >> x >> y;

	int MAX = max(x, y) * 2;

	int ans = INF;

	for (int i = 0; i <= MAX; i += 2) {
		int tmp = 0;
		tmp = i * c;//ABピザをi個買う

		int A = max(x - (i / 2), 0);

		tmp += A * a;//残ったやつ全てをAピザで買う

		int B = max(y - (i / 2), 0);

		tmp += B * b;//残ったやつ全てをBピザで買う


		ans = min(ans, tmp);
	}

	cout << ans << endl;

	return 0;
}