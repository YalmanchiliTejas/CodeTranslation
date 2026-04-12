#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long n,a[200010],sum[200010]={0},ans=0;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i],sum[i]%=mod;
	for (int i=1;i<=n;i++) ans+=a[i]*sum[i-1],ans%=mod;
	cout<<ans<<endl;
	return 0;
}