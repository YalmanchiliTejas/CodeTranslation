#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long int ll;
ll power(ll x,ll n)
{
	if(x==0) return 1;
	ll a=x,b=1;
	while(n)
	{
		if(n&1) b=((b%mod)*(a%mod))%mod;
		a=((a%mod)*(a%mod))%mod;
		n=n/2;
	}
	return b%mod;
}
ll inv(ll a,ll b){
	return (a*power(b,mod-2)%mod)%mod;
}
int main()
{

	// freopen("testcase1.txt","r",stdin);
	// freopen("output1.txt","w",stdout);

	ll s1=0,s2=0,i,n,t;
	// cin>>t;
	t=1;
	while(t--)
	{	
		s1=s2=0;
		cin>>n;
		ll a[n+2];
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
			s1=(s1%mod+a[i]%mod)%mod;
		// cout<<s1<<endl;
		for(i=0;i<n;i++)
			s2=(s2+((a[i]%mod)*((s1-a[i])%mod))%mod+mod)%mod;
		cout<<inv(s2,2)%mod<<endl;}
}