//author : 'Amit Singh Sansoya @amit3200'
//it was all meant to happen as i was all talk!
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
lld n;
vector<lld> arr;
vector<vector<lld>> dp;
lld ans=LONG_LONG_MIN;
lld dfs(lld i,lld j){
	if(i>=n || j<0)
		return 0;
	if(dp[i][j]!=LONG_LONG_MIN){
		return dp[i][j];
	}
	if(i==j){
		dp[i][j]=arr[i];
		return arr[i];
	}
	dp[i][j]=max(arr[i]-dfs(i+1,j),arr[j]-dfs(i,j-1));
	return dp[i][j];
}

int main(){
	cin>>n;
	dp.resize(n+1,vector<lld>(n+1,ans));
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		arr.push_back(data);
	}
	ans=dfs(0,n-1);
	cout<<ans<<"\n";
}