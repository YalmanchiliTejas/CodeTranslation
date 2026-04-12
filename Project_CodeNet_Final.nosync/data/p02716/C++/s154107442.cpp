#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { 0, -1, 1, 0 };
const ll dy[4] = { -1, 0, 0, 1 };
const ll INF = 1e9 + 7;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
using Graph = vector<vector<int>>;
ll mypow(ll x, ll n, ll m) {
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 0) {
		return mypow(x*x%m, n / 2, m);
	}
	else {
		return x * mypow(x, n - 1, m) % m;
	}
}
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
const int MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];
//テーブルをつくる前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;//mod pにおける1,2,,,nの逆元
	for (int i = 2; i < MAX; ++i) {
		fac[i] = fac[i - 1] * i%INF;
		inv[i] = INF - inv[INF%i] * (INF / i) % INF;
		finv[i] = finv[i - 1] * inv[i] % INF;
	}
}

ll COM(int n, int k) {
	if (n < k)return 0;
	if (n < 0 || k < 0)return 0;
	return fac[n] * (finv[k] * finv[n - k] % INF) % INF;
}
///////////////////////////////////////

ll dp[200010][4];
//dp[i][j];i個目までみてj個余分なxを入れたときのmax
const ll mod =1e18;
int main() {
	int N; cin >> N;
	vector <ll> a(N);
	REP(i, N) {
		cin >> a[i];
	}
	REP(i, N + 1) {
		REP(j, 4) {
			dp[i][j] = -mod;
		}
	}
	int k = 1 + (N % 2);
	dp[0][0] = 0;
	REP(i, N) {
		REP(j,k+1) {
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
			ll now = dp[i][j];
			if ((i + j) % 2 == 0)now += a[i];
			dp[i + 1][j] = max(dp[i + 1][j], now);
		}
	}
	ll ans = -mod;
	if (N % 2 == 0) {
		REP(i, k + 1) {
			ans = max(ans, dp[N][i]);
		}
	}
	else {
		for (int i = 1; i < k + 1; ++i) {
			ans = max(ans, dp[N][i]);
		}
	}
	cout << ans << endl;
	return 0;
}
