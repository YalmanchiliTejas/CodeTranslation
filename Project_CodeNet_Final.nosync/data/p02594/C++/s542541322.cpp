#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(long long i = 0; i < (n); i++)
#define rrep(i, n) for(long long i = (n)-1; i > -1; i--)
#define Rep(i, m, n) for(long long i = (m); i < (n); i++)
#define rRep(i, m, n) for(long long i = (n)-1; i >= (m); i--)
#define REP(i, m, n, p) for(long long i = m; i < n; i += p)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pq priority_queue
#define bcnt(n) __builtin_popcountll(n)
#define endk endl
#define ednl endl
#define enld endl
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using mii = map<int, int>;
using pqll = priority_queue<long long>;
using pqllg = priority_queue<long long, vector<long long>, greater<long long>>;
using mll = map<long long, long long>;
using pll = pair<long long, long long>;
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

long long const limLL = 9223372036854775807;  // POW(2,63)-1.
long long const dekai = 1e15;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ddx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ddy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int mod = 1000000007;
// const int mod = 998244353;
const long double pi = acos(-1);

// // 多倍長テンプレ
// /* ---------------------- ここから ---------------------- */
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// // 任意長整数型
// using Bint = mp::cpp_int;
// // 仮数部が1024ビットの浮動小数点数型(TLEしたら小さくする)
// using Real = mp::number<mp::cpp_dec_float<1024>>;
// /* ---------------------- ここまで ---------------------- */

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

