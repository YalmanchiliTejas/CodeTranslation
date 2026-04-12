#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dp[6000][6000];

#define MOD 998244353

inline int to_mod(long long n) {
	return n >= 0 ? n % MOD : MOD + n % MOD;
}

inline int madd(int a, int b) {
	return (a + b) % MOD;
}

inline int msub(int a, int b) {
	int t = a - b;
	return t >= 0 ? t : MOD + t;
}

inline int mmul(int a, int b) {
	return (int)((long long)a * b % MOD);
}

inline int mpow(int a, int b) {
	int r = 1;
	for(; b != 0; b >>= 1) {
		if (b & 1) r = mmul(r, a);
		a = mmul(a, a);
	}
	return r;
}

inline int minv(int a) {
	return mpow(a, MOD - 2);
}

inline int mdiv(int a, int b) {
	return mmul(a, minv(b));
}

int n, s, a[3000];

void show() {
	rep(i, n) {
		rep(j, s) {
			printf("%d ", dp[i][j]);
		}
		puts("");
	}
}

int main() {
	cin >> n >> s;
	rep(i, n) cin >> a[i];
	int res = 0;
	rep(i, n) {
		int t = a[i];
		if (t == s) {
			res = madd(res, to_mod((i + 1) * (n - i)));
		} else if (t < s) {
			dp[i][t] = madd(dp[i][t], i + 1);
		}
		if (i == 0) continue;
		rep(j, s) {
			dp[i][j] = madd(dp[i][j], dp[i-1][j]);
			if (j + t == s) {
				res = madd(res,  mmul(to_mod(dp[i-1][j]), to_mod(n - i)));
			} else if (j + t < s) {
				dp[i][j+t] = madd(dp[i][j+t], dp[i-1][j]);
			}
		}
	}
	cout << res << endl;
}


