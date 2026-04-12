#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
unsigned long long int m=1e9+7;
int main()
{
	ll n,arr[200001];
	cin>>n;
	unsigned long long int sum=0;
	for(ll i=1;i<=n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		sum-=arr[i];
		ans=(ans+((sum)%m*arr[i])%m)%m;
	}
	cout<<ans<<endl;
	return 0;
}