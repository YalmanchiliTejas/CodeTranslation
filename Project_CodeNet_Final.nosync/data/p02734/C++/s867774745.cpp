#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
int n, s;
int a[3010]; 
ll dp[3010][3010], ans;
const ll mod = 998244353;
int main() {
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= s; j++)dp[i][j] = dp[i - 1][j];
		dp[i][a[i]] = (dp[i][a[i]] + i) % mod;
		for (int j = 0; j + a[i] <= s; j++)
			dp[i][j + a[i]] = (dp[i][j + a[i]] + dp[i - 1][j]) % mod;
		ans = (ans + dp[i][s]) % mod;
	}
	cout << ans << endl;
	return 0;
}