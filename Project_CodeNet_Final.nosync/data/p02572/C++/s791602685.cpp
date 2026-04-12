#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long

ll M=1000000007;
            
void solve()
{
	ll n;
	cin>>n;
	ll arr[n],sum=0;
	for (ll i = 0; i < n; i++) 
	{
		cin>>arr[i];
		sum = (sum + arr[i])%M ;
	}

	ll ans=0,cur=0;
	for (ll i = 0; i < n; i++)
	{
		sum = (sum - arr[i] + M) %M;
		ans = ( ans + (sum * arr[i])%M ) %M;
	}

	cout<<ans;
}

int main()
{
	IOS
	ll t=1;
	//cin>>t;
	for(ll i=0;i<t;i++) solve();
	return 0;
}
