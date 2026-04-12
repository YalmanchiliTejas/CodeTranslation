#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int MXN=3000;
int a[MXN+1];
int dp[MXN+1][MXN+1][2];
bool vis[MXN+1][MXN+1][2];
int n,k;
int solve(int l,int r,int k){
	if( l==r )return dp[l][r][k]=(k ? -1*a[l] : a[l]);
	if( vis[l][r][k] )return dp[l][r][k];
	vis[l][r][k]=1;
	if(k==0){
		dp[l][r][k]=max(a[r]+solve(l,r-1,k^1),a[l]+solve(l+1,r,k^1));
	}
	else {
		dp[l][r][k]=min(-a[r]+solve(l,r-1,k^1),-a[l]+solve(l+1,r,k^1));
	}
	return dp[l][r][k];
}

int32_t main()
{
   IOS
   memset(dp,0,sizeof(dp));
   memset(vis,false,sizeof(vis));
   cin >> n ;
   for(int i=1;i<=n;i++)
   cin>>a[i];
   cout << ( solve(1,n,0) ) << endl;
}
