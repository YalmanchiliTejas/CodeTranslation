#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<algorithm>
#include<cmath>
#include<numeric>
using namespace std;

typedef long long LL;
const int MOD = 1e9+7;

LL dfs(int x,int y,vector<vector<LL>> &dp,vector<LL> &sif){
	if(x>y) return 0ll;
	if(dp[x][y]!=-1) return dp[x][y];
	dp[x][y] = max(sif[y+1]-sif[x]-dfs(x+1,y,dp,sif),sif[y+1]-sif[x]-dfs(x,y-1,dp,sif));
	return dp[x][y];
}
void solve(){
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++) cin>>nums[i];
	vector<LL> sif(n+1,0);
	for(int i=0;i<n;i++){
		sif[i+1]=sif[i]+nums[i];
	}
	vector<vector<LL>> dp(n,vector<LL>(n,-1ll));
	// for(int i=0;i<n;i++){
	// 	dp[i][i] = nums[i];
	// }
	// // for(int len=2;len<=n;len++){
	// // 	for(int i=0;i<(n-len+1);i++){
	// // 		int j = i+len-1;
	// // 		dp[i][j] = max(sif[j+1]-sif[i]-dp[i+1][j],sif[j+1]-sif[i]-dp[i][j-1]);
	// // 	}
	// // }
	cout<<2ll * dfs(0,n-1,dp,sif)-sif[n]<<endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T = 1;
	// cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
