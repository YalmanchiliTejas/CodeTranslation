#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back
#define in(x) int x; cin>>x;
#define ln(x) long long x; cin>>x;
#define memf(a) memset(a,false,sizeof(a))
#define F first
#define S second
#define endl "\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
int main()
{
	fast
	int n;
	cin>>n;
	ll a[n],pre=0;
	ll M=1e9+7;
	for(int i=0;i<n;i++) {cin>>a[i];pre+=a[i];}
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		pre-=a[i];
		ll x=((pre%M)*a[i])%M;
		sum+=(x);
		sum%=M;
	}
	cout<<sum;
	return 0;
}