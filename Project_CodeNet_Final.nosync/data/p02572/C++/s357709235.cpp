#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;

int n;
int a[200005],pre[200005];

signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++)  cin>>a[i];
	for (int i=1;i<=n;i++)  pre[i]=(pre[i-1]+a[i])%mod;
	
	int ans=0;
	for (int i=1;i<=n;i++)  ans=(ans+a[i]*pre[i-1]%mod)%mod;
	cout<<ans<<endl;
	
	return 0;
}
