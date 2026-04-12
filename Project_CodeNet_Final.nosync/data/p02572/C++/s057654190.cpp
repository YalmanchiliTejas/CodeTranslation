#include<bits/stdc++.h>
using namespace std;

// --------------------------------------------------------------------------------
#define FASTIO	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long 
#define mset(arr,val) memset(arr,val,sizeof(arr))
#define frepi(a,b) for(int i=a;i<=b;++i)
#define int long long
// --------------------------------------------------------------------------------

const int mod = 1e9+7;
void test_case(int tc)
{
	int n;cin>>n;
	ll arr[n+1];
	mset(arr,0);
	ll ans = 0;
	frepi(1,n)
	{
		cin>>arr[i];
		arr[i]=(arr[i]+arr[i-1]);
	}
	for(int i=1;i<n;++i){
		ll a = arr[i]-arr[i-1];
		ans+=(a*((arr[n]-arr[i]+mod)%mod))%mod;
		ans=ans%mod;
	}
	cout<<ans%mod;
}

int32_t main()
{
	FASTIO;
	#ifndef ONLINE_JUDGE
		freopen("/home/suryakant/input.txt","r",stdin);
		freopen("/home/suryakant/output.txt","w",stdout);
	#endif
	
    int tc=1;
    //cin>>tc;
    for(int i=1;i<=tc;++i)test_case(tc);
}