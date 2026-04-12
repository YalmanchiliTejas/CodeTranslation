#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
	ll n;
	cin >> n;
	ll a[n],cf[n+1];
	memset(cf,0,sizeof(cf));
	for(ll i=0;i<n;i++)
	{
		cin >> a[i];
		cf[i+1]=cf[i]+a[i];
		// s=s+a[i];
	}
	ll ans=0,sum;
	for(ll i=0;i<n-1;i++)
	{
		sum=(cf[n]-cf[i+1])%mod;
		ans=ans+sum*a[i];
		ans=ans%mod;
	}
	cout << ans<<"\n";

}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}
