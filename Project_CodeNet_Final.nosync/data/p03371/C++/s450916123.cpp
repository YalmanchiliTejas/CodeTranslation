//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <cstdint>
#include <climits>
#include <ctime>
#include <tuple>
using namespace std;

int main();

typedef long long ll;
typedef vector<bool> VB;
typedef vector<vector<bool>> VVB;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<ll> VL;
typedef vector<vector<ll>> VVL;
typedef vector<double> VD;
typedef vector<vector<double>> VVD;

const double PI=3.14159265358979323846;
const int INF = 1 << 29; // INF + N 程度の余裕を残すため、INT_MAXは使用しないこと。
const ll INFLL = 1LL << 61;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REP1(i, n) for(int i = 1; i <= (int)(n); i++)
#define REPLL(i, n) for(ll i = 0; i < (ll)(n); i++)
#define REP1LL(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define LEN(x) ((int)(x).length())
#define ZERO(a) memset(a, 0, sizeof(a))
#define RAD(d) (PI * (d) / 180)
#define DEG(r) (180.0 * (r) / PI)
#define popcnt(x) __builtin_popcount(x)
#define popcnt64(x) __builtin_popcountll(x)
#define pb push_back
#define mp make_pair

#define mt make_tuple
#define get0(x) get<0>(x)
#define get1(x) get<1>(x)
#define get2(x) get<2>(x)
#define get3(x) get<3>(x)
#define get4(x) get<4>(x)

// DP用
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

// ダンプ
template<class T> void dump(const vector<T> &v)
{
	if(SZ(v) == 0) return ;
	REP(i, SZ(v)-1){ cout << v[i] << " "; }
	cout << v[SZ(v)-1] << endl;
}

// ダンプ（2次元）
template<class T> void dump(const vector<vector<T>> &v)
{
	REP(j, SZ(v)){
		dump(v[j]);
	}
}

// ダンプ（２次元）
template<class T> void dump(int w, int h, const vector<T> &v)
{
	REP(j, h){
		REP(i, w-1){ cout << v[j * w + i] << " "; }
		cout << v[j * w + w-1] << endl;
	}
}

// 和
template<class T> T accumulate(const vector<T> &v)
{
	T sum = 0;
	REP(i, SZ(v)){ sum += v[i]; }
	return sum;
}

// 和（範囲指定）
template<class T> T accumulate(const vector<T> &v, int start, int length)
{
	T sum = 0;
	REP(i, length){
		sum += v[start + i];
	}
	return sum;
}

// 平均
template<class T> T average(const vector<T> &v)
{
	return accumulate(v) / SZ(v);
}

// 行列構造体
template<class T> struct Matrix
{
	T w, h;
	vector<T> A;
	Matrix(T w_, T h_) : w(w_), h(h_), A(w * h) {}
	T get(T x, T y) const { return A[y * w + x]; }
};

// 行列への入力
template<class T> void input(Matrix<T> &m)
{
	REP(j, m.h){
		REP(i, m.w){
			cin >> m.A[j * m.w + i];
		}
	}
}

// 行列の積算
template<class T> Matrix<T> prod(const Matrix<T> &a, const Matrix<T> &b)
{
	Matrix<T> m(b.w, a.h);

	REP(j, m.h){
		REP(i, m.w){
			ll c = 0;
			REP(k, a.w){
				c += a.A[j * a.w + k] * b.A[k * b.w + i];
			}
			m.A[j * m.w + i] = c;
		}
	}

	return m;
}

// 行列の出力(int)
void dump(const Matrix<int> &m)
{
	REP(j, m.h){
		REP(i, m.w-1){ printf("%d ", m.A[j * m.w + i]); }
		printf("%d\n", m.A[j * m.w + m.w-1]);
	}
}

// 行列の出力(long long)
void dump(const Matrix<ll> &m)
{
	REP(j, m.h){
		REP(i, m.w-1){ printf("%lld ", m.A[j * m.w + i]); }
		printf("%lld\n", m.A[j * m.w + m.w-1]);
	}
}

// 行列の出力(double)
void dump(const Matrix<double> &m)
{
	REP(j, m.h){
		REP(i, m.w-1){ printf("%f ", m.A[j * m.w + i]); }
		printf("%f\n", m.A[j * m.w + m.w-1]);
	}
}

