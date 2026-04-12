#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
typedef long long ll;
int main()
{
	int n;
	cin>>n;
	ll a[n];
	ll sum[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sum[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--)
	{
		sum[i]=sum[i+1]%MOD+a[i]%MOD;
		sum[i]%=MOD;
	}
	ll ans=0;
	for(int i=0;i<n-1;i++)
	{
		ans+=(a[i]*sum[i+1])%MOD;
		ans%=MOD;
	}
	cout<<ans%MOD;
	return 0;
}