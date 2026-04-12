#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10, MOD = 1e9 + 7;
int n, i, a[N];
LL ans, q[N];
int main() {
	cin >> n;
	for (i = 1; i <= n; i++) cin >> a[i];
	for (i = n; i >= 1; i--) q[i] = (q[i + 1] + a[i]) % MOD;
	for (i = 1; i < n; i++) ans = (ans + (a[i] * q[i + 1]) % MOD) % MOD;
	cout << ans << '\n';
	return 0;
}