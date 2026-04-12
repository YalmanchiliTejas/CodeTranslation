// E - Cell Distance
#include <bits/stdc++.h>

using namespace std;

#define	MOD	1000000007

int main(int argc, char *argv[])
{
	long long n, m, k;
	cin >> n >> m >> k;

	long long r = 0, t = 1;
	for (long long i = 0; i < n; i++) r = (r + (1 + i) * i / 2 * m % MOD * m % MOD) % MOD;
	for (long long i = 0; i < m; i++) r = (r + (1 + i) * i / 2 * n % MOD * n % MOD) % MOD;
	for (long long i = 2; i <= n * m - 2; i++) r = r * i % MOD;
	for (long long i = 2; i <= k - 2; i++) t = t * i % MOD;
	for (long long i = 2; i <= (n * m - k); i++) t = t * i % MOD;
	for (long long x = MOD - 2; x > 0; t = t * t % MOD, x >>= 1)
		if (x & 1) r = r * t % MOD;
	cout << r << endl;

	return 0;
}
