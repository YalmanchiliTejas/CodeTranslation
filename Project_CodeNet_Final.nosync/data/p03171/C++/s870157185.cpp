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
#define inf1 1000000000
#define endl '\n'
ll arr[3005];
ll dp[3005][3005];
int main()
{
	fastio;
	#ifdef APNA_IO
		freopen("input.txt" , "rt" ,stdin);
		freopen("output.txt" , "wt" ,stdout);
	#endif
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	ll k=1;
	if (n%2==0)
		k=-1;
	for(ll i=0;i<n;i++)
		dp[i][i]=k*arr[i];
	for(ll i=1;i<n;i++)
	{
		for(ll j=0;j<n-i;j++)
		{
			if(k==-1)
			{
				if(i%2==1)
					dp[j][j+i]=max(dp[j+1][j+i]+arr[j],dp[j][j+i-1]+arr[j+i]);
				else
					dp[j][j+i]=min(dp[j+1][j+i]-arr[j],dp[j][j+i-1]-arr[j+i]);
			}
			else if(k==1)
			{
				if(i%2==0)
					dp[j][j+i]=max(dp[j+1][j+i]+arr[j],dp[j][j+i-1]+arr[j+i]);
				else
					dp[j][j+i]=min(dp[j+1][j+i]-arr[j],dp[j][j+i-1]-arr[j+i]);
			}
		}
	}
	cout<<dp[0][n-1]<<endl;
	return 0;
}