#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 1e5 + 100;
const long long MOD = 1e9 + 7;
int n;
long long a[N], sum1, sum2;

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++ ) {
		scanf ("%lld", &a[i]);
		sum1 += a[i];
	}
	for (int i = 1; i <= n; i ++ ) {
		sum1 -= a[i];
		sum2 = sum2 + ((sum1 % MOD) * (a[i] % MOD)) % MOD;
		sum2 %= MOD;
	}
	printf ("%lld\n", sum2);
	return 0;
}