#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 10;
const int mod = 998244353;
typedef long long ll;
#define lowbit(i) (i & (-i))
ll sum[maxn];
int n,m,k,a[maxn],s,dp[maxn];
int main() {
	scanf("%d%d",&n,&s);
	for (int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (s > a[i]) ans = (ans + 1ll * dp[s - a[i]] * (n - i + 1)) % mod;
		else if (s == a[i]) ans = (ans + 1ll * i * (n - i + 1)) % mod;
		for (int j = s; j >= a[i]; j--)
			dp[j] = (dp[j] + dp[j - a[i]]) % mod;
		dp[a[i]] = (dp[a[i]] + i) % mod;
	}
	printf("%d\n",ans);
}