#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int NMAX = 2e5 + 10;
const int MOD = 1e9 + 7;
ll a[NMAX],sum[NMAX];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for(register int i = 1;i <= n;i++)
		scanf("%d",a+i);
	sum[n+1] = 0;
	for(register int i = n;i >= 1;--i)
		sum[i] = (sum[i+1] + a[i])%MOD;

	ll ans = 0;
	for(register int i = 1;i < n;i++)
		ans = (ans + a[i] * sum[i+1] % MOD)%MOD;
	printf("%lld\n",ans);
	return 0;
}