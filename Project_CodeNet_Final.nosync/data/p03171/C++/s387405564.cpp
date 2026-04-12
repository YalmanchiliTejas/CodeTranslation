#include<bits/stdc++.h>
#define v vector<vector<long>>
using namespace std;
long util(int i,int j,v &dp,vector<long>&arr,vector<long>&sum){
	if(i>j)
		return 0;
	if(i==j){
		dp[i][j]=arr[i];
		return dp[i][j];
	}
	if(dp[i][j]!=-1)
		return dp[i][j];
	dp[i][j]=arr[i]+sum[j]-sum[i]-util(i+1,j,dp,arr,sum);
	long temp=arr[j]+sum[j-1];
	if(i-1>=0)
		temp-=sum[i-1];
	temp-=util(i,j-1,dp,arr,sum);
	dp[i][j]=max(dp[i][j],temp);
	return dp[i][j];
}
int main(){
	int n;
	cin>>n;
	vector<long>arr(n);
	vector<long>sum(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(i==0)
			sum[0]=arr[i];
		else
		sum[i]=sum[i-1]+arr[i];
	}
	v dp(n,vector<long>(n,-1));
	long x=util(0,n-1,dp,arr,sum);
	long y=sum[n-1]-x;
	cout<<x-y;
	return 0;
}