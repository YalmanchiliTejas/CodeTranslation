#include <bits/stdc++.h>
using namespace std;

#pragma region macros_and_aliases

#define rep(i, n) for(long long i = 0; i < (n); i++)
#define rrep(i, n) for(long long i = (n)-1; i > -1; i--)
#define Rep(i, m, n) for(long long i = (m); i < (n); i++)
#define rRep(i, m, n) for(long long i = (n)-1; i >= (m); i--)
#define REP(i, m, n, p) for(long long i = m; i < n; i += p)
#define foa(s, v) for(auto &s : v)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define bcnt(n) __builtin_popcountll(n)
#define endk endl
#define ednl endl
#define enld endl

using ll = long long;
using ld = long double;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using mll = map<long long, long long>;
using pll = pair<long long, long long>;
using qll = queue<long long>;
using sll = set<long long>;
using vpll = vector<pair<long long, long long>>;
template <class T = ll>
using V = vector<T>;
template <class T = ll>
using VV = V<V<T>>;
template <class T = ll>
using VVV = V<V<V<T>>>;
//昇順pq(小さい方から取り出す)
template <class T = ll>
using pqup = priority_queue<T, vector<T>, greater<T>>;
//降順pq(大きい方から取り出す)
template <class T = ll>
using pqdn = priority_queue<T>;

#pragma region debug
#define debug(var)                  \
	do {                            \
		std::cout << #var << " : "; \
		view(var);                  \
	} while(0)

template <typename T>
void view(T e) {
	std::cout << e << "\n";
}
template <typename T>
void view(const std::vector<T> &v) {
	for(const auto &e : v) {
		std::cout << e << " ";
	}
	std::cout << "\n";
}
template <typename T>
void view(const std::set<T> &s) {
	for(auto &t : s) {
		std::cout << t << " ";
	}
	std::cout << "\n";
}
template <typename T>
void view(const std::vector<std::vector<T>> &vv) {
	std::cout << "\n";
	for(const auto &v : vv) {
		view(v);
	}
}
template <typename T, typename U>
void view(const std::vector<std::pair<T, U>> &v) {
	std::cout << "\n";
	for(const auto &c : v) {
		std::cout << c.first << " " << c.second << "\n";
	}
}
template <typename T, typename U>
void view(const std::map<T, U> &m) {
	std::cout << "\n";
	for(auto &t : m) {
		std::cout << t.first << " " << t.second << "\n";
	}
}

#pragma endregion

#pragma region input
#define VEC(type, name, size) \
	vector<type> name(size);  \
	IN(name)
#define VVEC(type, name, h, w)                     \
	vector<vector<type>> name(h, vector<type>(w)); \
	IN(name)
#define INT(...)     \
	int __VA_ARGS__; \
	IN(__VA_ARGS__)
#define LL(...)            \
	long long __VA_ARGS__; \
	IN(__VA_ARGS__)
#define STR(...)        \
	string __VA_ARGS__; \
	IN(__VA_ARGS__)
#define CHAR(...)     \
	char __VA_ARGS__; \
	IN(__VA_ARGS__)
#define DOUBLE(...)     \
	double __VA_ARGS__; \
	IN(__VA_ARGS__)
#define LD(...)              \
	long double __VA_ARGS__; \
	IN(__VA_ARGS__)

template <class T>
void scan(T &a) {
	cin >> a;
}
template <class T>
void scan(vector<T> &a) {
	for(auto &i : a) scan(i);
}
template <class T, class L>
void scan(pair<T, L> &p) {
	scan(p.first);
	scan(p.second);
}
void IN() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &... tail) {
	scan(head);
	IN(tail...);
}
template <class T>
inline void print(T x) {
	cout << x << '\n';
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
	os << p.first << " " << p.second;
	return os;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
	is >> p.first >> p.second;
	return is;
}
#pragma endregion

#pragma endregion

#pragma region constants

