#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
using namespace std;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1LL << 60;
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl;
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)
#define INF INT_MAX/2

ll mod= 1000000007;
struct mint {
	ll x;
	mint(ll x = 0) :x(x%mod) {}
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod - a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a) {
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint a) const {
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint a) const {
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint a) const {
		mint res(*this);
		return res *= a;
	}
};
mint dp[1010][1010];
const int MAX = 10000;
const int MOD = mod;
ll fac[MAX], finv[MAX], inv[MAX];

void combinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}
ll comb(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	combinit();
	fac[0] = 1;
	rep(i, 1, 1010) {
		fac[i] = i * fac[i - 1];
		fac[i] %= mod;
	}

	dp[a - 1][n] = 1;
	for (int i = a; i <= b; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] += dp[i - 1][j];
			mint p = 1;
			for (int k = 1; k <= d && j + k * i <= n; k++) {
				mint tmp = comb(j + k * i, i);
				p *= tmp;
				p *= inv[k];
				if (k >= c)dp[i][j] += p*dp[i-1][j+k*i];
			}
		}
	}
	puts(dp[b][0].x)

	return 0;
}
