#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
#include<complex>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 4000001;
const long double eps = 1E-14;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};

class mint {
	long long x;
public:
	mint(long long x = 0) : x((x% MOD + MOD) % MOD) {}
	mint operator-() const {
		return mint(-x);
	}
	mint& operator+=(const mint& a) {
		if ((x += a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint& operator-=(const mint& a) {
		if ((x += MOD - a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint& operator*=(const  mint& a) {
		(x *= a.x) %= MOD;
		return *this;
	}
	mint operator+(const mint& a) const {
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint& a) const {
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint& a) const {
		mint res(*this);
		return res *= a;
	}

	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}

	// for prime MOD
	mint inv() const {
		return pow(MOD - 2);
	}
	mint& operator/=(const mint& a) {
		return (*this) *= a.inv();
	}
	mint operator/(const mint& a) const {
		mint res(*this);
		return res /= a;
	}

	friend ostream& operator<<(ostream& os, const mint& m) {
		os << m.x;
		return os;
	}
};

mint pw(mint a, ll b) {
	if (b == 0) { return 1; }
	mint ret = pw(a, b >> 1);
	ret *= ret;
	if (b & 1) { ret *= a; }
	return ret;
}

typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;

typedef vector<mint> vmint;
typedef vector<vector<mint>> vvmint;
typedef vector<vector<vector<mint>>> vvvmint;

//////////////////////////////////////
ll N;
vll a(N + 1);

vll op(ll x) {
	ll t = a[1] - (N + 1) * x;

	vll ret(N + 1, 0);

	ll sousa = 0;
	repn(i, N) {
		ll k = 0;

		if (a[i] > t) {
			k=(a[i] - t - 1) / (N + 1) + 1;
			sousa += k;
		}
		
		ret[i] = a[i] - (N + 1) * k;
	}

	repn(i, N) { ret[i] += sousa; }

	sort(++ret.begin(), ret.end(), greater<ll>());

	return ret;
}

bool ch(ll x, ll M) {//a[1]に対し操作をx回おこなったとき、最大値がM以下になるか
	vll c = op(x);
	if (c[1] > M) { return false; }

	return true;
	
}

vll one(vll c) {
	c[1] -= (N + 1);
	repn(i, N) c[i]++;
	sort(++c.begin(), c.end(), greater<ll>());
	return c;
}

int main() {
	cin >> N;
	a.assign(N + 1, 0);
	repn(i, N) cin >> a[i];
	sort(++a.begin(), a.end(), greater<ll>());

	ll M = 1000;

	ll l = -1;
	ll r = INF;
	while (r - l > 1) {
		ll m = (r + l) / 2;
		if (ch(m, M)) { r = m; }
		else { l = m; }
	}

	vll c = op(r);

	while (c[1]>N-1) {
		c = one(c);
	}

	ll ans = 0;
	repn(i, N) ans += a[i] - c[i];
	cout << ans << endl;

	

}