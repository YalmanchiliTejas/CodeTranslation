#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> ele;

int dp[3001][3001]; // we dont need a third dimension which specifies whose turn it is..
int solve(int i,int j,int turn){

	if(i>j) return 0;

	if(dp[i][j]!=-1) return dp[i][j];

	if(turn==1) return dp[i][j]=max(ele[i]+solve(i+1,j,0),ele[j]+solve(i,j-1,0));
	else return dp[i][j]=min(solve(i+1,j,1),solve(i,j-1,1));
}

int32_t main(){
  
    int n;
    cin>>n;

    ele.resize(n+1,0);
    int sum=0;
    for (int i = 1; i <=n; ++i) cin>>ele[i],sum+=ele[i];
    memset(dp,-1,sizeof dp);
	int x=solve(1,n,1);
	int y=sum-x;
	cout<<x-y;

}