#include <bits/stdc++.h>
#define LL long long
#define PII pair<int, int>
#define f first
#define s second 
using namespace std;
const LL MOD = (LL) 998244353;
const int MAXN = 3005;

int n, tgt, a[MAXN];
LL dp[MAXN][MAXN], sum[MAXN];

int main() { 
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> tgt;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = a[i]; j <= tgt; j++) {
			dp[i][j] = sum[j - a[i]];
		}
		dp[i][a[i]] = (dp[i][a[i]] + i) % MOD;
		for (int j = a[i]; j <= tgt; j++) {
			sum[j] = (sum[j] + dp[i][j]) % MOD;
		}
	}
	
	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + dp[i][tgt] * (n - i + 1)) % MOD;
	}
	
	cout << ans << '\n';

	return 0;
}