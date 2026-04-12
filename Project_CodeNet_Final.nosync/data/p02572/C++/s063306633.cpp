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
#include<stack>
using namespace std;
#define int long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define dup(x,y) (((x)+(y)-1)/(y))
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e18;
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
	mint& operator-=(const mint a) {
		if ((x += MOD - a.x) >= MOD)x -= MOD;
		return *this;
	}
	mint& operator*=(const mint a) {
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
ostream& operator<<(ostream& os, const mint& m) {
	os << m.x;
	return os;
}

signed main() {
	int N;
	cin >> N;
	vector<mint>A(N);
	rep(i, N) {
		int a;
		cin >> a;
		A[i] = a;
	}
	mint sum = 0;
	rep(i, N)sum += A[i];
	mint ans = 0;
	rep(i, N) {
		sum -= A[i];
		ans += sum * A[i];
	}
	cout << ans;
}