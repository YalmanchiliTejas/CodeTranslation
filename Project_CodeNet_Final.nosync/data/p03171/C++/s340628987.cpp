#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


const int maxn = 3000;
int dp[2][maxn][maxn],a[maxn];
int n,sum=0;

int solve(int I,int l,int r)
{
	if( l > r )return 0;
	if( dp[I][l][r] != -1 )return dp[I][l][r];
	if( I&1 )dp[I][l][r]=min( - a[l] + solve(I^1,l+1,r) , - a[r] + solve(I^1,l,r-1) );
	else dp[I][l][r]=max( a[l] + solve(I^1,l+1,r) , a[r] + solve(I^1,l,r-1) );
	return dp[I][l][r];
	
}
int32_t main()
{
	IOS
	memset(dp,-1,sizeof(dp));
	
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i],sum+=a[i];
	
	cout << solve(0,0,n-1) << endl;
	
	
	
	
}
