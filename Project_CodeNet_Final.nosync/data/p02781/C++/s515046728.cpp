#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,s,f) for(int i=s;i<f;i++)
#define INF 1000000000000000000
#define MOD 1000000007
typedef pair<int, int> P;

bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)return false;
	}
	return n != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}
int mod_pow(int n, int p, int m) {
	if (p == 0) return 1;
	if (p % 2 == 0) {
		int t = mod_pow(n, p / 2, m);
		return (t * t) % m;
	}
	return n * mod_pow(n, p - 1, m) % m;
}
int extGCD(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long d = extGCD(b, a % b, y, x);
	y -= a / b * x;
	return d;
}
int modinv(int a, int m) {
	int b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
int digit(int x) {
	int cnt = 0;
	while (x > 0) {
		cnt += x % 10;
		x /= 10;
	}
	return cnt;
}
int read() {
	int tmp;
	cin >> tmp;
	return tmp;
}
int xor128() {
	static int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	int t = (x xor (x << 11));
	x = y; y = z; z = w;
	return (w = (w xor (w >> 19)) xor (t xor (t >> 8)));
}
map<int, int> factaring(int x) {
	map<int, int>ans;
	int now = 2;
	while (now * now <= x) {
		if (x % now == 0) {
			x /= now;
			ans[now]++;
		}
		else now++;
	}
	if (x != 1) ans[x]++;
	return ans;
}

const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int Com(int n, int k) {
	int x=1, y=1;
	rep(i, k) {
		y *= i + 1;
		y %= MOD;
	}
	for (int i = n - k + 1; i <= n; i++) {
		x *= i;
		x %= MOD;
	}
	return x * modinv(y, MOD) % MOD;
}

int dp[150][3][150];

signed main() {
	string n;
	int K;
	cin >> n >> K;
	dp[0][0][0] = 1;
	for (int i = 0; i < n.size(); i++) {
		int D = n[i] - '0';
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k <= n.size(); k++) {
				for (int d = 0; d <= (j ? 9 : D); d++) {
					dp[i + 1][j || (d < D)][d ? k + 1 : k] += dp[i][j][k];
				}
			}
		}
	}
	cout << dp[n.size()][1][K] + dp[n.size()][0][K] << endl;

	return 0;
}