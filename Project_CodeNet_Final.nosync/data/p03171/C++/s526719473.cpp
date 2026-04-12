#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[3001][3001];//dp[i,j] = optimul value of x in subarray i to j when p1 tries to maximize x while p2 tries to mini x;
int maxprofit(int ar[],int i, int j,int turn){
	if(i>j){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	if(turn==1)
		return dp[i][j]= max(ar[i]+maxprofit(ar,i+1,j,0), ar[j]+maxprofit(ar,i,j-1,0));
	else{
		return dp[i][j]=min(maxprofit(ar,i+1,j,1),maxprofit(ar,i,j-1,1));
	}
	
}

signed main(){
	int n;
	cin>>n;
	int ar[n];
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>ar[i];
		sum+=ar[i];
	}
//	cout<<sum<<endl;
	memset(dp,-1,sizeof dp);
	int optx = maxprofit(ar,0,n-1,1);
	int opty = sum - optx;
	cout<<optx-opty<<endl;
	return 0;
}