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

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
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
#define pb push_back

#define rep(i, N) for(ll i = 0; i < N; i++)
#define repa(i, a, N) for(ll i = a; i < N; i++)
#define repr(i, N) for(ll i = N-1; i >= 0; i--)

#define drep(i, N, j, M) rep(i, N) rep(j, M)
#define trep(i, N, j, M, k, L) rep(i, N) rep(j, M) rep(k, L)

#define all(A) A.begin(), A.end()
template<class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
	return os << "{" << p.first << "," << p.second << "}";
}

template<class t>
ostream& operator<<(ostream& os, const vector<t>& v) {
	os << "{";
	for (auto e : v)os << e << ",";
	return os << "}";
}

template<class t, class u>
ostream& operator<<(ostream& os, const unordered_map<t, u>& m) {
	os << "{";
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		os << "(" << itr->first << ", " << itr->second << "), ";
	}
	return os << "}";
}

template<class t>
ostream& operator<<(ostream& os, const set<t>& m) {
	os << "{";
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		os << *itr << ", ";
	}
	return os << "}";
}

template<class t>
ostream& operator<<(ostream& os, const multiset<t>& m) {
	os << "{";
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		os << *itr << ", ";
	}
	return os << "}";
}


const ll LLMAX = numeric_limits<long long>::max() / 3;
const double DMAX = numeric_limits<double>::max() / 3;

const double PI = 3.141592653589793;
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;

template <std::int_fast64_t Modulus> class modint {
	using i64 = std::int_fast64_t;

public:
	i64 a;

	constexpr modint(const i64 x = 0) noexcept : a(x % Modulus) {}
	constexpr i64 &value() noexcept { return a; }
	constexpr const i64 &value() const noexcept { return a; }
	constexpr modint operator+(const modint rhs) const noexcept {
		return modint(*this) += rhs;
	}
	constexpr modint operator-(const modint rhs) const noexcept {
		return modint(*this) -= rhs;
	}
	constexpr modint operator*(const modint rhs) const noexcept {
		return modint(*this) *= rhs;
	}
	constexpr modint operator/(const modint rhs) const noexcept {
		return modint(*this) /= rhs;
	}
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
		i64 exp = Modulus - 2;
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

template<std::int_fast64_t Modulus>
ostream& operator<<(ostream& os, const modint<Modulus>& m) {
	return os << (m.a + Modulus) % Modulus;
}

typedef modint<MOD> mod;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll PowInt(ll a, ll n) {
	ll t = 1;
	rep(i, n) {
		t *= a;
	}
	return t;
}

void No() { cout << "No" << endl; }
void Yes() { cout << "Yes" << endl; }
void NO() { cout << "NO" << endl; }
void YES() { cout << "YES" << endl; }

vector<ll> fac(1e6+1); //n!(mod M)
vector<ll> ifac(1e6+1); //k!^{M-2} (mod 
ll mpow(ll x, ll n) { //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
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
	for (ll i = 0; i < 1e6; i++) {
		fac[i + 1] = fac[i] * (i + 1) % MOD; // n!(mod M)
		ifac[i + 1] = ifac[i] * mpow(i + 1, MOD - 2) % MOD; // k!^{M-2} (mod M) ←累乗にmpowを採用
	}
}

ll x;

ll N, M, K;
ll ans;

int main() {
	string S;
	cin >> S;
	if (S[0] == S[1] && S[1] == S[2]) {
		No();
	}
	else {
		Yes();
	}

	return 0;
}
