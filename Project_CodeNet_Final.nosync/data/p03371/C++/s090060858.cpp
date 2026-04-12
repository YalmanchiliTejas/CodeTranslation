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

const int INF = 1e9 + 1;
const ll LLINF = 1e17 + 1;
const int DX[9] = { 0,  0, 1, -1, 1,  1, -1, -1, 0 }; // 4;４近傍
const int DY[9] = { 1, -1, 0,  0, 1, -1,  1, -1, 0 }; // 8:８近傍 9:(0,0)を含む
const ll MOD = 1e9 + 7; //10^9 + 7
const ll MAX = 1e9;
const double PI = 3.14159265358979323846264338327950288;



//---------------------------------------------------------------
//  オーバーフローチェック
//---------------------------------------------------------------
bool is_overflow(ll a, ll b)
{
	return ((a * b) / b != a);
}

//---------------------------------------------------------------
//  約数列挙
//---------------------------------------------------------------
vll divisor(ll n) {
	vll ret;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(begin(ret), end(ret));
	return (ret);
}

//---------------------------------------------------------------
// N以下のすべての素数を列挙する(エラトステネスの篩)
//---------------------------------------------------------------
vbool searchSosuu(ll N) {
	vbool sosuu; // ←これをグローバル変数にして１度だけ実行する
	for (ll i = 0; i < N; i++) {
		sosuu.emplace_back(true);
	}
	sosuu[0] = false;
	sosuu[1] = false;
	for (ll i = 2; i < N; i++) {
		if (sosuu[i]) {
			for (ll j = 2; i * j < N; j++) {
				sosuu[i * j] = false;
			}
		}
	}

	return sosuu;
}

//---------------------------------------------------------------
// 素因数分解　O(√N)
//---------------------------------------------------------------
vpll div_prime(ll n)
{
	vpll prime_factor;
	for (ll i = 2; i * i <= n; i++)
	{
		ll count = 0;
		while (n % i == 0)
		{
			count++;
			n /= i;
		}
		if (count)
		{
			pair<ll, ll> temp = { i, count };
			prime_factor.emplace_back(temp);
		}
	}
	if (n != 1)
	{
		pair<ll, ll> temp = { n, 1 };
		prime_factor.emplace_back(temp);
	}

	return prime_factor;
}

//---------------------------------------------------------------
// 素数判定
//---------------------------------------------------------------
bool is_sosuu(ll N) {

	if (N < 2) {
		return false;
	}
	else if (N == 2) {
		return true;
	}
	else if (N % 2 == 0) {
		return false;
	}

	for (ll i = 3; i <= sqrt(N); i += 2) {
		if (N % i == 0) {
			return false;
		}
	}

	return true;
}

//---------------------------------------------------------------
// 最大公約数（ユークリッドの互除法）(O(logA))
//---------------------------------------------------------------
ll gcd(ll a, ll b) {
	if (a < b) {
		ll tmp = a;
		a = b;
		b = tmp;
	}

	ll r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}

//---------------------------------------------------------------
// 最小公倍数
//---------------------------------------------------------------
ll lcm(ll a, ll b) {
	ll temp = gcd(a, b);
	return temp * (a / temp) * (b / temp);
}

//---------------------------------------------------------------
// 階乗
//---------------------------------------------------------------
ll factorial(ll n)
{
	if (n <= 1)
	{
		return 1;
	}

	return (n * (factorial(n - 1))) % MOD;
}

