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
#include <cassert>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e18;
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

int main(){
	ll N;
	cin >> N;
	vll A(3 * N + 1);
	repn(i, 3 * N)cin >> A[i];

	vvll dp(N + 1, vll(N + 1, -INF));
	vll R(N + 1, -INF);
	ll M = 0;
	ll S = 0;

	dp[A[1]][A[2]] = 0;
	dp[A[2]][A[1]] = 0;
	R[A[1]] = 0;
	R[A[2]] = 0;

	repn(i, N-1) {
		ll a = A[3 * i];
		ll b = A[3 * i + 1];
		ll c = A[3 * i + 2];

		map<pair<ll, ll>, ll> mp;

		repn(j, N) {
			if (R[j] < 0) { continue; }
			
			mp[{j, a}] = R[j];
			if (b == c) { mp[{j, a}] = max(mp[{j, a}], dp[j][b] + S + 1); }
			
			mp[{j, b}] = max(mp[{j, b}], R[j]);
			if (c == a) { mp[{j, b}] = max(mp[{j, b}], dp[j][c] + S + 1); }
			mp[{j, c}] = max(mp[{j, c}], R[j]);
			if (a == b) { mp[{j, c}] = max(mp[{j, c}], dp[j][a] + S + 1); }
		}
		

		mp[{a, b}] = max(mp[{a, b}], max(M, dp[c][c] + S + 1));
		mp[{b, c}] = max(mp[{b, c}], max(M, dp[a][a] + S + 1));
		mp[{c, a}] = max(mp[{c, a}], max(M, dp[b][b] + S + 1));

		if (a == b && b == c) {
			S++;
			repn(j, N)R[j]++;
			M++;
		}

		for (auto p : mp) {
			ll x = p.first.first;
			ll y = p.first.second;
			//cout << x << y << " " << p.second << endl;
			dp[x][y] = max(dp[x][y],p.second - S);
			if (mp.count({ y,x })) { dp[x][y] = max(mp[{y, x}] - S,dp[x][y]); }
			dp[y][x] = dp[x][y];
			R[x] = max(R[x], p.second);
			R[y] = max(R[y], p.second);
			M = max(M, p.second);
		}

		//repn(j, N) {
		//	repn(k, N) { cout << dp[j][k]<<" "; }
		//	cout << endl;
		//}
		//cout << S << endl;
		//repn(j, N)cout << R[j] << " ";
		//cout << M << endl;

	}

	M = max(M, dp[A[3 * N]][A[3 * N]] + S + 1);
	cout << M << endl;
}