//端数繰りあがり割り算(検証済)
// a÷bの端数繰り上げ
template <class T>
T divup(T a, T b) {
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

// 整数のとき限定の普通のPOW関数
//標準機能のpow(a,n)は整数だとバグるのでこちらを使う
long long POW(long long a, long long n) {
	long long res = 1;
	while(n > 0) {
		if(n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

//素数判定
//素数ならばtrue、素数以外の整数にはfalse
//負数は全てfalse
//検証済み
template <class T>
bool prime(T N) {
	if(N <= 1) return false;
	T p = sqrt(N);
	for(long long i = 2; i <= p; i++)
		if(N % i == 0) return false;
	return true;
}

//ベクトルの出力(検証済)
// vectorの中身を出力する 答えの出力に利用可能
template <class T>
void vout(vector<T> &v) {
	if(v.size() > 0) {
		for(auto it = v.begin(); it < v.end(); it++) {
			cout << *it;
			if(it != v.end() - 1) cout << " ";
		}
	}
	cout << endl;
}

//引数ベクトルに同一要素が複数あるとき、先頭を残し他は削除したベクトルを返す
//ベクトル長も変化する
// O(nlogn)くらい
template <class T>
vector<T> singlized(vector<T> &v) {
	set<T> s;
	vector<T> ret;
	for(auto seg : v) {
		if(!s.count(seg)) {
			ret.push_back(seg);
			s.insert(seg);
		}
	}
	return ret;
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

//配列圧縮(同順位なし)
//{1,36,1,3,8,-2,-92}を
//{2, 6,3,4,5, 1,  0}にする
template <class T>
vector<long long> ranking(vector<T> &v) {
	vector<pair<T, long long>> r;
	long long n = v.size();
	rep(i, n) r.push_back({v[i], i});
	sort(all(r));
	vll res(n);
	rep(i, n) { res[r[i].second] = i; }
	return res;
}

//着順配列
// (placesort(v)).[i] = i番目に小さい要素が入っている箇所
template <class T>
vector<long long> sortedplace(vector<T> &v) {
	auto w = ranking(v);
	ll n = v.size();
	vll res(n);
	rep(i, n) res[w[i]] = i;
	return res;
}

// 10進法でn桁の整数xに対して、大きい方の位から、その位の1桁の数字を
//収納した長さnのベクトルを返す
// 0に対しては{}を返す
//検証済み
vector<long long> keta(ll x) {
	vll w;
	while(x > 0) {
		w.push_back(x % 10);
		x /= 10;
	}
	reverse(all(w));
	return w;
}

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while(n > 0) {
		if(n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

// a^{-1} mod を計算する
// modとaが互いに素のときのみ有効(数学的に逆元が一意に定まるのがそのときのみ)
long long modinv(long long a, long long mod) { return modpow(a, mod - 2, mod); }

//整数n個の入力を受け取ってベクトルに突っ込んで返す
//チェック済み
vector<long long> vin(long long n) {
	vector<long long> v(n);
	for(long long i = 0; i < n; i++) {
		cin >> v[i];
	}
	return v;
}

vector<long long> yakusuu(long long n) {  // nの約数を列挙
	vector<long long> ret;
	long long sq = sqrt(n);
	for(long long i = 1; i <= sq; ++i) {
		if(n % i == 0) {
			ret.push_back(i);
			if(i * i != n) {
				ret.push_back(n / i);
			}
		}
	}
	sort(ret.begin(), ret.end());
	return ret;
}

map<long long, long long> soinsuu(long long n) {
	map<long long, long long> m;
	long long p = sqrt(n);
	while(n % 2 == 0) {
		n /= 2;
		if(m.count(2)) {
			m[2]++;
		} else {
			m[2] = 1;
		}
	}
	for(long long i = 3; i * i <= n; i += 2) {
		while(n % i == 0) {
			n /= i;
			if(m.count(i)) {
				m[i]++;
			} else {
				m[i] = 1;
			}
		}
	}
	if(n != 1) m[n] = 1;
	return m;
}

//エラトステネスのふるい
//素数なら1,素数でないなら0
vector<long long> eratos(long long n) {
	assert(n >= 0);
	vll v(n + 1, 1);
	if(n >= 0) v[0] = 0;
	if(n >= 1) v[1] = 0;
	Rep(i, 2, n + 1) {
		if(v[i]) {
			for(ll k = i * 2; k < n + 1; k += i) {
				v[k] = 0;
			}
		}
	}
	return v;
}
// n以下の素数のみを入れたvector
vector<long long> primevec(long long n) {
	vll v = eratos(n);
	vll ret;
	Rep(i, 2, n + 1) if(v[i]) ret.push_back(i);
	return ret;
}
// n以下の素数を全て詰めたset
set<long long> primeset(long long n) {
	vll v = eratos(n);
	sll s;
	Rep(i, 2, n + 1) if(v[i]) s.insert(i);
	return s;
}

// vectorの中身を数える map<要素,個数>を返す
template <class T>
map<T, long long> countv(vector<T> v) {
	map<T, long long> m;
	for(auto &g : v) {
		if(m.count(g))
			m[g]++;
		else
			m[g] = 1;
	}
	return m;
}

// nCk modを求める
const ll MAX = 510000;
// この値は求める二項計数の値に応じて変える
// MAX=3*10^7のとき1900msほど、ほぼ比例
// MAX=5*10^6程度ならそれほど気にしなくてよい(300ms程)
long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void cominit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(ll i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}
// 二項係数計算
long long commod(ll n, ll k) {
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
//順列計算
long long pmod(ll n, ll k) {
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * finv[n - k] % mod;
}
// nHk計算
// n個の区別しないoを区別するk個の箱に入れる方法の総数
//(n+k-1)C(k-1)と等しい
long long hmod(ll n, ll k) { return commod(n + k - 1, n); }

/* next combination */
//次の組み合わせをbitで返す
//全探索のloopに使える
long long next_combination(long long sub) {
	long long x = sub & -sub, y = sub + x;
	return (((sub & ~y) / x) >> 1) | y;
}

// 20200617
template <class T>
void warshall(vector<vector<T>> &v) {
	ll n = v.size();
	rep(i, n) {
		rep(j, n) {
			rep(k, n) { v[j][k] = min(v[j][k], v[j][i] + v[i][k]); }
		}
	}
	return;
}

// 20200626
//普通の二項計数(overflowに注意)
vvll comb(100, vll(100, -1));
long long com(long long n, long long k) {
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

// 20200709
string bits(long long n, long long k) {
	// nをk桁のbitで表示したstringを返す
	string s = "";
	rep(i, k) {
		char c = '0' + (n % 2);
		s += c;
		n /= 2;
	}
	reverse(all(s));
	return s;
}

// 1次元累積和
template <class T>
vector<T> barsuminit(vector<T> &v) {
	ll h = v.size();
	V<T> ret(h + 1);
	ret[0] = 0;
	rep(i, h) ret[i + 1] = v[i] + ret[i];
	return ret;
}
template <class T>
T barsum(vector<T> &v, ll x0, ll x1) {
	if(x1 <= x0) return 0;
	return v[x1] - v[x0];
}
// 2次元累積和
template <class T>
vector<vector<T>> sheetsuminit(vector<vector<T>> &v) {
	ll h = v.size();
	assert(h != 0);
	ll w = v.at(0).size();
	VV<T> ret(h + 1, V<T>(w + 1));
	rep(i, h + 1) ret[i][0] = 0;
	rep(i, w + 1) ret[0][i] = 0;
	rep(i, h) rep(j, w) ret[i + 1][j + 1] = v[i][j];
	rep(i, h) rep(j, w) ret[i + 1][j + 1] += ret[i + 1][j];
	rep(i, h) rep(j, w) ret[i + 1][j + 1] += ret[i][j + 1];
	return ret;
}
//[x0,y0],(x1,y1)で囲まれた領域内の和
//端点は(x,y)のみ含む.面積は(x1-x0)*(y1-y0);
template <class T>
T sheetsum(vector<vector<T>> &v, ll x0, ll y0, ll x1, ll y1) {
	if(x0 >= x1 || y0 >= y1) return 0;
	return v[x0][y0] + v[x1][y1] - v[x0][y1] - v[x1][y0];
}
// 3次元累積和
template <class T>
vector<vector<vector<T>>> cubiodsuminit(vector<vector<vector<T>>> &v) {
	ll h = v.size();
	assert(h != 0);
	ll w = v[0].size();
	assert(w != 0);
	ll z = v[0][0].size();
	VVV<T> ret(h + 1, VV<T>(w + 1, V<T>(z + 1)));
	rep(i, h + 1) rep(j, w + 1) rep(k, z + 1) { ret[i][j][k] = (i == 0 || j == 0 || k == 0 ? 0 : v[i - 1][j - 1][k - 1]); }
	rep(i, h) rep(j, w) rep(k, z) ret[i + 1][j + 1][k + 1] += ret[i + 1][j + 1][k];
	rep(i, h) rep(j, w) rep(k, z) ret[i + 1][j + 1][k + 1] += ret[i + 1][j][k + 1];
	rep(i, h) rep(j, w) rep(k, z) ret[i + 1][j + 1][k + 1] += ret[i][j + 1][k + 1];
	return ret;
}
//[x0,y0],(x1,y1)で囲まれた領域内の和
//端点は(x,y)のみ含む.面積は(x1-x0)*(y1-y0);
template <class T>
T cubiodsum(vector<vector<vector<T>>> &v, ll x0, ll y0, ll z0, ll x1, ll y1, ll z1) {
	if(x0 >= x1 || y0 >= y1 || z0 >= z1) return 0;
	return v[x1][y1][z1] - v[x1][y1][z0] - v[x1][y0][z1] - v[x0][y1][z1] + v[x1][y0][z0] + v[x0][y1][z0] + v[x0][y0][z1] - v[x0][y0][z0];
}
//////////////////////////////////////////

struct UF {						  //サイズが測れるUF
	vector<long long> par, size;  // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
	// sizeはiを根とする木のサイズ
	UF(long long N) : par(N), size(N) {	 //最初は全てが根であるとして初期化
		for(long long i = 0; i < N; i++) {
			par[i] = i;
			size[i] = 1;
		}
	}

	long long root(long long x) {  // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
		if(par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(long long x, long long y) {	// xとyの木を併合
		long long rx = root(x);				// xの根をrx
		long long ry = root(y);				// yの根をry
		if(rx == ry) return;				// xとyの根が同じ(=同じ木にある)時はそのまま
		par[rx] = ry;						// xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
		size[ry] += size[rx];
		size[rx] = 0;  //サイズの処理 根じゃなくなったらサイズは0になる
	}

	bool same(long long x, long long y) {  // 2つのデータx, yが属する木が同じならtrueを返す
		long long rx = root(x);
		long long ry = root(y);
		return rx == ry;
	}
};

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division

struct mint {
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
istream &operator>>(istream &is, const mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

// 20200604
struct STmax {	//最大値を測るセグ木
	ll size;	// treeの葉の数=m*2-1
	ll m;		// tree最下段の数
	vector<long long> seg;
	STmax(long long n) : size(n), m(n), seg(0) {
		m = 1;
		while(m < n) {
			m *= 2;
		}
		size = m * 2 - 1;
		rep(i, size) { seg.push_back(-99999999977); }
	}
	void update(ll i, ll k) {  // i番目をkに更新
		ll v = i + m - 1;
		seg[v] = k;
		while(v > 0) {
			v = (v - 1) / 2;
			seg[v] = max(seg[v * 2 + 1], seg[v * 2 + 2]);
		}
	}
	ll query(ll a, ll b, ll k, ll l, ll r) {  //区間[a,b)での最大値を求める
		if(r <= a || b <= l) return -99999999977;
		if(a <= l && r <= b) return seg[k];
		// cout << "#" << a << " " << b << " " << k << " " << l << " " << r << endl;
		ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
	ll largest(ll a, ll b) {
		if(a >= b) return -99999999977;
		return query(a, b, 0, 0, m);
	}
};

struct STmin {	//最小値を測るセグ木
	ll size;	// treeの葉の数=m*2-1
	ll m;		// tree最下段の数
	vector<long long> seg;
	STmin(long long n) : size(n), m(n), seg(0) {
		m = 1;
		while(m < n) {
			m *= 2;
		}
		size = m * 2 - 1;
		rep(i, size) { seg.push_back(99999999977); }
	}
	void update(ll i, ll k) {  // i番目をkに更新
		ll v = i + m - 1;
		seg[v] = k;
		while(v > 0) {
			v = (v - 1) / 2;
			seg[v] = min(seg[v * 2 + 1], seg[v * 2 + 2]);
		}
	}
	ll query(ll a, ll b, ll k, ll l, ll r) {  //区間[a,b)での最大値を求める
		if(r <= a || b <= l) return 99999999977;
		if(a <= l && r <= b) return seg[k];
		// cout << "#" << a << " " << b << " " << k << " " << l << " " << r << endl;
		ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

		return min(vl, vr);
	}
	ll smallest(ll a, ll b) {
		if(a >= b) return 99999999977;
		return query(a, b, 0, 0, m);
	}
};

struct STsum {	//区間の合計値を測るセグ木
	ll size;	// treeの葉の数=m*2-1
	ll m;		// tree最下段の数
	vector<long long> seg;
	STsum(long long n) : size(n), m(n), seg(0) {
		m = 1;
		while(m < n) {
			m *= 2;
		}
		size = m * 2 - 1;

		rep(i, size) { seg.push_back(0); }
		//改造時はここをまず変える
	}
	void update(ll i, ll k) {  // i番目をkに更新
		ll v = i + m - 1;
		seg[v] = k;
		while(v > 0) {
			v = (v - 1) / 2;

			seg[v] = seg[v * 2 + 1] + seg[v * 2 + 2];
			//改造時はここを変える
		}
	}
	ll query(ll a, ll b, ll k, ll l, ll r) {  //区間[a,b)での最大値を求める
		if(r <= a || b <= l) return 0;
		if(a <= l && r <= b) return seg[k];
		// cout << "#" << a << " " << b << " " << k << " " << l << " " << r << endl;
		ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

		return vl + vr;	 //改造時はここを変える
	}
	ll sum(ll a, ll b) {
		if(a >= b) return 0;
		return query(a, b, 0, 0, m);
	}
};

struct edge {
	ll len;
	ll to;
};
struct graph {	// 0-indexed
	vector<vector<edge>> edges;
	bool directed, weight;
	long long ver;

	// constructor
	graph(long long vertex, bool direction = 0, bool weigh = 0) : edges(vertex) {
		ver = vertex;
		directed = direction;
		weight = weigh;
		edges.resize(vertex);
	}

	//辺の追加 (0-indexed)
	void update(long long from, long long to, long long len = 1, bool direction = 1) {
		edge e;
		e.to = to;
		e.len = len;
		edges[from].push_back(e);
		if(!direction) {
			e.to = from;
			edges[to].push_back(e);
		}
	}

	//入力受取 (1-indexed)
	void input(long long edge_num, long long index = 1) {
		rep(i, edge_num) {
			ll a, b;
			cin >> a >> b;
			a -= index;
			b -= index;
			ll c;
			if(weight)
				cin >> c;
			else
				c = 1;
			update(a, b, c, directed);
		}
	}

	//長さが負のpathがないときの単一始点最短経路<vll> O((ver)log(ver)+(edge))
	vector<long long> dijkstra(long long start) {
		vector<long long> ret(ver, dekai);
		pqup<pair<long long, long long>> p;	 //{dist,place}
		p.push({0, start});
		ret[start] = 0;

		while(!p.empty()) {
			ll dist = p.top().first;
			ll place = p.top().second;
			p.pop();
			if(ret[place] < dist) continue;
			for(auto &next : edges[place]) {
				ll nextplace = next.to;
				ll dis = next.len;
				if(chmin(ret[nextplace], dist + dis)) {
					p.push({ret[nextplace], nextplace});
				}
			}
		}
		return ret;
	}

	//単一始点最短経路 O((ver)*(edge))
	//ある頂点までのコストが無限に小さくなり得るとき→ ret[i] = -dekai;
	vector<long long> BellmanFord(long long start) {
		vector<long long> ret(ver, dekai);
		ret[start] = 0;
		rep(loop, ver - 1) {
			rep(v, ver) {
				for(auto &e : edges[v]) {
					chmin(ret[e.to], ret[v] + e.len);
				}
			}
		}

		//無限降下点の検索
		queue<ll> q;
		vb chk(ver, 0);
		rep(v, ver) {
			for(auto &e : edges[v]) {
				if(chmin(ret[e.to], ret[v] + e.len)) {
					if(!chk[e.to]) {
						q.push(e.to);
						chk[e.to] = 1;
					}
				}
			}
		}
		while(!q.empty()) {
			ll now = q.front();
			q.pop();
			for(auto &e : edges[now]) {
				if(!chk[e.to]) {
					chk[e.to] = 1;
					q.push(e.to);
				}
			}
		}
		rep(i, ver) if(chk[i]) ret[i] = -dekai;

		return ret;
	}

	//閉路に含まれない頂点列挙
	//要素数がver未満なら閉路が存在、そうでなければ閉路は存在しない
	vector<long long> topo_sort() {
		assert(directed);
		vector<long long> num_input(ver);
		// 入次数
		for(long long i = 0; i < ver; i++) {
			for(auto e : edges[i]) {
				num_input[e.to]++;
			}
		}
		// 入次数が0のノードをqueueで管理する
		queue<long long> que;
		for(int i = 0; i < ver; i++) {
			if(num_input[i] == 0) {
				que.push(i);
			}
		}
		vector<long long> ans;
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

	//無向木構造を根から葉に伸びる有向木構造に書き換える
	graph RootToLeaf(ll root) {	 // 0-indexed
		graph ret(ver, 1, weight);
		vb chk(ver, 0);
		chk[root] = 1;
		function<void(ll)> dfs = [&](ll now) {
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
	graph LeafToRoot(ll root) {	 // 0-indexed
		graph ret(ver, 1, weight);
		vb chk(ver, 0);
		chk[root] = 1;
		function<void(ll)> dfs = [&](ll now) {
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
	vector<long long> par(ll root) {  // 0-indexed
		vll ret(ver, -1);
		ret[root] = root;  // rootの親はroot
		function<void(ll)> dfs = [&](ll now) {
			for(auto &e : edges[now]) {
				if(ret[e.to] != -1) continue;
				ret[e.to] = now;
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}
	vector<edge> ParentAndDistance(ll root) {  // 0-indexed
		V<edge> ret(ver);
		rep(i, ver) ret[i].to = -1;
		ret[root].to = root;  // rootの親はroot
		ret[root].len = 0;	  // rootの親との距離は0
		function<void(ll)> dfs = [&](ll now) {
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

	VV<ll> GraphArray(void) {
		VV<ll> ret(ver, V<ll>(ver, dekai));
		rep(from, ver) {
			for(auto &e : edges[from]) {
				ret[from][e.to] = e.len;
			}
			ret[from][from] = 0;
		}
		return ret;
	}
};

// //ダブリング
// // reach : 2^reach 先まで検索
// VV<edge> doublize(vll &v, ll reach) {  // vは子から親へのvector
// 	ll n = v.size();
// 	VV<long long> ret(n, 20);
// }

// cout<<fixed<<setprecision(15);
int main() {
ll n;cin>>n;
if(n>=30) cout<<"Yes"<<endl;
else cout<<"No"<<endl;
	
}














