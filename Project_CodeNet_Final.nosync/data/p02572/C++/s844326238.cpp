#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ll i,j,t=1;
	//cin>>t;
	for(i=0;i<t;i++)
	{
		ll n,s=0,ans=0;
		cin>>n;
		ll a[n+5];
		for(j=0;j<n;j++)
		{
			cin>>a[j];
			s+=a[j];
		}
		
		ll m=1000000007;
		for(j=0;j<n;j++)
		{
			s-=a[j];
			ans=(ans+((a[j]%m)*(s%m))%m)%m;
		}
		cout<<ans;
	}
}