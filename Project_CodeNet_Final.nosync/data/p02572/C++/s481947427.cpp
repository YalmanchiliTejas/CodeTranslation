#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
const long long mod=1e9+7;
long long a[maxn],sum[maxn];
int main()
{	
	int n;
	long long ans=0;
	cin>>n;
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++)cin>>a[i];
	sum[n]=a[n];
	for(int i=n-1;i>0;i--)sum[i]+=sum[i+1]+a[i];
	for(int i=n-1;i>0;i--)sum[i]=sum[i]%mod;
	for(int i=1;i<n;i++)ans=(ans+a[i]*sum[i+1]%mod)%mod;
	cout<<ans<<endl;
return 0;
}
