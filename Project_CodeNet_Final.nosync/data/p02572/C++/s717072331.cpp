#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
long long ans,n,s,a[200005];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=n-1;i>=1;i--)
	{
		s=(s+a[i+1])%mod;
		ans=(a[i]*s+ans)%mod;
	}
	cout<<ans<<endl;
	return 0;
}