// 文字列の大文字化
string &to_upper(string &s)
{
	REP(i, s.length()){
		if('a' <= s[i] && s[i] <= 'z'){
			s[i] -= 32;
		}
	}

	return s;
}

// 文字列の小文字化
string &to_lower(string &s)
{
	REP(i, s.length()){
		if('A' <= s[i] && s[i] <= 'Z'){
			s[i] += 32;
		}
	}

	return s;
}

// 素数取得
VB get_prime(int n)
{
	VB prime_flag(n, true);
	prime_flag[0] = false;
	prime_flag[1] = false;

	for(int i = 2; i < n; i++){
		if(!prime_flag[i]) continue;
		for(int j = i * 2; j < n; j += i)
			prime_flag[j] = false;
	}

	return prime_flag;
}

// 素数判定（エラトステネスのふるい）
template <class T> bool is_prime(T value)
{
	for(ll i = 2; i * i <= value; i++){
		if(value % i == 0)
			return false;
	}
	return true;
}

// 約数の列挙
template <class T> vector<T> get_divisors(T n)
{
	vector<T> ret;
	for(T i = 1; i * i <= n; i++){
		if(n % i == 0){
			ret.push_back(i);
			if(i * i != n)
				ret.push_back(n / i);
		}
	}
	sort(ALL(ret));
	return ret;
}

// 約数の列挙（1 ～ sqrt(N)まで）
template <class T> vector<T> get_divisors2(T n)
{
	vector<T> ret;
	for(T i = 1; i * i <= n; i++){
		if(n % i == 0){
			ret.push_back(i);
		}
	}
	return ret;
}

// 最大公約数(GCD; Greatest Common Divisor)  ※ユークリッドの互除法
template <class T> T gcd(T a, T b)
{
	if(a < b)
		return gcd(b, a);

	ll r;
	while((r = a % b)){
		a = b;
		b = r;
	}
	return b;
}

// ３数の最大公約数
template <class T> T gcd(T a, T b, T c)
{
	return gcd(gcd(a, b), c);
}

// ３数以上の最大公約数
template <class T> T gcd(const vector<T> v)
{
	if(SZ(v) == 0)
		return 0;

	if(SZ(v) == 1)
		return v[0];

	if(SZ(v) == 2)
		return gcd(v[0], v[1]);

	T g = v[0];
	for(int i = 1; i < SZ(v); i++){
		g = gcd(g, v[i]);
	}
	return g;
}

// 最小公倍数(LCM; Least Common Multiple)
template <class T> T lcm(T a, T b)
{
	return a / gcd(a, b) * b;
}

