#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7; 
long long ans=0,n,a[210000],sum[210000]={0};
int main()
{
	 cin>>n;
	 for(long long i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	 	sum[i]=(sum[i-1]+a[i])%mod;
	 }
	for(long long i=1;i<n;i++)
	{
	 	ans=(ans+((a[i]%mod)*(sum[n]-sum[i]+mod)%mod)%mod)%mod;
	}
	cout<<ans;
 } 