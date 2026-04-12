#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
	ll n;
	cin>>n;
	ll a[n];
	ll sum=0;
	ll pre[n]={0};
	for(ll p=0;p<n;p++)
	{
		cin>>a[p];
		sum=(sum%mod+a[p]%mod)%mod;
		if(p==0)
			pre[p]=a[p]%mod;
		else
			pre[p]=(pre[p-1]%mod+a[p]%mod)%mod;
	}
	ll ans=0;
	for(ll p=0;p<n-1;p++)
	{
		ll ter=((sum-pre[p]+mod)%mod*a[p]%mod)%mod;
		ans=(ans%mod+ter%mod)%mod;
		//cout<<"ans= "<<ans<<endl;

	}
	cout<<ans;

}