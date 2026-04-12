#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define COUT cout<<fixed<<setprecision(12)
#define fast ios:: sync_with_stdio(false),cin.tie(0);
ll M=1000000007;
void solve()
{
	ll n;
	cin>>n;
	ll a[n+1];
	for(ll i=0;i<n;i++)
	cin>>a[i];
	//ll s[n+1];
	//s[n-1]=a[n-1];
	
	ll sum=0;
	
/*	for(ll i=n-2;i>=0;i--)
	{
	    s[i]=s[i+1]+a[i];
	}*/
	ll s=a[n-1];
	for(ll i=n-2;i>=0;i--)
	{
	    sum=((sum%M)+(s*a[i])%M)%M;
	    s=(s%M+a[i] %M)%M;
	}
	cout<<sum;
}

int main()
{
	ll t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	
	return 0;
}