#include <bits/stdc++.h>
using namespace std;

long long n, a[200000], sum[200000];

int main() {
	const long long mod = 1e9 + 7;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0) sum[0] = a[0];
		else sum[i] = sum[i - 1] + a[i];
	}
	long long ans = 0;
	for (int i = 0; i <= n - 2; i++) {
		ans = ((ans % mod) + (((a[i] % mod) * ((sum[n - 1] - sum[i]) % mod)) % mod)) % mod;
	}
	cout << ans;
	return 0;
}

















