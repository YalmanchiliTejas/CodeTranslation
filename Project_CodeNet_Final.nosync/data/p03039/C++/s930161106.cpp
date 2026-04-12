#include<iostream>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<functional>
#include<tuple>
#include<cctype>
#include<stdint.h>
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef int_fast64_t ll;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> piii;
typedef pair<pii, pii> piiii;
typedef pair<ll, bool> pib;

typedef vector<bool> vb;

typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

typedef vector<double> vf;

typedef queue<ll> qi;

typedef long double ld;

#define mp make_pair
#define mt make_tuple
#define pb push_back

#define rep(i, N) for(ll i = 0; i < N; i++)
#define repa(i, a, N) for(ll i = a; i < N; i++)
#define repr(i, N) for(ll i = N-1; i >= 0; i--)

#define drep(i, N, j, M) rep(i, N) rep(j, M)
#define trep(i, N, j, M, k, L) rep(i, N) rep(j, M) rep(k, L)

#define all(A) A.begin(), A.end()
#define uni(A) A.erase(unique(all(A)), A.end())

const ll LLMAX = numeric_limits<ll>::max() / 3;
const ld LDMAX = numeric_limits<ld>::max() / 3;
const ld PI = 3.141592653589793;
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;

template <ll Modulus>
class modint {
public:
	ll a;
	constexpr modint(const ll x = 0) noexcept : a(x % Modulus) {}
	constexpr ll &value() noexcept { return a; }
	constexpr const ll &value() const noexcept { return a; }
	constexpr modint operator+() const noexcept { return *this; }
	constexpr modint operator-() const noexcept { return modint(0LL) -= modint(*this); }
	constexpr modint operator+(const modint rhs) const noexcept { return modint(*this) += rhs; }
	constexpr modint operator-(const modint rhs) const noexcept { return modint(*this) -= rhs; }
	constexpr modint operator*(const modint rhs) const noexcept { return modint(*this) *= rhs; }
	constexpr modint operator/(const modint rhs) const noexcept { return modint(*this) /= rhs; }
	constexpr modint &operator+=(const modint rhs) noexcept { a += rhs.a; if (a >= Modulus) { a -= Modulus; }return *this; }
	constexpr modint &operator-=(const modint rhs) noexcept { if (a < rhs.a) { a += Modulus; }a -= rhs.a; return *this; }
	constexpr modint &operator*=(const modint rhs) noexcept { a = a * rhs.a % Modulus; return *this; }
	constexpr modint &operator/=(modint rhs) noexcept { ll exp = Modulus - 2; while (exp) { if (exp % 2) { *this *= rhs; }rhs *= rhs; exp /= 2; }return *this; }
};
typedef modint<MOD> mod;

constexpr const mod operator+(const ll a, const mod b) noexcept{ return mod(a) += b; }
constexpr const mod operator-(const ll a, const mod b) noexcept{ return mod(a) -= b; }
constexpr const mod operator*(const ll a, const mod b) noexcept{ return mod(a) *= b; }
constexpr const mod operator/(const ll a, const mod b) noexcept{ return mod(a) /= b; }

template <class T> class SegTree {
	ll n;vector<T> data;T def;function<T(T, T)> operation;function<T(T, T)> update;T _query(ll a, ll b, ll k, ll l, ll r) {if (r <= a || b <= l) return def;if (a <= l && r <= b)return data[k];else {T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2);T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r);return operation(c1, c2);}}
public:
	// _n: サイズ, _def: 初期値・単位元, _operation: クエリ, _update: 更新
	SegTree(ll _n, T _def, function<T(T, T)> _operation,function<T(T, T)> _update): def(_def), operation(_operation), update(_update) {n = 1;while (n < _n) {n *= 2;}data = vector<T>(2 * n - 1, def);}
	// iの値をxに変更
	void change(ll i, T x) {i += n - 1;data[i] = update(data[i], x);while (i > 0) {i = (i - 1) / 2;data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);}}
	// [a, b)の区間クエリ実行
	T query(ll a, ll b) {return _query(a, b, 0, 0, n);}
	// 添え字アクセス
	constexpr const T operator[](ll i) const noexcept {return data[i + n - 1];}
	constexpr const ll size() const noexcept { return n; }
	constexpr const T unit() const noexcept { return def; }
};

