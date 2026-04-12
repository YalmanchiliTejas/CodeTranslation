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

int main() {
	ll N, M;
	cin >> N >> M;
	string S;
	cin >> S;

	ll c = S[0];

	ll K = -1;
	rep(i, M) {
		if (S[i] != c) { K = i; }
	}
	
	if (K == -1) {
		if (N == 1) { cout << 1 << endl; return 0; }
		if (N == 2) { cout << 3 << endl; return 0; }
		vmint dp(N + 1, 0);
		dp[0] = 1;
		dp[1] = 2;

		for (ll i = 2; i <= N; i++) {
			dp[i] = dp[i - 2] + dp[i - 1];
		}

		mint ans = dp[N - 1];
		ans += dp[N - 3];

		cout << ans << endl;
		return 0;
	}
	if (N % 2 != 0) { cout << 0 << endl; return 0; }

	vll ren(K + 1, 0);
	rep(i, K + 1) {
		if (S[i] != c) { ren[i] = 0; }
		else if (i == 0) { ren[i] = 1; }
		else { ren[i] = ren[i - 1] + 1; }
	}

	ll mn = INF;
	rep(i, K) {
		if (ren[i + 1] == 0) {
			if (ren[i] % 2 == 1) { mn = min(ren[i], mn); }
			if (ren[i] == i + 1) { mn = min(ren[i]+ 1, mn); }
			}
	}

	//cout << mn << endl;

	N /= 2;
	mn = (mn - 1) / 2;

	vmint dp(N + 1, 0), rdp(N + 1, 0);
	dp[0] = 1;
	rdp[0] = 1;

	repn(i, N) {
		if (i <= mn + 1)dp[i] = rdp[i - 1];
		else dp[i] = rdp[i - 1] - rdp[i - mn - 2];

		rdp[i] = rdp[i - 1] + dp[i];

		//cout << i << dp[i] << rdp[i] << endl;
	}

	mint ans = 0;
	if (mn >= N) { ans = pw(2, N); }
	else if (mn == N - 1) { ans = pw(2, N) - 1; }
	else {
		rep(i, mn + 1) {
			ans += rdp[N - i - 1] - rdp[N - mn - 2];
		}
	}
	ans *= 2;
	cout << ans << endl;
}

