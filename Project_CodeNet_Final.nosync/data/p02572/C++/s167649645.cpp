#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
int n,tot,ans,a[200001];
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		ans=(ans+tot*a[i]%mod)%mod;
		tot=(tot+a[i])%mod;
	}
	cout<<ans;
	return 0;
} 