/*
SegTree<ll> st(N, LLMAX,
	// a: left child, b: right child
	[](ll a, ll b) {return min(a, b); },
	// d: old, x: query
	[](ll d, ll x) {return x; });
// */


template<class t, class u>ostream& operator<<(ostream& os, const pair<t, u>& p) { return os << "{" << p.first << "," << p.second << "}"; }
template<class t>ostream& operator<<(ostream& os, const vector<t>& v) { os << "{";	for (auto e : v)os << e << ",";	return os << "}" << endl; }
template<class t, class u>ostream& operator<<(ostream& os, const unordered_map<t, u>& m) { os << "{"; for (auto itr = m.begin(); itr != m.end(); ++itr) { os << "(" << itr->first << ", " << itr->second << "), "; }	return os << "}"; }
template<class t>ostream& operator<<(ostream& os, const set<t>& m) { os << "{";	for (auto itr = m.begin(); itr != m.end(); ++itr) { os << *itr << ", "; }return os << "}"; }
template<class t>ostream& operator<<(ostream& os, const multiset<t>& m) { os << "{"; for (auto itr = m.begin(); itr != m.end(); ++itr) { os << *itr << ", "; }return os << "}"; }
template<ll Modulus>ostream& operator<<(ostream& os, const modint<Modulus>& m) { return os << (m.a + Modulus) % Modulus; }

template<class t>ostream& operator<<(ostream& os, const SegTree<t>& st) {
	os << "{";
	ll s = st.size();
	rep(i, s){
		t v = st[i];
		if (v == st.unit()) {
			os << "-, ";
		}
		else {
			os << v << ", ";
		}
	}
	return os << "}\n";
}

typedef vector<mod> vm;
typedef vector<vm> vvm;
typedef vector<vvm> vvvm;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void No() { cout << "No" << endl; }
void Yes() { cout << "Yes" << endl; }
void NO() { cout << "NO" << endl; }
void YES() { cout << "YES" << endl; }

vector<ll> fac(1e7 + 1); //n!(mod M)
vector<ll> ifac(1e7 + 1); //k!^{M-2} (mod 
//x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
ll mpow(ll x, ll n) { 
	ll ans = 1;
	while (n != 0) {
		if (n & 1) ans = ans * x % MOD;
		x = x * x % MOD;
		n = n >> 1;
	}
	return ans;
}

ll comb(ll a, ll b) { //aCbをmod計算
	if (a == 0 && b == 0)return 1;
	if (a < b || a < 0)return 0;
	ll tmp = ifac[a - b] * ifac[b] % MOD;
	return tmp * fac[a] % MOD;
}

void pre_calc_comb() {
	fac[0] = 1;
	ifac[0] = 1;
	for (ll i = 0; i < 1e7; i++) {
		fac[i + 1] = fac[i] * (i + 1) % MOD; // n!(mod M)
		ifac[i + 1] = ifac[i] * mpow(i + 1, MOD - 2) % MOD; // k!^{M-2} (mod M) ←累乗にmpowを採用
	}
}

ll gcd(ll a, ll b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;

	if (a%b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a%b));
	}
}

ll N, M, K, Q;
ll ans = 0;
ll H, W;
string S;

void solve() {
	cin >> N >> M >> K;
	// NM
	// xについて考える
	// |xi - xj| = aのとき
	// xi < xj
	// xiが 1 ~ (N - a) 
	// xjは 1+a ~ N
	// の N - a 個
	// M * M * (N - a)

	// (N*M - 2)_C_K

	pre_calc_comb();
	mod c = comb(N * M - 2, K - 2);

	mod ans = 0;
	repa(a, 1, N) {
		mod num = M * M * (N - a);
		ans += a * num * c;
	}

	repa(a, 1, M) {
		mod num = N * N * (M - a);
		ans += a * num * c;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
