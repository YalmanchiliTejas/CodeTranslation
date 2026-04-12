#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <math.h>
#include <algorithm>
#include <numeric>


using namespace std;

// マクロ&定数&関数 ================================================
typedef unsigned int uint;
typedef long long ll;

typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<double> vdouble;
typedef vector<bool> vbool;
typedef vector<string> vstring;

typedef vector<pair<int, int>> vpint;
typedef vector<pair<ll, ll>> vpll;
typedef vector<pair<double, double>> vpdouble;

typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvll;
typedef vector<vpint> vvpint;
typedef vector<vpll> vvpll;
typedef vector<vector<double>> vvdouble;
typedef vector<vector<string>> vvstring;
typedef vector<vector<bool>> vvbool;

typedef vector<vector<vector<ll>>> vvvll;
typedef vector<vector<vector<bool>>> vvvbool;

const int INF = 1e9 + 1;
const ll LLINF = 1e17 + 1;
const int DX[9] = { 0,  0, 1, -1, 1,  1, -1, -1, 0 }; // 4;４近傍
const int DY[9] = { 1, -1, 0,  0, 1, -1,  1, -1, 0 }; // 8:８近傍 9:(0,0)を含む
const double PI = 3.14159265358979323846264338327950288;

//VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV

const ll MOD = 1000000007; //10^9 + 7

//VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV


template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } else return false; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } else return false; }

//---------------------------------------------------------------
//  オーバーフローチェック
//---------------------------------------------------------------
void is_overflow(ll a, ll b) { if ((a * b) / b != a) cout << "OVERFLOW!!!!!" << endl; }

//---------------------------------------------------------------
//  整数の乱数生成
//---------------------------------------------------------------
ll random_int(ll start, ll last)
{
	//srand((uint)time(NULL));
	return start + rand() % (last - start + 1);
}

//---------------------------------------------------------------
//  x∈[a, b)
//---------------------------------------------------------------
bool is_in(ll x, ll a, ll b)
{
	return (a <= x && x < b);
}

//---------------------------------------------------------------
//  約数列挙
//---------------------------------------------------------------
vll divisor(ll n) {
	vll ret;
	for (ll i = 1; i * i <= n; i++) { if (n % i == 0) { ret.push_back(i);	if (i * i != n) ret.push_back(n / i); } }
	sort(begin(ret), end(ret));	return (ret);
}

//---------------------------------------------------------------
// N以下のすべての素数を列挙する(エラトステネスの篩)
//---------------------------------------------------------------
vbool searchSosuu(ll N) {
	vbool sosuu;
	for (ll i = 0; i < N; i++) { sosuu.emplace_back(true); }
	sosuu[0] = false;	sosuu[1] = false;
	for (ll i = 2; i < N; i++) { if (sosuu[i]) { for (ll j = 2; i * j < N; j++) { sosuu[i * j] = false; } } }
	return sosuu;
}

//---------------------------------------------------------------
// 素因数分解　O(√N)
//---------------------------------------------------------------
vpll to_prime(ll n) {
	vpll prime_factor;
	for (ll i = 2; i * i <= n; i++) {
		ll count = 0; while (n % i == 0) { count++; n /= i; }
		if (count) { pair<ll, ll> temp = { i, count };	prime_factor.emplace_back(temp); }
	}
	if (n != 1) { pair<ll, ll> temp = { n, 1 }; prime_factor.emplace_back(temp); }
	return prime_factor;
}

//---------------------------------------------------------------
// 素数判定
//---------------------------------------------------------------
bool is_sosuu(ll N) {
	if (N < 2)			 return false;
	else if (N == 2)	 return true;
	else if (N % 2 == 0) return false;
	for (ll i = 3; i <= sqrt(N); i += 2) { if (N % i == 0)	return false; }
	return true;
}

//---------------------------------------------------------------
// 最大公約数（ユークリッドの互除法）
//---------------------------------------------------------------
ll gcd(ll a, ll b) {
	if (a < b) { ll tmp = a;	a = b; b = tmp; }
	ll r = a % b;
	while (r != 0) { a = b; b = r; r = a % b; }
	return b;
}

