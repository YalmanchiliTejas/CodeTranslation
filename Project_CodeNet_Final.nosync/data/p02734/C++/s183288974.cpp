#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 998244353
#define INF 1e9+5
typedef long long ll;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define forn(i,a,b) for(ll i=a;i<(ll)b;i++)
#define ff first
#define ss second
#define int long long
int32_t main()
{
	IOS;
	int n,s;
	cin>>n>>s;
	int arr[n+1];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	int dp[n+1][s+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=s;j++)
			dp[i][j]=0;
	for(int i=1;i<=n;i++)
		if(arr[i]<=s)
			dp[i][arr[i]]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=s;j++)
		{
			if(j>=arr[i])
				dp[i][j]=(0LL+dp[i][j]+dp[i-1][j-arr[i]])%mod;
			if(i>1)
				dp[i][j]=(0LL+dp[i][j]+dp[i-1][j])%mod;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=(0LL + ans + dp[i][s])%mod;
	cout<<ans<<"\n";
	return 0;
}