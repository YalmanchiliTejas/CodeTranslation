#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define li long
#define pb push_back
#define mem(arr,x) memset(arr,x,sizeof(arr))
ll n,a[3001];
ll dp[3001][3001];
ll maxDiff(ll start,ll end)
{
	if(start>end)
		return 0;

	if(dp[start][end]!=-1)
		return dp[start][end];

	ll ans1=a[start]-maxDiff(start+1,end);
	ll ans2=a[end]-maxDiff(start,end-1);
	return dp[start][end]=max(ans1,ans2);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(ll i=0;i<n;i++)
    cin>>a[i];
	mem(dp,-1);
	cout<<maxDiff(0,n-1);
    return 0;
}