//---------------------------------------------------------------
// 高速コンビネーション計算(前処理:O(N) 計算:O(1))
//---------------------------------------------------------------
// テーブルを作る前処理
ll comb_const = 200005;
vll fac(comb_const), finv(comb_const), inv(comb_const);
bool COMineted = false;
void COMinit() {

	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
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
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//---------------------------------------------------------------
// 繰り返し２乗法 base^sisuu
//---------------------------------------------------------------
ll RepeatSquaring(ll base, ll sisuu) {
	if (sisuu < 0) {
		cout << "RepeatSquaring: 指数が負です!" << endl;
		return 0;
	}
	if (sisuu == 0) return 1;
	if (sisuu % 2 == 0) {
		ll t = RepeatSquaring(base, sisuu / 2) % MOD;
		return (t * t) % MOD;
	}
	return base * RepeatSquaring(base, sisuu - 1) % MOD;
}

//---------------------------------------------------------------
// 高速単発コンビネーション計算(O(logN))
//---------------------------------------------------------------
ll fast_com(ll a, ll b) {

	ll bunshi = 1;
	ll bunbo = 1;
	for (ll i = 1; i <= b; i++)
	{
		bunbo *= i;
		bunbo %= MOD;

		bunshi *= (a - i + 1);
		bunshi %= MOD;
	}

	ll ret = bunshi * RepeatSquaring(bunbo, MOD - 2);

	ret %= MOD;
	while (ret < 0)
	{
		ret += MOD;
	}

	return ret;
}

//---------------------------------------------------------------
// 2直線の交差判定(直線(x1, y1)->(x2, y2) と 直線(X1, Y1)->(X2, Y2))
//---------------------------------------------------------------
bool is_cross(ll x1, ll y1, ll x2, ll y2, ll X1, ll Y1, ll X2, ll Y2)
{
	ll dx_ai = X1 - x1;
	ll dy_ai = Y1 - y1;
	ll dx_bi = X1 - x2;
	ll dy_bi = Y1 - y2;

	ll dx_ai2 = X2 - x1;
	ll dy_ai2 = Y2 - y1;
	ll dx_bi2 = X2 - x2;
	ll dy_bi2 = Y2 - y2;

	ll si = dx_ai * dy_bi - dy_ai * dx_bi;
	ll si2 = dx_ai2 * dy_bi2 - dy_ai2 * dx_bi2;

	ll si3 = dx_ai * dy_ai2 - dy_ai * dx_ai2;
	ll si4 = dx_bi * dy_bi2 - dy_bi * dx_bi2;

	return (si * si2 < 0 && si3 * si4 < 0);

}

//---------------------------------------------------------------
// 最長増加部分列の長さ(O(NlogN))
//---------------------------------------------------------------
ll LSI(vll vec, ll size)
{
	vll lsi(size + 1); // 長さjを作った時の右端の最小値
	for (ll i = 0; i <= size; i++)
	{
		lsi[i] = LLINF;
	}

	lsi[0] = 0;
	lsi[1] = vec[0];

	for (ll i = 1; i < size; i++)
	{
		// 初めてvec[i]の方が小さくなるところを探す
		auto Iter = lower_bound(lsi.begin(), lsi.end(), vec[i]);
		ll idx = Iter - lsi.begin();

		if (idx > 0 && lsi[idx - 1] < vec[i]) // 条件文の前半怪しい
		{
			lsi[idx] = vec[i];
		}
	}

	for (ll i = size; i >= 0; i--)
	{
		if (lsi[i] < LLINF)
		{
			return i;
		}
	}
}

//---------------------------------------------------------------
// 木の根からの深さ
//---------------------------------------------------------------
vll tree_depth(vvll edge, ll start_node, ll n_node)
{
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
// ワーシャルフロイド法(O(N^3)) 任意の2点間の最短距離
//---------------------------------------------------------------
vvll warshall_floyd(ll n, vvll d) {
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
class UnionFind {
public:
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


//========================================================================






int main() {

	////==================================
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(30);
	////==================================



	ll A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	ll ans = LLINF;
	for (int a = 0; a <= X; a++)
	{

		ll rest_X = X - a;
		ll rest_Y = Y;

		ll money = a * A + rest_X * 2 * C;

		if (rest_Y > rest_X)
		{
			money += min((rest_Y - rest_X) * B,  (rest_Y-rest_X) * 2* C);
		}
		ans = min(ans, money);

	}

	cout << ans << endl;




}