long long const limLL = 9223372036854775807;  // POW(2,63)-1 ~ 9.22e18
long long const dekai = 3e16;
const long double pi = acos(-1);
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ddy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int mod = 1000000007;
// const int mod = 998244353;
#pragma endregion

#pragma region basic_procedure

template <class T>
inline bool isin(T x, T lef, T rig) {
	return ((lef <= x) && (x < rig));
}

template <class T>
inline bool chmin(T &a, T b) {
	if(a > b) {
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b) {
	if(a < b) {
		a = b;
		return true;
	}
	return false;
}

void Yes(bool f = 1) { cout << (f ? "Yes" : "No") << "\n"; }
void No() { cout << "No\n"; }
void YES(bool f = 1) { cout << (f ? "YES" : "NO") << "\n"; }
void NO() { cout << "NO\n"; }
void err() {
	cout << -1 << "\n";
	exit(0);
}

vector<long long> vin(long long n) {  //整数n個の入力を受け取ってベクトルに突っ込んで返す
	vector<long long> v(n);
	for(long long i = 0; i < n; i++) {
		cin >> v[i];
	}
	return v;
}

//ベクトルの出力(検証済)
// vectorの中身を出力する 答えの出力に利用可能
template <class T>
void vout(vector<T> &v, bool tate = 0) {
	if(v.size() > 0) {
		for(auto it = v.begin(); it < v.end(); it++) {
			cout << *it;
			if(it != v.end() - 1) {
				if(tate)
					cout << endl;
				else
					cout << " ";
			}
		}
	}
	cout << endl;
}

template <class T>
void add(vector<T> &v, T val) {	 //ベクトルの各要素に加算
	for(auto &a : v) a += val;
	return;
}

// vectorの中身を数える map<要素,個数>を返す
template <class T>
map<T, long long> cntv(vector<T> v) {
	map<T, long long> m;
	for(auto &g : v) {
		if(m.count(g))
			m[g]++;
		else
			m[g] = 1;
	}
	return m;
}

//配列圧縮(検証済)
//{1,36,1,3,8,-2,-92}を
//{2, 5,2,3,4, 1,  0}にする
template <class T>
vector<long long> press(vector<T> &v) {
	long long n = v.size();
	vector<long long> w(n);
	map<T, long long> m;
	for(T &p : v) m[p] = 0;
	long long i = 0;
	for(auto &p : m) {
		p.second = i;
		i++;
	}
	for(long long i = 0; i < n; i++) w.at(i) = m[v.at(i)];
	return w;
}

template <class T>
T divup(T a, T b) {
	//端数繰りあがり割り算
	assert(b != 0);
	T x = abs(a);
	T y = abs(b);
	T z = (x + y - 1) / y;
	if((a < 0 && b > 0) || (a > 0 && b < 0))
		return -z;
	else if(a == 0)
		return 0;
	else
		return z;
}

long long POW(long long a, long long n) {
	long long res = 1;
	while(n > 0) {
		if(n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

template <class T>
int sgn(T x) {	//符号関数
	if(x < 0) return -1;
	if(x == 0) return 0;
	return 1;
}

long long modpow(long long a, long long n, long long mod) {	 // a^n mod
	if(mod == 1) return 0LL;
	long long res = 1;
	while(n > 0) {
		if(n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

// a * x % mod == __gcd(a,mod)なるxを返す
// a が modの倍数でないことが条件
long long modinv(long long a, long long mod) {
	long long b = mod, u = 1, v = 0;
	while(b) {
		long long t = a / b;
		a -= t * b;
		swap(a, b);
		u -= t * v;
		swap(u, v);
	}
	u %= mod;
	if(u < 0) u += mod;
	return u;
}

vvll comb(100, vll(100, -1));
long long com(long long n, long long k) {  //普通の二項計数(overflowに注意)
	assert(n < 100 && k < 100);
	if(n < k || k < 0 || n < 0) return 0;
	if(comb[n][k] != -1) return comb[n][k];
	ll res;
	if(n - k < k)
		res = com(n, n - k);
	else if(k == 0)
		res = 1;
	else
		res = com(n - 1, k - 1) + com(n - 1, k);
	comb[n][k] = res;
	return res;
}

// nCk modを求める
const ll MAX = 5100000;
// この値は求める二項計数の値に応じて変える
// MAX=3*10^7のとき1900msほど、ほぼ比例
// MAX=5*10^6程度ならそれほど気にしなくてよい(300ms程)
long long fac[MAX], finv[MAX], inv[MAX];

void cominit() {
	// テーブルを作る前処理
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(ll i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}
long long commod(ll n, ll k) {	// 二項係数計算
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
long long pmod(ll n, ll k) {  //順列計算
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * finv[n - k] % mod;
}
long long hmod(ll n, ll k) {  // nHk計算
	// n個の区別しないoを区別するk個の箱に入れる方法の総数
	//(n+k-1)C(k-1)と等しい
	return commod(n + k - 1, n);
}
#pragma endregion

template <class T = long long>
struct edge {
	T len;
	int from;
	int to;
	bool operator<(const edge a) const {
		if(len != a.len) return len < a.len;
		if(from != a.from) return from < a.from;
		return to < a.to;
	}
	bool operator>(const edge a) const {
		if(len != a.len) return len > a.len;
		if(from != a.from) return from > a.from;
		return to > a.to;
	}
};
template <class T = long long>
struct graph {	// 0-indexed
	T const INF = numeric_limits<T>::max() / 3;
	vector<vector<edge<T>>> edges;
	bool directed, weight;
	int ver;

	// constructor
	graph() = default;
	graph(int vertex, bool direction = 0, bool weigh = 0) : edges(vertex) {
		ver = vertex;
		directed = direction;
		weight = weigh;
		edges.resize(vertex);
	}

	//辺の追加 (0-indexed)
	void update(int from, int to, T len = 1, bool direction = 1) {
		edge<T> e;
		e.len = len;
		e.from = from;
		e.to = to;
		edges[from].push_back(e);
		if(!direction) {
			swap(e.to, e.from);
			edges[to].push_back(e);
		}
	}

	//入力受取 (1-indexed)
	void input(int edge_num, int index = 1) {
		for(int i = 0; i < edge_num; i++) {
			int a;
			int b;
			cin >> a >> b;
			a -= index;
			b -= index;
			T c;
			if(weight)
				cin >> c;
			else
				c = 1;
			update(a, b, c, directed);
		}
	}

	// 辺の長さを全て1とみたときの単一始点最短経路 (無理なときはINF)
	vector<T> bfs(int start) {
		// https://atcoder.jp/contests/abc007/submissions/me
		vector<T> ret(ver, INF);
		queue<int> q;
		q.push(start);
		ret[start] = 0;
		while(!q.empty()) {
			int now = q.front();
			q.pop();
			for(auto &e : edges[now]) {
				if(ret[e.to] != INF) continue;
				q.push(e.to);
				ret[e.to] = ret[now] + 1;
			}
		}
		return ret;
	}

	//長さが負のpathがないときの単一始点最短経路<vll> O((ver)log(ver)+(edge))
	vector<T> dijkstra(int start) {
		vector<T> ret(ver, (T)INF);
		// pqup<pair<T, int>> p;														   //{dist,place}
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> p;  //{dist,place}
		p.push({0, start});
		ret[start] = 0;

		while(!p.empty()) {
			T dist = p.top().first;
			int place = p.top().second;
			p.pop();
			if(ret[place] < dist) continue;
			for(auto &next : edges[place]) {
				int nextplace = next.to;
				T dis = next.len;
				if(ret[nextplace] > dist + dis) {
					ret[nextplace] = dist + dis;
					p.push({ret[nextplace], nextplace});
				}
			}
		}
		return ret;
	}

	//単一始点最短経路 O((ver)*(edge))
	//辿り着けないとき ret[i] = INF;
	//ある頂点までのコストが無限に小さくなり得るとき→ ret[i] = -INF;
	vector<T> BellmanFord(int start) {
		// https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
		vector<T> ret(ver, INF);
		ret[start] = 0;
		for(int loop = 0; loop < ver - 1; loop++) {
			for(int v = 0; v < ver; v++) {
				if(ret[v] == INF) continue;
				for(auto &e : edges[v]) {
					ret[e.to] = min(ret[e.to], ret[v] + e.len);
				}
			}
		}

		//無限降下点の検索
		queue<int> q;
		vector<bool> chk(ver, 0);
		for(int v = 0; v < ver; v++) {
			if(ret[v] == INF) continue;
			for(auto &e : edges[v]) {
				if(ret[e.to] > ret[v] + e.len) {
					ret[e.to] = ret[v] + e.len;
					if(!chk[e.to]) {
						q.push(e.to);
						chk[e.to] = 1;
					}
				}
			}
		}
		while(!q.empty()) {
			int now = q.front();
			q.pop();
			for(auto &e : edges[now]) {
				if(!chk[e.to]) {
					chk[e.to] = 1;
					q.push(e.to);
				}
			}
		}
		for(int i = 0; i < ver; i++)
			if(chk[i]) ret[i] = -INF;

		return ret;
	}

	//閉路に含まれない頂点列挙
	//要素数がver未満なら閉路が存在、そうでなければ閉路は存在しない
	vector<int> topo_sort() {
		// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_A
		// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B
		assert(directed);
		vector<int> num_input(ver);
		// 入次数
		for(int i = 0; i < ver; i++) {
			for(auto e : edges[i]) {
				num_input[e.to]++;
			}
		}
		// 入次数が0のノードをqueueで管理する
		queue<int> que;
		for(int i = 0; i < ver; i++) {
			if(num_input[i] == 0) {
				que.push(i);
			}
		}
		vector<int> ans;
		while(!que.empty()) {
			auto node = que.front();
			que.pop();
			ans.push_back(node);
			// 頂点の削除
			for(auto e : edges[node]) {
				num_input[e.to]--;
				// 行き先の入次数が0になったらqueueに追加
				if(num_input[e.to] == 0) {
					que.push(e.to);
				}
			}
		}
		return ans;
	}

	//{{端点、端点},直径の大きさ}
	pair<pair<int, int>, T> DiameterOfTree(bool weigh = true) {
		// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A
		vector<T> vec;
		vec = weigh ? dijkstra(0) : bfs(0);
		int v1 = -1;
		T dia = -1;
		for(int i = 0; i < ver; i++)
			if((dia < vec[i])) {
				dia = vec[i];
				v1 = i;
			}

		vec = weigh ? dijkstra(v1) : bfs(v1);
		dia = -1;
		int v2 = -1;
		for(int i = 0; i < ver; i++)
			if((dia < vec[i])) {
				v2 = i;
				dia = vec[i];
			}

		pair<pair<int, int>, T> ans = {{v1, v2}, dia};
		return ans;
	}

	//無向木構造を根から葉に伸びる有向木構造に書き換える
	graph<T> RootToLeaf(int root) {	 // 0-indexed
		graph<T> ret(ver, 1, weight);
		vector<bool> chk(ver, 0);
		chk[root] = 1;
		function<void(int)> dfs = [&](int now) {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				ret.update(now, e.to, e.len, 1);
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}

	//無向木構造を葉から根に伸びる有向木構造に書き換える
	graph<T> LeafToRoot(int root) {	 // 0-indexed
		graph<T> ret(ver, 1, weight);
		vector<bool> chk(ver, 0);
		chk[root] = 1;
		function<void(int)> dfs = [&](int now) {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				ret.update(e.to, now, e.len, 1);
				dfs(e.to);
			}
		};
		dfs(root);
		ret.update(root, root, 0);
		return ret;
	}

	// LeafToRootのvector版.par[i]=iの親の頂点
	vector<int> par(int root) {	 // 0-indexed
		vector<int> ret(ver, -1);
		ret[root] = root;  // rootの親はroot
		function<void(int)> dfs = [&](int now) {
			for(auto &e : edges[now]) {
				if(ret[e.to] != -1) continue;
				ret[e.to] = now;
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}
	vector<edge<T>> ParentAndDistance(int root) {  // 0-indexed
		vector<edge<T>> ret(ver);
		for(int i = 0; i < ver; i++) ret[i].to = -1;
		ret[root].to = root;  // rootの親はroot
		ret[root].len = 0;	  // rootの親との距離は0
		function<void(int)> dfs = [&](int now) {
			for(auto &e : edges[now]) {
				if(ret[e.to].to != -1) continue;
				ret[e.to].to = now;
				ret[e.to].len = e.len;
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}

	//隣接sheet.主にwarshall用
	vector<vector<T>> GraphArray(void) {
		vector<vector<T>> ret(ver, vector<T>(ver, INF));
		for(int from = 0; from < ver; from++) {
			for(auto &e : edges[from]) {
				ret[from][e.to] = e.len;
			}
			ret[from][from] = 0;
		}
		return ret;
	}

	graph<T> Prim(int start = 0) {
		// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A
		graph<T> ret(ver, 0, 1);
		priority_queue<edge<T>, vector<edge<T>>, greater<edge<T>>> p;
		for(auto &e : edges[start]) {
			p.push(e);
		}
		vector<bool> chk(ver, 0);
		chk[start] = 1;
		while(!p.empty()) {
			auto ed = p.top();
			p.pop();
			if(chk[ed.to]) continue;
			chk[ed.to] = 1;
			ret.update(ed.from, ed.to, ed.len);
			for(auto &e : edges[ed.to]) {
				p.push(e);
			}
		}
		return ret;
	}

	//各頂点を根としたときの木の高さ
	vector<T> height(int start = 0) {
		// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_B
		vector<T> fir(ver, -1), sec(ver, -1);
		function<T(int, int)> dfs = [&](int now, int par) {
			T f = 0, s = 0;	 // startを根としたときのnowからの深さ1番目、2番目
			for(auto &e : edges[now]) {
				if(e.to == par) continue;
				s = max(s, dfs(e.to, now) + e.len);
				if(f < s) swap(f, s);
			}
			sec[now] = s;
			return fir[now] = f;
		};
		dfs(start, -1);
		function<void(int, int, T, T, T)> sol = [&](int now, int par, T parf, T pars, T parlen) {
			if(fir[now] + parlen == parf) parf = pars;
			sec[now] = max(sec[now], parf + parlen);
			if(fir[now] < sec[now]) swap(fir[now], sec[now]);
			for(auto &e : edges[now]) {
				if(e.to == par) continue;
				sol(e.to, now, fir[now], sec[now], e.len);
			}
			return;
		};
		sol(start, -1, -1, -1, -1);
		return fir;
	}

	//全方位木DP
	//マージ関数、上に送るための関数、単位元、はじめの根
	// 関数はstd::functionで渡す
	template <class U>
	vector<U> zenhoui(function<U(U, U)> f, function<U(U)> g, U unit, int root = 0) {
		auto tr = RootToLeaf(root);
		vector<vector<U>> v(ver);
		vector<U> ret(ver);	 //求める答

		function<U(int)> dfs = [&](int now) {
			U res = unit;
			vector<U> vec;
			for(auto &e : tr.edges[now]) {
				U k = dfs(e.to);
				vec.push_back(k);
				res = f(res, k);
			}
			v[now] = vec;
			return g(res);
		};
		dfs(root);

		function<void(int, U)> dfs2 = [&](int now, U ans_par) {
			int sz = v[now].size();
			vector<U> mae(sz + 1), rev(sz + 1);
			mae[0] = rev[sz] = unit;
			for(int i = 0; i < sz; i++) mae[i + 1] = f(mae[i], v[now][i]);
			for(int i = sz - 1; i >= 0; i--) rev[i] = f(rev[i + 1], v[now][i]);
			for(int i = 0; i < sz; i++) {
				auto nxtans = f(ans_par, f(mae[i], rev[i + 1]));
				dfs2(tr.edges[now][i].to, g(nxtans));
			}
			ret[now] = f(ans_par, mae[sz]);
			return;
		};
		dfs2(root, unit);

		return ret;
	}

	// HL分解
};

typedef tuple<int, int, int, int> tu;

using Real = double;

struct mint {
	// auto mod int
	// https://youtu.be/L8grWxBlIZ4?t=9858
	// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
	// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
	ll x;  // typedef long long ll;
	mint(ll x = 0) : x((x % mod + mod) % mod) {}
	mint operator-() const { return mint(-x); }
	mint &operator+=(const mint a) {
		if((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint &operator-=(const mint a) {
		if((x += mod - a.x) >= mod) x -= mod;
		return *this;
	}
	mint &operator*=(const mint a) {
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint a) const { return mint(*this) += a; }
	mint operator-(const mint a) const { return mint(*this) -= a; }
	mint operator*(const mint a) const { return mint(*this) *= a; }
	mint pow(ll t) const {
		if(!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if(t & 1) a *= *this;
		return a;
	}

	// for prime mod
	mint inv() const { return pow(mod - 2); }
	mint &operator/=(const mint a) { return *this *= a.inv(); }
	mint operator/(const mint a) const { return mint(*this) /= a; }
};
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

int main() {
	INT(n, m);
	INT(s, t);
	graph<ll> gra(n, 0, 1);
	gra.input(m);
	s--, t--;
	vector<pair<ll, mint>> froms(n, {dekai, 0}), fromt(n, {dekai, 0});
	froms[s] = {0, 1};
	fromt[t] = {0, 1};

	pqup<pair<ll, int>> q;
	vi chk(n);
	q.push({0, s});
	while(!q.empty()) {
		int now;
		ll dist;
		tie(dist, now) = q.top();
		q.pop();
		if(chk[now]) continue;
		chk[now] = 1;
		mint cnt = froms[now].second;
		foa(e, gra.edges[now]) {
			if(chmin(froms[e.to].first, dist + e.len)) {
				froms[e.to].second = cnt;
				q.push({froms[e.to].first, e.to});
			} else if(froms[e.to].first == dist + e.len) {
				froms[e.to].second += cnt;
			}
		}
	}

	rep(i, n) chk[i] = 0;
	pqup<pair<ll, int>> p;
	p.push({0, t});
	while(!p.empty()) {
		int now;
		ll dist;
		tie(dist, now) = p.top();
		p.pop();
		if(chk[now]) continue;
		chk[now] = 1;
		mint cnt = fromt[now].second;
		foa(e, gra.edges[now]) {
			if(chmin(fromt[e.to].first, dist + e.len)) {
				fromt[e.to].second = cnt;
				p.push({fromt[e.to].first, e.to});
			} else if(fromt[e.to].first == dist + e.len) {
				fromt[e.to].second += cnt;
			}
		}
	}

	mint ans = froms[t].second * fromt[s].second;
	ll kyori = froms[t].first;

	rep(i, n) foa(e, gra.edges[i]) {
		int from, to;
		from = e.from;
		to = e.to;

		auto lef = froms[from], rig = fromt[to];

		if(kyori != lef.first + e.len + rig.first) {
			continue;
		}

		if(abs(lef.first - rig.first) >= e.len) continue;

		ans -= lef.second * rig.second * lef.second * rig.second;
	}

	// debug(ans);

	rep(i, n) {
		auto lef = froms[i], rig = fromt[i];

		if(lef.first + rig.first == kyori && lef.first == rig.first) {
			ans -= lef.second * rig.second * lef.second * rig.second;
		}
	}
	cout << ans << endl;

	//debug(froms);
	//debug(fromt);
}
