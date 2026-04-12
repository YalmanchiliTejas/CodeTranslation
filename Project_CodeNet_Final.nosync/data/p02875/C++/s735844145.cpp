// C - Neither AB nor BA
#include <bits/stdc++.h>

using namespace std;

#define	MOD	998244353

vector<long long> fact, finv;

void init_fact(int n = 1000000)
{
	fact.resize(n); finv.resize(n);
	fact[0] = finv[n - 1] = 1;
	for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i % MOD;
	for (long long x = MOD - 2, a = fact[n - 1]; x > 0; a = a * a % MOD, x >>= 1)
		if (x & 1) finv[n - 1] = finv[n - 1] * a % MOD;
	for (int i = n - 2; i >= 0; i--) finv[i] = finv[i + 1] * (i + 1) % MOD;
}

long long cnr(int n, int r)
{
	if (r < 0 || r > n) return 0;
	if (r == 0 || r == n) return 1;
	return fact[n] * finv[r] % MOD * finv[n - r] % MOD;
}

int main(int argc, char *argv[])
{
	long long n;
	cin >> n;

	init_fact(n + 1);

	long long ans = 1;
	for (int i = 0; i < n; i++) ans = ans * 3 % MOD;

	vector<long long> p2(n + 1, 1);
	for (int i = 0; i < n; i++) p2[i + 1] = (p2[i] * 2) % MOD;
	for (long long i = n / 2 + 1; i <= n; i++)
		ans = (ans - cnr(n, i) * p2[n - i] * 2 % MOD + MOD) % MOD;

	cout << ans << endl;

	return 0;
}