// MOD計算(べき乗) : a^n % MOD
ll modpow(ll a, ll n, ll mod)
{
	ll res = 1;
	while(n > 0){
		if(n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;	
}

// MOD計算(逆元) : a^(-1) MOD  (※拡張ユークリッド互除法)
ll modinv(ll a, ll mod)
{
	ll b = mod, u = 1, v = 0;
	while(b){
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= mod;
	if(u < 0) u += mod;
	return u;
}

// MOD計算
// 
// modint 構造体を使ってみませんか？ (C++) - noshi91のメモ
// https://noshi91.hatenablog.com/entry/2019/03/31/174006
// 
// 使い方:
//   const int MOD = 1000000007;
//   using mint = modint<MOD>;
//   mint a = 1234;
// 
template <std::uint_fast64_t Modulus> class modint {
	using u64 = std::uint_fast64_t;

public:
	u64 a;

	constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
	constexpr u64 &value() noexcept { return a; }
	constexpr const u64 &value() const noexcept { return a; }
	constexpr modint operator+(const modint rhs) const noexcept { return modint(*this) += rhs; }
	constexpr modint operator-(const modint rhs) const noexcept { return modint(*this) -= rhs; }
	constexpr modint operator*(const modint rhs) const noexcept { return modint(*this) *= rhs; }
	constexpr modint operator/(const modint rhs) const noexcept { return modint(*this) /= rhs; }
	constexpr modint &operator+=(const modint rhs) noexcept {
		a += rhs.a;
		if (a >= Modulus) {
			a -= Modulus;
		}
		return *this;
	}
	constexpr modint &operator-=(const modint rhs) noexcept {
		if (a < rhs.a) {
			a += Modulus;
		}
		a -= rhs.a;
		return *this;
	}
	constexpr modint &operator*=(const modint rhs) noexcept {
		a = a * rhs.a % Modulus;
		return *this;
	}
	constexpr modint &operator/=(modint rhs) noexcept {
		u64 exp = Modulus - 2;
		while (exp) {
			if (exp % 2) {
				*this *= rhs;
			}
			rhs *= rhs;
			exp /= 2;
		}
		return *this;
	}
};

// DFS 幅優先探索 (A[0] ... A[N] タイプ)
#if 0
VI AA(N);

void dfs(int index, int size, int start, int end)
{
    if (index == size) {
		solve(A); // ここで必要な処理を行う
    }
    else{
		for(int i = start; i <= end; ++i){
			A[index] = i;

			// start <= A[i] <= end (i=0~size-1) の場合
			//dfs(index + 1, size, start, end);

			// start <= A[0] <= A[1] <= ... <= A[size-1] <= end の場合
			dfs(index + 1, size, i, end); // start = iを指定することで、次indexの値域を狭める
		}
    }
}
#endif

// DFS 幅優先探索 (グラフ問題)
// 
// ■ 解ける問題
// 1.グラフ上の到達可否
// 2.連結成分の数
// 3.二部グラフ判定　→　引数に現在ノードの色を追加する。color[v]が到達済みで、かつ同じ色の場合、二部グラフではない。
// 4.各頂点の深さ　→　(行きがけ順)
// 5.各頂点の部分木サイズ　→　(帰りがけ順)
// 6.サイクル検出（★勉強中）
// 
#if 0
VVI G(N); // グラフ
VB seen(N, false); // 到達フラグ
VI first_order(N); // 行きがけ順
VI last_order(N);  // 帰りがけ順
VI color(N, 0); // 二部グラフ判定用(0:未到達, 1:白, -1:黒)
VI depth(N); // 各頂点の深さ
VI subtree_size(N); // 各頂点の部分木サイズ

void dfs(const VVI &G, int v, int &order, int parent, int d)
{
	first_order[v] = order++;
	depth[v] = d;

	seen[v] = true;
	for(auto nv : G[v]){
		if(seen[nv]) continue;
		dfs(G, nv, order, v, d);
	}

	// 部分木サイズ
	subtree_size[v] = 1;
	for(auto c : G[v]){
		if(c == parent) continue;
		subtree_size[v] += subtree_size[c];
	}

	last_order[v] = order++;
}
#endif

// DAG(有向無閉路グラフ)のトポロジカルソート
// 
// ■ 応用問題
// 1.依存関係の解決処理
// 
VI tsort(const VVI &G)
{
	int N = G.size();
	VI indeg(N); // 各ノードへの入力辺数
	stack<int> S; // indeg(x) == 0 のノード

	for(auto &v : G){
		for(auto &e : v){
			indeg[e]++;
		}
	}

	REP(i, N){
		if(indeg[i] == 0)
			S.push(i);
	}

	VI ans;
	while(!S.empty()){
		int v = S.top(); S.pop();
		ans.pb(v);
		for(auto &e : G[v]){
			indeg[e]--;
			if(indeg[e] == 0)
				S.push(e);
		}
	}

	return ans;
}

// グラフの辺(Edge)
typedef pair<ll, int> Edge; // first : コスト, second : 接続先ノード

// ダイクストラ法(最短経路問題。コストが負の場合使用できない)
vector<ll> dijkstra(const vector<vector<Edge>> &G, int start)
{
	int N = G.size();
	priority_queue<Edge, vector<Edge>, greater<Edge>> que;
	vector<ll> dist(N, INFLL);

	que.push(mp(0LL, start));
	dist[start] = 0;

	while(!que.empty()){
		Edge p = que.top(); que.pop();
		if(dist[p.second] < p.first) continue;

		for(auto &e : G[p.second]){
			if(dist[e.second] > dist[p.second] + e.first){
				dist[e.second] = dist[p.second] + e.first;
				que.push(mp(dist[e.second], e.second));
			}
		}
	}

	return dist;
}

// Union-Find木(素集合データ構造) - グループ分けを木構造で管理する。任意の２要素が同じグループに所属するか判定する
struct UnionFind
{
	// 親ノードのインデックス
	VI parent;

	UnionFind(int size)
	{
		parent.resize(size);
		REP(i, size){ parent[i] = i; } // 初期状態は自ノードが親ノード(＝すべてのノードが独立)
	}

	// 木の根(root)を取得する
	int root(int x)
	{
		// 要素xが根の場合
		if(parent[x] == x)
			return x;

		// 経路圧縮
		parent[x] = root(parent[x]);

		return parent[x];
	}

	// 同じグループかどうか判定する
	bool same(int x, int y)
	{
		return root(x) == root(y);
	}

	// ２つのグループを併合する
	void unite(int x, int y)
	{
		x = root(x);
		y = root(y);
		if(x != y)
			parent[x] = y;
	}
};

// 最小全域木(Minimum Spanning Tree) (クラスカル法)
typedef tuple<int, int, int> STEdge; // get0 : コスト, get1,2 : 頂点

struct SpanningTree
{
	vector<STEdge> edges;
	
	// 辺を追加する(※直接edges変数に追加してもよい。)
	void add(int cost, int a, int b)
	{
		edges.push_back(mt(cost, a, b));
	}

	// 最小全域木を生成し、コストの和を計算する
	int kuraskal(int size)
	{
		sort(ALL(edges));

		UnionFind tree(size);

		int min_cost = 0;
		REP(i, SZ(edges)){
			auto &e = edges[i];
			if(!tree.same(get1(e), get2(e))){
				min_cost += get0(e);
				tree.unite(get1(e), get2(e));
			}
		}
		
		return min_cost;
	}
};

// よく忘れるSTLの使い方
// 
// ■ 最小値、最大値
// it = min_element(first, last);
// it = min_element(first, last);
// 
// ■ 値の交換 swap(a, b)  ※文字列(string)も交換可能。
// 
// ■ 乱数
// srand((unsigned)time(NULL));
// rand() - 0 ~ 2^31-1 の範囲の乱数(※VSの場合2^15-1。)
// 
// ■ 時間計測
// int t0 = clock();
// double ts = 1.0 * (clock() - t0) / CLOCKS_PER_SEC;
// 
// ■ sort ソート（降順）
// sort(first, last, greater<T>());  // 大きい順(降順)
// 
// ■ カウント O(N)、探索 O(N)、二分探索 O(logN)
// n = count(first, last, value);
// it = find(first, last, value);  ※見つからない場合、it == last
// i = lower_bound(first, last, value) - first
// ★[first, last) 間は小さい順に【 ソート済み 】であること。
// 
// ■ vector<T>
// v{ a, b, c }  // 初期値
// v.assign(first, last)  ※sizeも変わる
// v.assign(N, value)     ※sizeも変わる
// 
// ■ stack<T>, queue<T>
// ■ priority_queue<T, vector<T>, greater<T>>  // 大きい順(降順)の場合、less<T> (※sortとは逆)
// s.push(x)
// s.pop()
// x = s.top() or x = q.front()  ※queueの場合はfront()。
// s.size()
// s.empty()
// 
// ■ set<T>, multiset<T>
// s.insert(x)
// s.erase(x)  ※multisetではすべてのx
// s.erase(it)
// s.lower_bound(x) 
// 
// ■ map<K, V>
// m[K] = V; // 追加
// m.find(K) == m.end() // 探索
// 
// ■ tuple
// tuple<T0, T1, T2, ...> t;
// t = mt(v0, v1, v2, ...)
// v0 = get0(t)
// get0(t) = v0
// 
// ■ 順列
// do{
// }while(next_permutation(first, last));
// ★[first, last) 間は小さい順に【 ソート済み 】であること。
// 
// ■ ビットセット
// bitset<8> b("10000000");
// bs.size()
// b[i]  (i = 0 ~ b.size()-1)
// b.set(i)  or  b.reset(i)
// b.count(), b.all(), b.any(), b.none()  1の数, すべて1か, いずれか1か, すべて0か
// 

int main()
{
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

//	int min_cost = INF;
	int min_cost = 0x7FFFFFFF;
	for(int k = 0; k <= max(X, Y); k++){
		// int a = max(0, X - k) * A;
		// int b = max(0, Y - k) * B;
		int cost = 2 * C * k + max(0, X - k) * A + max(0, Y - k) * B;
		chmin(min_cost, cost);
	}

	cout << min_cost << endl;

	return 0;
}

# if 0
int main()
{
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int min_cost = 0x7FFFFFFF;

	for(int k = 0; k <= max(X, Y); k++){
		int cost = 2 * C * k + A * max(0, X - k) + B * max(0, Y - k);
		chmin(min_cost, cost);
	}
#endif
