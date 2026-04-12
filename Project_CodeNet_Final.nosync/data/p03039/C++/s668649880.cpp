/* 
	بسم الله الرحمن الرحیم
	
	(; طلا یک جهانی
*/	

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int pw(int b, int p) {
	int res = 1;
	for (; p; p >>= 1, b = 1LL * b * b % MOD)
		if (p & 1)
			res = 1LL * res * b % MOD;
	return res;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	int a = 0, b = 0;
	for (int i = 1; i < m; i++)
		a = (a + 1LL * i * (m - i)) % MOD;
	for (int i = 1; i < n; i++)
		b = (b + 1LL * i * (n - i)) % MOD;
	a = 1LL * a * n % MOD * n % MOD;
	b = 1LL * b * m % MOD * m % MOD;
	if (1LL * n * m - 2 >= MOD)
		return cout << 0, 0;
	int ans = 1, fac = 1;;
	for (int i = 1; i <= n * m - 2; i++) {
		fac = (1LL * i * fac) % MOD;
		if (i == k - 2)
			ans = 1LL * ans * pw(fac, MOD - 2) % MOD;
		if (i == n * m - k)
			ans = 1LL * ans * pw(fac, MOD - 2) % MOD;
	}
	ans = 1LL * ans * fac % MOD;
	ans = 1LL * ans * (a + b) % MOD;
	cout << ans;
}
