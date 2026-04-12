#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<int>& dq,int st, int end, vector<vector<ll>>& dp){
	if(st > end)
		return 0;
	if(dp[st][end] != -1)
		return dp[st][end];

	//dp[st][end] = max(max(solve(dq, st+1, end-1, dp), solve(dq, st+2, end, dp)) + dq[st], max(solve(dq, st+1, end-1, dp), solve(dq, st, end-2, dp)) + dq[end]);
	dp[st][end] = max(dq[st] - solve(dq, st+1, end, dp), dq[end] - solve(dq, st, end-1, dp));
	
	return dp[st][end];
}

int main(){
	int n;cin>>n;
	vector<int> dq;
	for(int i = 0; i < n; i++){
		int t;cin>>t;
		dq.push_back(t);
	}
	vector<vector<ll> > dp(n, vector<ll>(n,-1));
	dp[0][n-1] = solve(dq, 0, n-1, dp);
	
	cout<<dp[0][n-1]<<endl;
	return 0;
}