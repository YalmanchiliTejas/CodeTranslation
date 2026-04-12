#include<bits/stdc++.h>
using namespace std;
#define pb  push_back
#define mod 1000000007
#define INF 1e18
typedef  long long ll;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	ll arr[n];
	ll pre[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	pre[0]=arr[0];
	for (int i = 1; i <n; ++i)
	{
		pre[i]=(pre[i-1]+arr[i])%mod;
		// cout<<pre[i]<<" ";
	}
	// cout<<endl;
	ll ans=0;
	for (int i = 1; i <= n-1; ++i)
	{
		ll temp=(pre[i]+mod-arr[i])%mod;
		ans=((temp*arr[i])+ans)%mod;
	}
	cout<<ans;
	return 0;
}