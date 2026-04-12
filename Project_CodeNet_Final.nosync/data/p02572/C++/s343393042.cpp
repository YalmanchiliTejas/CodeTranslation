#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5+100;
const ll MOD = 1e9+7;
ll n;
ll a[N];
ll sum[N];
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i] = sum[i-1]+a[i];
	}
	ll tot = sum[n];
	ll ans = 0;
	for(int i=1;i<=n;i++)
	{
		ans = (ans + (a[i]*((tot - sum[i])%MOD))%MOD)%MOD;
	}
	cout << ans << endl;
	return 0;
}