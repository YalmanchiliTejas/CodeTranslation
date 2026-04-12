#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define inf 1000000000
#define md 1000000007
#define pb push_back
#define li 3005
#define int long long
using namespace std;
int n,A[li],dp[li][li][3];
int dfs(int l,int r,int t){
	if(l>r){
		return 0;
	}
	if(~dp[l][r][t]) return dp[l][r][t];
	if(t==1){
		dp[l][r][t]=max(dfs(l+1,r,1-t)+A[l],dfs(l,r-1,1-t)+A[r]);
	}
	if(t==0){
		dp[l][r][t]=min(dfs(l+1,r,1-t)-A[l],dfs(l,r-1,1-t)-A[r]);
	}
	return dp[l][r][t];
}
main(){
	memset(dp,-1,sizeof(dp));
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&A[i]);
	int ty=dfs(1,n,1);
	printf("%lld\n",ty);
	return 0;
}


