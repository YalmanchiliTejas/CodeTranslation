#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 3005
int dp[MAXN][MAXN];
int a[MAXN];
int n;

int dfs(int l, int r){
	if(dp[l][r]!=-1) return dp[l][r];
	if(l>r) return 0;
	int lev = (n-1-l)+r;
	lev%=2;
	if(lev==0){
		return dp[l][r] = max(dfs(l+1,r)+a[l], dfs(l,r-1)+a[r]);
	}
	else{
		return dp[l][r] = min(dfs(l+1,r)-a[l], dfs(l,r-1)-a[r]);
	}
}

int32_t main(){
	cin>>n;
	for(int i=0; i<n; i++) cin>>a[i];
	memset(dp,-1,sizeof(dp));
	cout<<dfs(0,n-1);
}