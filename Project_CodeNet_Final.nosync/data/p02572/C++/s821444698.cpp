#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define pi 3.1415926535897
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mod 1000000007
#define mod1 998244353
#define inf 1000000000000000000
#define inf1 100000000000000
#define endl '\n'
ll power(ll a,ll b,ll m){ll ans=1;while(b){if(b&1) ans=(ans*a)%m; b/=2;a=(a*a)%m;}return ans;}
ll arr[200005];
ll pre[200005];
int main()
{
	fastio;
	#ifdef gdb_18
		freopen("input.txt" , "rt" ,stdin);
		freopen("output.txt" , "wt" ,stdout);
	#endif
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>arr[i];
		pre[i]=(pre[i-1]+arr[i])%mod;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		ll cur=(pre[i-1]*arr[i])%mod;
		ans=(ans+cur)%mod;
	}	
	cout<<ans<<endl;
	return 0;	
}