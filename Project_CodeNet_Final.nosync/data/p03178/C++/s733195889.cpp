#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e10;
const long double PI = (acos(-1));

struct mint {
	int x;
	mint(int x = 0) :x((x% MOD + MOD) % MOD) {}
	mint operator-() const {
		return mint(-x);
	}
	mint& operator+=(const mint a) {
		if ((x += a.x) >= MOD)x -= MOD;
		return *this;
	}
	mint & operator-=(const mint a) {
		if ((x += MOD - a.x) >= MOD)x -= MOD;
		return *this;
	}
	mint & operator*=(const mint a) {
		(x *= a.x) %= MOD;
		return *this;
	}
	mint operator+(const mint a)const {
		return mint(*this) += a;
	}
	mint operator-(const mint a)const {
		return mint(*this) -= a;
	}
	mint operator*(const mint a)const {
		return mint(*this) *= a;
	}
	mint pow(int t)const {
		if (!t)return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1)a *= *this;
		return a;
	}

	//for prime mod
	mint inv() const {
		return pow(MOD - 2);
	}
	mint& operator/=(const mint a) {
		return (*this) *= a.inv();
	}
	mint operator/(const mint a)const {
		mint res(*this);
		return res /= a;
	}
};
ostream& operator<<(ostream & os, const mint & m) {
	os << m.x;
	return os;
}

mint dp[10005][105][2];
//dp[i][num][sml]
//sml = 0 : 制限あり sml = 1 : 制限なし

signed main() {
	string K;
	int D;
	cin >> K >> D;
	int len = K.size();
	dp[0][0][0] = 1;
	rep(i, len)rep(j, D)rep(k, 2) {
		rep(d, 10) {
			int ni = i + 1, nj = (j + d) % D, nk = k;
			int nd = K[i] - '0';
			if (k == 0) {
				if (d > nd)continue;
				if (d < nd)nk = 1;
			}
			dp[ni][nj][nk] += dp[i][j][k];
		}
	}
	mint ans = dp[len][0][0] + dp[len][0][1] - 1;
	cout << ans << endl;
}