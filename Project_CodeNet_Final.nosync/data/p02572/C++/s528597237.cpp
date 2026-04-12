#include<bits/stdc++.h>
using namespace std;
long long ans;
long long sum1[200005];
long long a[200005];
long long mod=1e9+7;
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum1[i]=(sum1[i-1]+a[i])%mod;
	}
	for(int i=1;i<n;i++)
	{
		ans=(ans+a[i]*((sum1[n]-sum1[i])%mod))%mod;
	}
	cout<<(ans+mod)%mod;
}