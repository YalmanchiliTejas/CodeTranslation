#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll n, m;
ll a[3001];
ll dp[3001];
const ll mod = 998244353;
int main()
{
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	ll dap = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > m)continue;
		if (a[i] == m) {
			dap += i * (n - i + 1);
			dap %= mod;
		}
		else {
			dap += (dp[m - a[i]] * (n - i + 1));
			dap %= mod;
		}
		for (int y = m; y >= a[i]; y--) {
			dp[y] += dp[y - a[i]];
			dp[y] %= mod;
		}
		dp[a[i]] += i;
		dp[a[i]] %= mod;
	}
	printf("%lld\n", dap);
}