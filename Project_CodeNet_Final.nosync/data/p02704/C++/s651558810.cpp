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

typedef unsigned long long ll;
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

vvll solve(vll s, vll t, vll u, vll v) {
	vvll g(N, vll(N,-1));

	rep(i, N) {
		if (s[i] == 0 && u[i] == 1) {
			rep(j, N)g[i][j] = 1;
		}
		if (s[i] == 1 && u[i] == 0) {
			rep(j, N)g[i][j] = 0;
		}
		if (t[i] == 0 && v[i] == 1) {
			rep(j, N)g[j][i] = 1;
		}
		if (t[i] == 1 && v[i] == 0) {
			rep(j, N)g[j][i] = 0;
		}
	}

	vll gyo(N, -1), re(N, -1);
	vll gyook(N, 1), reok(N, 1);

	ll cg = 0;
	rep(i, N) {
		if (s[i] == u[i]) {
			gyo[i] = cg;
			cg++;
			bool b = 0;
			rep(j, N) { if (g[i][j] == u[i]) { b = 1; } }
			gyook[i] = b;
		}
	}
	ll cr = 0;
	rep(j, N) {
		if (t[j] == v[j]) {
			re[j] = cr;
			cr++;
			bool b = 0;
			rep(i, N) { if (g[i][j] == v[j]) { b = 1; } }
			reok[j] = b;
		}

	}

	if (cg == 1) {
		rep(i, N)rep(j, N) {
			if (gyo[i] != -1 && re[j] != -1) {
				if (reok[j]) { g[i][j] = u[i]; }
				else { g[i][j] = v[j]; }
			}
		}
	}

	else if (cr == 1) {
		rep(i, N)rep(j, N) {
			if (re[j] != -1 && gyo[i] != -1) {
				if (gyook[i]) { g[i][j] = v[j]; }
				else { g[i][j] = u[i]; }
			}
		}
	}

	else {
		rep(i, N)rep(j, N) {
			if (re[j] != -1 && gyo[i] != -1) {
				g[i][j] = (gyo[i] + re[j]) % 2;
			}
		}
	}

	//cout << re[0] << gyo[0] << endl;

	rep(i, N) {
		if (s[i] == 0) {
			bool b = 1;
			rep(j, N)b &= g[i][j];
			if (b != u[i]) { cout << -1 << endl; exit(0); }
		}
		if (s[i] == 1) {
			bool b = 0;
			rep(j, N)b |= g[i][j];
			if (b != u[i]) { cout << -1 << endl; exit(0); }
		}
	}

	rep(j, N) {
		if (t[j] == 0) {
			bool b = 1;
			rep(i, N)b &= g[i][j];
			if (b != v[j]) { cout << -1 << endl; exit(0); }
		}
		if (t[j] == 1) {
			bool b = 0;
			rep(i, N)b |= g[i][j];
			if (b != v[j]) { cout << -1 << endl; exit(0); }
		}
	}

	return g;
}


int main() {
	cin >> N;
	vll S(N), T(N), U(N), V(N);
	rep(i, N)cin >> S[i];
	rep(i, N)cin >> T[i];
	rep(i, N)cin >> U[i];
	rep(i, N)cin >> V[i];

	vvll ans(N, vll(N, 0));

	rep(bt, 64){/////
		vll u(N), v(N);
		rep(i, N) {
			u[i] = (U[i] >> bt) & 1;
			v[i] = (V[i] >> bt) & 1;
		}

		vvll g = solve(S, T, u, v);

		rep(i, N)rep(j, N) {
			ans[i][j] += g[i][j] * (1ull << bt);
		}

		//cout << bt << endl;
	}

	rep(i, N) {
		rep(j, N)cout << ans[i][j] << " ";
		cout << endl;
	}
}
