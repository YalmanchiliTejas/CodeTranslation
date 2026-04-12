#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
using str = string;
using vl = vector<ll>;
using vs = vector<str>;
using listl = list<ll>;

#define min(A, B) min(static_cast<ll>(A), static_cast<ll>(B))
#define max(A, B) max(static_cast<ll>(A), static_cast<ll>(B))
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back

#define rep(i, m)		for(ll i = 0, i_max = m; i < i_max; i++)
#define erep(i, m)		for(ll i = 0, i_max = m; i <= i_max; i++)
#define nrep(i, b, m)	for(ll i = b, i_max = m; i < i_max; i++)
#define enrep(i, b, m)	for(ll i = b, i_max = m; i <= i_max; i++)
#define brep(i, m)		for(ll i = m; i >= 0; i--)
#define ebrep(i, b, e)	for(ll i = b; i >= e; i--)

#define _rep(m)			rep(i, m)
#define _erep(m)		erep(i, m)
#define _nrep(b, m)		nrep(i, b, m)
#define _enrep(b, m)	enrep(i, b, m)
#define _brep(m)		brep(i, m)
#define _ebrep(b, e)	ebrep(i, b, e)

// modint: mod 計算を int を扱うように扱える構造体
template<int MOD> struct Fp {
	ll val;
	constexpr Fp(ll v = 0) noexcept : val(v % MOD) {
		if (val < 0) val += MOD;
	}
	constexpr int getmod() { return MOD; }
	constexpr Fp operator - () const noexcept {
		return val ? MOD - val : 0;
	}
	constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
	constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
	constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
	constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
	constexpr Fp& operator += (const Fp& r) noexcept {
		val += r.val;
		if (val >= MOD) val -= MOD;
		return *this;
	}
	constexpr Fp& operator -= (const Fp& r) noexcept {
		val -= r.val;
		if (val < 0) val += MOD;
		return *this;
	}
	constexpr Fp& operator *= (const Fp& r) noexcept {
		val = val * r.val % MOD;
		return *this;
	}
	constexpr Fp& operator /= (const Fp& r) noexcept {
		ll a = r.val, b = MOD, u = 1, v = 0;
		while (b) {
			ll t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		val = val * u % MOD;
		if (val < 0) val += MOD;
		return *this;
	}
	constexpr bool operator == (const Fp& r) const noexcept {
		return this->val == r.val;
	}
	constexpr bool operator != (const Fp& r) const noexcept {
		return this->val != r.val;
	}
	friend ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
		return os << x.val;
	}
	friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, ll n) noexcept {
		if (n == 0) return 1;
		auto t = modpow(a, n / 2);
		t = t * t;
		if (n & 1) t = t * a;
		return t;
	}
};

const int MOD = 998244353;
using mint = Fp<MOD>;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

void in(ll& I)
{
	cin >> I;
}

void in(vl& I)
{
	for (auto& i : I)
	{
		cin >> i;
	}
}

void in(vs& I)
{
	for (auto& i : I)
	{
		cin >> i;
	}
}

void in(listl& I)
{
	for (auto& i : I)
	{
		cin >> i;
	}
}

void in(str& s)
{
	cin >> s;
}

void out(ll O)
{
	cout << O;
}

void out(vl& O)
{
	for (auto& o : O)
	{
		cout << o << endl;
	}
}

void rout(bool b, str True, str False)
{
	if (b) cout << True.c_str();
	else cout << False.c_str();
}

const int INF = 1LL << 30;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dp[3030][3030];

int main()
{
    int n;
    cin >>n;
    
    puts(n>=30?"Yes":"No");

	return 0;
}

