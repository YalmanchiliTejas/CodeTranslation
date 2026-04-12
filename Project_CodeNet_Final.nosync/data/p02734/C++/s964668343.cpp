#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll dp[3010] = {0}, ans = 0;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		for (int j = m; j >= x; j--) {
			if (j == m) {
				if (m == x)ans = (ans + 1ll*i*(n-i+1)%mod) % mod;
				else if (m-x > 0) ans = (ans + 1ll*dp[m-x]*(n-i+1)%mod)%mod;
				
			}
			else if (j == x) {
				dp[j] = (dp[j] + i)%mod;
			}
			else dp[j] = (dp[j] + dp[j-x])%mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}