#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
const long long MOD = (long long)1e9 + 7;

long long n, m, k;

long long quickpow(long long b, int e)
{
	return e ? ((e & 1 ? b : 1)*quickpow((b*b) % MOD, e >> 1)) % MOD : 1;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		ans += i * 1LL * (n - i);
		ans = ans % MOD;
	}
	ans = ans * m;
	ans = ans % MOD;
	ans = ans * m;
	ans = ans % MOD;
	long long tmp = ans;
	ans = 0;
	for (int i = 1; i < m; i++) {
		ans += i * 1LL * (m - i);
		ans = ans % MOD;
	}
	ans = ans * n;
	ans = ans % MOD;
	ans = ans * n;
	ans = ans % MOD;
	ans = ans + tmp;
	ans = ans % MOD;
	for (int i = 1; i <= k - 2; i++) {
		ans = ans * (n*m - 1 - i);
		ans = ans % MOD;
		ans = ans * quickpow(i, MOD - 2);
		ans = ans % MOD;
	}
	cout << ans << "\n";
	//system("pause");
	return 0;
}