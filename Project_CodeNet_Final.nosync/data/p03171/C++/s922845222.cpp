#include<bits/stdc++.h>
using namespace std;
int n,arr[3001];
long long int dp[3001][3001][2];
long long int solve(int a,int b,int turn){
	if(a>b){
		return 0;
	}
	if(dp[a][b][turn]==-1){
		if(turn == 1){
			dp[a][b][turn]=max(solve(a+1,b,0)+arr[a],solve(a,b-1,0)+arr[b]);
		}
		else{
			dp[a][b][turn]=min(solve(a+1,b,1)-arr[a],solve(a,b-1,1)-arr[b]);
		}
	}
	return dp[a][b][turn];
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<3001;i++){
		for(int j=0;j<3001;j++){
			dp[i][j][0]=-1;
			dp[i][j][1]=-1;
		}
	}
	cout<<solve(0,n-1,1);
	return 0;
}