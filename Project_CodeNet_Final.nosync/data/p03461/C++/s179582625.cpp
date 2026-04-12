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
const double eps = 1E-18;

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
	mint ret = pw(a, b>>1);
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


//////////////////////////

int main() {
	ll A, B;
	cin >> A >> B;

	vvll d(A + 1, vll(B + 1));
	repn(i, A)repn(j, B) cin >> d[i][j];

	vll a, b, c;

	ll k = 1;
	rep(x, 101)rep(y, 101) {
		ll k = -1;

		repn(i, A)repn(j, B) {
			k = max(d[i][j] - x * i - y * j, k);
		}
		
		if (k >= 0) { a.push_back(x); b.push_back(y); c.push_back(k);}
	}

	ll M = a.size();

	bool tf = 1;

	repn(i, A)repn(j, B) {
		ll dis = INF;
		rep(l, M) {
			dis = min(dis, a[l] * i + b[l] * j + c[l]);
		}
		if (dis != d[i][j]) { tf = 0; }
	}

	if (tf == 0) { cout << "Impossible" << endl; return 0; }

	cout << "Possible" << endl;

	cout << 202 << " " << 200 + M << endl;

	repn(i, 100) {
		cout << i << " " << i + 1 << " " << "X" << endl;
	}
	repn(i, 100) {
		cout << 101 + i << " " << 101 + i + 1 << " " << "Y" << endl;
	}
	rep(i, M) {
		cout << a[i] + 1 << " " << 202 - b[i] << " " << c[i] << endl;
	}
	cout << 1 << " " << 202 << endl;
	
}
