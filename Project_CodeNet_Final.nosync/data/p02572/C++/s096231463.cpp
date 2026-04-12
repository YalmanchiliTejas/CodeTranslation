#include<bits/stdc++.h>
#define ll long long int
const int MOD=1000000007;
using namespace std;
int main()
{
	int n;cin>>n;
	vector<ll> a(n);
	vector<ll> suff(n+1);
	suff[n]=0;
	ll ans=0;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=n-1;i>=0;i--)
	{
		suff[i]=(a[i]+suff[i+1])%MOD;
	}
	for(int i=0;i<n-1;i++)
	{
		ans+=(a[i]*suff[i+1])%MOD;
	}
	cout<<ans%MOD<<"\n";
	
	return 0;
	
}