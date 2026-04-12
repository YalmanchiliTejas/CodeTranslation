#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long 
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back 
#define mp make_pair
#define inf 2000000009
#define mod 1000000007
using namespace std;

ll n;
ll a[3000];
ll dp[3000][3000];

ll fun( ll start, ll end)
{
	if(start>end)
		return 0;
	else if(dp[start][end]!=-1)
		return dp[start][end];
	else
	return dp[start][end]=max(a[start]-fun(start+1,end),a[end]-fun(start,end-1));
}
int main()
{ 
fast;
	
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>a[i];

	memset(dp,-1,sizeof(dp));
	cout<<fun(0,n-1);
}
