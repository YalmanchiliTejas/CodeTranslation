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
int comb(int n, int k) {
	k = min(k, n - k);
	int x = 1, y = 1;
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

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, s;
	int ans = 0;
	int a[3005];
	cin >> n >> s;
	rep(i, n) {
		cin >> a[i];
	}
	int dp[3005][3005];
	rep(i, n + 1) {
		rep(j, s + 1) {
			dp[i][j] = 0;
		}
	}
	rep(i, n) {
		dp[i][0] = 1;
	}
	rep(i, n) {
		rep(j, s + 1) {
			dp[i + 1][j] += dp[i][j];
			dp[i + 1][j] %= 998244353;
		}
		for (int j = 0; j <= s - a[i]; j++) {
			if (j == s - a[i]) {
				ans += dp[i][j] * (n - i);
				ans %= 998244353;
			}
			else {
				dp[i + 1][j + a[i]] += dp[i][j];
				dp[i + 1][j + a[i]] %= 998244353;
			}
		}
	}
	/*rep(i, n + 1) {
		rep(j, s + 1) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << ans << endl;

	return 0;
}
