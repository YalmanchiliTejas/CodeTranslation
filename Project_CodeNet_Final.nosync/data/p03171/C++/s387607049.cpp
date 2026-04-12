#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[3001][3001][2];
ll solve(vector<ll>&v,int i,int j,bool turn){
	if(i>j){
		return 0;
	}

	if(dp[i][j][turn]!=-1){
		return dp[i][j][turn];
	}

	if(turn==1){
		return dp[i][j][turn] = max(v[i] + solve(v,i+1,j,0),v[j] + solve(v,i,j-1,0));
	}else{

		return dp[i][j][turn] = min(solve(v,i+1,j,1),solve(v,i,j-1,1));
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	memset(dp,-1,sizeof dp);
	ll n;
	cin>>n;
	vector<ll>v(n+1);
	ll sum = 0;
	for(int i = 1; i <= n ; i++){
		cin>>v[i];
		sum += v[i];
	}
	ll scoreX = solve(v,1,n,1);
	ll scoreY = sum - scoreX;
	cout<<scoreX - scoreY<<endl;
	// for(int i = 1; i <= n ; i++){
	// 	cout<<v[i]<<" ";	
	// }
	return 0;
}