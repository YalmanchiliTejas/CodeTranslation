#include<bits/stdc++.h>
#include<string.h>
#define ll long long 
#include<vector>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int mod=1e9+7;
ll dp[3002][3002][2];
	int n;
	ll v[3002];
ll solve(int i, int j, int turn){
	if(i>j)
	return 0;
	if(dp[i][j][turn]!=-1)
	return dp[i][j][turn];
	if(turn==0)
	return dp[i][j][turn]=max(v[i]+solve(i+1,j,1),v[j]+solve(i,j-1,1));
	else
	return dp[i][j][turn]=min(solve(i+1,j,0),solve(i,j-1,0));
}
int main(){
	IOS;
	cin>>n;
	ll sum=0;
	for(int i=0;i<n;i++)
	{
	cin>>v[i];
	sum+=v[i];}
	memset(dp,-1,sizeof(dp));
	//dp[i][j][0] = max(a[i]+dp[i+1][j][1],a[j]+dp[i][j-1][1])
	//dp[i][j][1] = min(dp[i+1][j][0],dp[i][j-1][0])
	cout<<2*solve(0,n-1,0)-sum;
}