//---------------------------------------------------------------
// 最小公倍数
//---------------------------------------------------------------
ll lcm(ll a, ll b) { ll temp = gcd(a, b); return temp * (a / temp) * (b / temp); }

//---------------------------------------------------------------
// 階乗
//---------------------------------------------------------------
ll factorial(ll n) { if (n <= 1) { return 1; }return (n * (factorial(n - 1))) % MOD; }

//---------------------------------------------------------------
// 高速コンビネーション計算(前処理:O(N) 計算:O(1))
//---------------------------------------------------------------
// テーブルを作る前処理
ll comb_const = 300005;
vll fac(comb_const), finv(comb_const), inv(comb_const);
bool COMineted = false;
void COMinit() {
	fac[0] = fac[1] = 1; finv[0] = finv[1] = 1; inv[1] = 1;
	for (ll i = 2; i < comb_const; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
	COMineted = true;
}
// 二項係数計算
ll COM(ll n, ll k) {
	if (COMineted == false) COMinit();
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return (fac[n] * (finv[k] * finv[n - k] % MOD)) % MOD;
}

//---------------------------------------------------------------
// 繰り返し２乗法 base^sisuu
//---------------------------------------------------------------
ll RepeatSquaring(ll base, ll sisuu, ll mod = MOD) {
	if (sisuu < 0) { cout << "RepeatSquaring: 指数が負です!" << endl; return 0; }
	if (sisuu == 0) return 1;
	if (sisuu % 2 == 0) { ll t = RepeatSquaring(base, sisuu / 2, mod) % mod;	return (t * t) % mod; }
	return (base * RepeatSquaring(base, sisuu - 1, mod)) % mod;
}

//---------------------------------------------------------------
// 高速単発コンビネーション計算(O(logN))
//---------------------------------------------------------------
ll fast_com(ll a, ll b) {
	ll bunshi = 1;	ll bunbo = 1;
	for (ll i = 1; i <= b; i++) { bunbo *= i;	bunbo %= MOD; bunshi *= (a - i + 1); bunshi %= MOD; }
	ll ret = bunshi * RepeatSquaring(bunbo, MOD - 2, MOD); ret %= MOD;
	while (ret < 0) { ret += MOD; }
	return ret;
}

//---------------------------------------------------------------
// 整数をビットのリストに変換する ll->vbool
//---------------------------------------------------------------
vbool to_bitlist(ll bit, ll fixed_size = 1) {
	if (bit == 0) return vbool(fixed_size, 0);
	vbool list;
	while (bit > 0) { list.emplace_back(bit & 1);	bit /= 2; }
	while (list.size() < fixed_size) { list.emplace_back(0); }
	return list;
}

//---------------------------------------------------------------
// 座標圧縮(O(NlogN))   0スタートになることに注意！
//---------------------------------------------------------------
class PosPress
{
	/*
	配列Pを座圧→instance = PosPress(P);

	座圧済み配列→instance.arr
	fooの圧縮後→instance.func[foo]
	fooの圧縮前→instance.rev[foo]
	*/
public:
	vll arr;
	map<ll, ll> func;
	map<ll, ll> rev;

	PosPress(vll P) {
		arr = P; sort(P.begin(), P.end()); func[P[0]] = 0;	rev[0] = P[0]; ll next = 1;
		for (int i = 1; i < P.size(); i++) { if (P[i] != P[i - 1]) { func[P[i]] = next; rev[next] = P[i]; next++; } }
		for (int i = 0; i < P.size(); i++) { arr[i] = func[arr[i]]; }
	}
};

//---------------------------------------------------------------
// 行列累乗(O(N^3))
//---------------------------------------------------------------
vvll mat_cross(vvll A, vvll B) {
	ll N = A.size(); ll K = B.size(); ll M = B[0].size();
	vvll C(N, vll(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			for (int k = 0; k < K; k++)
				C[i][j] += A[i][k] * B[k][j];
	return C;
}

//---------------------------------------------------------------
// 2直線の交差判定(直線(x1, y1)->(x2, y2) と 直線(X1, Y1)->(X2, Y2))
//---------------------------------------------------------------
bool is_cross(ll x1, ll y1, ll x2, ll y2, ll X1, ll Y1, ll X2, ll Y2) {
	ll dx_ai = X1 - x1;	ll dy_ai = Y1 - y1;
	ll dx_bi = X1 - x2;	ll dy_bi = Y1 - y2;
	ll dx_ai2 = X2 - x1; ll dy_ai2 = Y2 - y1;
	ll dx_bi2 = X2 - x2; ll dy_bi2 = Y2 - y2;
	ll si = dx_ai * dy_bi - dy_ai * dx_bi;
	ll si2 = dx_ai2 * dy_bi2 - dy_ai2 * dx_bi2;
	ll si3 = dx_ai * dy_ai2 - dy_ai * dx_ai2;
	ll si4 = dx_bi * dy_bi2 - dy_bi * dx_bi2;
	return (si * si2 < 0 && si3 * si4 < 0);
}

//---------------------------------------------------------------
// 最長増加部分列の長さ(O(NlogN))
//---------------------------------------------------------------
ll LSI(vll vec)
{
	ll size = vec.size();
	vll lsi(size + 1); // 長さjを作った時の右端の最小値
	for (ll i = 0; i <= size; i++) { lsi[i] = LLINF; }
	lsi[0] = 0;	lsi[1] = vec[0];
	for (ll i = 1; i < size; i++)
	{
		// 初めてvec[i]の方が小さくなるところを探す
		auto Iter = lower_bound(lsi.begin(), lsi.end(), vec[i]);
		ll idx = Iter - lsi.begin();
		if (idx > 0 && lsi[idx - 1] < vec[i]) { lsi[idx] = vec[i]; }
	}
	for (ll i = size; i >= 0; i--) { if (lsi[i] < LLINF) { return i; } }
}

//---------------------------------------------------------------
// LCS(最長共通部分列) O(|S||T|)
//---------------------------------------------------------------
string LCS(string S, string T)
{
	vvll dp(S.length() + 1);
	for (int i = 0; i < dp.size(); i++) { vll t(T.length() + 1, 0); dp[i] = t; }

	for (int i = 0; i < S.length(); i++) {
		for (int j = 0; j < T.length(); j++) {
			dp[i + 1][j + 1] = max({ dp[i][j] + ll(S[i] == T[j]), dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1] });
		}
	}
	ll len = dp[S.length()][T.length()];
	string ans = "";
	ll i = dp.size() - 1;
	ll j = dp[0].size() - 1;
	while (len > 0) {
		if (dp[i - 1][j] == len) { i--; }
		else if (dp[i][j - 1] == len) { j--; }
		else { ans += S[i - 1]; i--; j--; len--; }
	}

	reverse(ans.begin(), ans.end());
	return ans;
}
vll LCS(vll S, vll T)
{
	vvll dp(S.size() + 1);
	for (int i = 0; i < dp.size(); i++) { vll t(T.size() + 1, 0); dp[i] = t; }

	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < T.size(); j++) {
			dp[i + 1][j + 1] = max({ dp[i][j] + ll(S[i] == T[j]), dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1] });
		}
	}
	ll len = dp[S.size()][T.size()];
	vll ans;
	ll i = dp.size() - 1;
	ll j = dp[0].size() - 1;
	while (len > 0) {
		if (dp[i - 1][j] == len) { i--; }
		else if (dp[i][j - 1] == len) { j--; }
		else { ans.emplace_back(S[i - 1]); i--; j--; len--; }
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

//---------------------------------------------------------------
// 木の根からの深さ
//---------------------------------------------------------------
vll tree_depth(vvll edge, ll start_node)
{
	ll n_node = edge.size();
	vll dist(n_node, LLINF);
	dist[start_node] = 0;

	stack<pll> S;
	S.push({ start_node, 0 });

	while (!S.empty())
	{
		ll node = S.top().first;
		ll d = S.top().second;
		dist[node] = d;

		S.pop();

		for (int i = 0; i < edge[node].size(); i++)
		{
			if (dist[edge[node][i]] == LLINF)
			{
				S.push({ edge[node][i], d + 1 });
			}
		}
	}

	return dist;
}

//---------------------------------------------------------------
// ワーシャルフロイド法(O(N^3)) d: 正方行列(N*N)
//---------------------------------------------------------------
vvll warshall_floyd(vvll d) {
	ll n = d.size();
	for (int k = 0; k < n; k++) {       // 経由する頂点
		for (int i = 0; i < n; i++) {    // 始点
			for (int j = 0; j < n; j++) {  // 終点
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	return d;
}

//---------------------------------------------------------------
// Union Find
//---------------------------------------------------------------
class UnionFind {
public:
	/*
	UnionFind uf(要素の個数);
	for(int i = 0;i < 関係の個数; i++)
	{
		uf.merge(A[i], B[i]);
	}

	nを含む集合の大きさ = uf.size(n)
	nを含む集合の代表者 = uf.root(n)
	集合の個数 = uf.n_group
	*/
	vector <ll> par; // 各元の親を表す配列
	vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)
	ll n_group; //集合の数

	// Constructor
	UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
		for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
		n_group = sz_;
	}
	void init(ll sz_) {
		par.resize(sz_);
		siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
		for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
	}

	// Member Function
	// Find
	ll root(ll x) { // 根の検索
		while (par[x] != x) {
			x = par[x] = par[par[x]]; // x の親の親を x の親とする
		}
		return x;
	}

	// Union(Unite, Merge)
	bool merge(ll x, ll y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		// merge technique（データ構造をマージするテク．小を大にくっつける）
		if (siz[x] < siz[y]) swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
		n_group--;
		return true;
	}

	bool issame(ll x, ll y) { // 連結判定
		return root(x) == root(y);
	}

	ll size(ll x) { // 素集合のサイズ
		return siz[root(x)];
	}
};

//---------------------------------------------------------------
// ダイクストラ(O(ElogV))   edge: 隣接リスト from->pair{to, cost}
//---------------------------------------------------------------
class Dijkstra
{
public:

	vll dist; // iまでの最短距離
	vll past; // (iまで最短で行くときの一つ前)

	// edge[i] -> {to, cost}
	Dijkstra(vvpll edge, ll start) : dist(edge.size(), LLINF), past(edge.size(), -1)
	{
		using Pi = pll;
		priority_queue< Pi, vector< Pi >, greater< Pi > > que;
		dist[start] = 0;
		que.emplace(dist[start], start);
		while (!que.empty()) {
			ll cost;
			int idx;
			tie(cost, idx) = que.top();
			que.pop();
			if (dist[idx] < cost) continue;
			for (int i = 0; i < edge[idx].size(); i++)
			{
				ll next_cost = cost + edge[idx][i].second;
				if (dist[edge[idx][i].first] <= next_cost) continue;
				dist[edge[idx][i].first] = next_cost;
				past[edge[idx][i].first] = idx;
				que.emplace(dist[edge[idx][i].first], edge[idx][i].first);
			}
		}
	}

	// goalまでの最短経路
	vll shortest(ll goal)
	{
		vll ret;
		while (goal != -1)
		{
			ret.emplace_back(goal);
			goal = past[goal];
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};

//---------------------------------------------------------------
// LCA: 最近共通祖先 (O())
//---------------------------------------------------------------
class Lca
{
public:

	vll depth; // 根0からiまでの最短距離
	vvll doubling;
	ll n_bit = 30;

	// edge[i] -> {to, cost}
	Lca(vvll edge) : doubling(50, vll(edge.size(), -1))
	{
		// 深さ
		depth = tree_depth(edge, 0);

		// ダブリングで親を辿れるようにする
		// jから2^i回親を辿ったノード
		doubling[0][0] = -1;
		for (int i = 1; i < edge.size(); i++)
			for (int j : edge[i])
				if (depth[i] > depth[j]) { doubling[0][i] = j; break; }
		for (int i = 1; i < n_bit; i++)
			for (int j = 0; j < edge.size(); j++) {
				if (doubling[i - 1][j] != -1) doubling[i][j] = doubling[i - 1][doubling[i - 1][j]];
				else doubling[i][j] = -1;
			}
	}

	// aとbの最近共通祖先
	ll get_lca(ll a, ll b)
	{
		// depth[a] >= depth[b]にする
		if (depth[a] < depth[b]) swap(a, b);
		ll oa = a;
		ll ob = b;
		ll d = depth[a] - depth[b];

		// aをdだけさかのぼる。
		vbool bit = to_bitlist(d, n_bit);
		for (int i = 0; i < n_bit; i++)if (bit[i]) a = doubling[i][a];

		// depth[a] == depth[b]になっている。
		for (int i = n_bit - 1; i >= 0; i--) {
			if (doubling[i][a] == doubling[i][b]) continue;
			a = doubling[i][a];	b = doubling[i][b];
		}
		return a == b ? a : doubling[0][a];
	}


};

//---------------------------------------------------------------
// Z-algorithm(SとS[i:]の最長接頭辞長)  O(|S|)
//---------------------------------------------------------------
vll Zalgorithm(string S)
{
	ll n = S.size();
	vll Z(n, 0);
	ll start = -1;
	ll last = -1;
	for (ll i = 1; i < n; i++) {
		if (start >= 0) { Z[i] = min(Z[i - start], last - i); chmax(Z[i], 0LL); }
		while (i + Z[i] < S.size() && S[Z[i]] == S[i + Z[i]])
			Z[i] ++;
		if (last < i + Z[i]) { last = i + Z[i]; start = i; }
	}
	Z[0] = n;
	return Z;
}
vll Zalgorithm(vll S)
{
	ll n = S.size();
	vll Z(n, 0);
	ll start = -1;
	ll last = -1;
	for (ll i = 1; i < n; i++) {
		if (start >= 0) { Z[i] = min(Z[i - start], last - i); chmax(Z[i], 0LL); }
		while (i + Z[i] < S.size() && S[Z[i]] == S[i + Z[i]])
			Z[i] ++;
		if (last < i + Z[i]) { last = i + Z[i]; start = i; }
	}
	Z[0] = n;
	return Z;
}

//---------------------------------------------------------------
// セグメント木
//---------------------------------------------------------------
class SegmentTree
{
public:

	const ll SEG_LEN = 1 << 19;
	vector<set<ll>> seg;
	ll s;

	SegmentTree(vll A) : seg(SEG_LEN * 2, set<ll>({})) {
		s = A.size();

		for (int i = 0; i < A.size(); i++)
		{
			seg[i + SEG_LEN] = { A[i] };
		}



		for (int i = 0; i < A.size(); i++)
		{
			ll pos = i + SEG_LEN;
			while (true)
			{
				pos /= 2;
				if (pos <= 0) break;

				if (seg[pos * 2 + 1].size() < seg[pos * 2].size())
				{
					seg[pos] = seg[pos * 2];

					for (auto itr = seg[pos * 2 + 1].begin(); itr != seg[pos * 2 + 1].end(); ++itr) {

						seg[pos].insert(*itr);
					}
				}
				else
				{
					seg[pos] = seg[pos * 2 + 1];

					for (auto itr = seg[pos * 2].begin(); itr != seg[pos * 2].end(); ++itr) {

						seg[pos].insert(*itr);
					}
				}

			}
		}


	}

	ll seg_max(ll left, ll right)
	{
		left += SEG_LEN;
		right += SEG_LEN + 1;

		set<ll> ret = {};
		vbool used(s + 1, false);

		while (left < right)
		{
			while (left % 2 == 1)
			{
				if (seg[left].size())
				{
					for (auto itr = seg[left].begin(); itr != seg[left].end(); ++itr) {
						if (!used[*itr]) {
							ret.insert(*itr);
							used[*itr] = true;
						}
					}
				}
				left++;
			}
			while (right % 2 == 1)
			{
				if (seg[right - 1].size())
				{
					for (auto itr = seg[right - 1].begin(); itr != seg[right - 1].end(); ++itr) {
						if (!used[*itr]) {
							ret.insert(*itr);
							used[*itr] = true;
						}
					}
				}
				right--;
			}

			left /= 2;
			right /= 2;
		}

		return ret.size();
	}

};


//========================================================================
//========================================================================
//========================================================================
//========================================================================




int main() {

	//////==================================
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(25);
	//////==================================


	/*
	～思いついたことはとりあえず絶対メモする！！～
	*/


	ll N;
	cin >> N;
	vll A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}


	ll sum = 0;
	ll ans = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		ans += sum * A[i];
		sum += A[i];
		ans %= MOD;
		sum %= MOD;
	}

	cout << ans;




}