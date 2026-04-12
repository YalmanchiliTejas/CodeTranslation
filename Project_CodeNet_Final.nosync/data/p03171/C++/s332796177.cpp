#include<bits/stdc++.h> 
using namespace std;

#define int long long

int solve(vector<int>& coins, int l, int r,vector<vector<int>> &dp){
	if (l>r) return 0;
	if (dp[l][r]!=-1) return dp[l][r];
	return dp[l][r]= max(coins[l]+min(solve(coins,l+2,r,dp),solve(coins,l+1,r-1,dp)),
		   	   coins[r]+min(solve(coins,l+1,r-1,dp),solve(coins,l,r-2,dp)));
}

signed main() {
	// freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
	int N;
	cin>>N;
	int sum=0;
	vector<int> coins(N);
	for (int i=0;i<N;i++){
		cin>>coins[i];
		sum+=coins[i];
	}
	vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
	int X = solve(coins,0,N-1,dp);
	int Y = sum-X;
	cout<<X-Y<<endl;
    return 0; 
}
