#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[2][3001][3001];
int n;
/*
fn(int a[],int i,int j,int k)
{
	
	/*if(i>n)
	return 0;
	
	if(j<-1)
	return 0;
	
	if(i==j)
     {
     	dp[k][i][j]=a[i];
      return a[i];
	 }
	if(dp[k][i][j]!=-1)
	return dp[k][i][j];
	
	dp[0][i][j]=max(fn(a,i+1,j)+a[i],fn(a,i,j-1)+a[j]);
	
	return dp[k][i][j];
	
	
}
*/
int32_t main()
{
	//int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
	cin>>a[i];
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	{
		dp[0][i][j]=0;
		dp[1][i][j]=INT_MAX;
	}
     for(int i=0; i<n; i++)
     {
     	dp[0][i][i]=a[i];
     	dp[1][i][i]=-a[i];
	 }
	 
	 for(int l=2; l<=n; l++)
	 {
	 	for(int i=0; i<=n-l; i++ )
	 	{
	 		int j=i+l-1;
	 		
	 		dp[0][i][j]=max(dp[1][i+1][j]+a[i],dp[1][i][j-1]+a[j]);
	 		dp[1][i][j]=min(dp[0][i+1][j]-a[i],dp[0][i][j-1]-a[j]);
	 		
		 }
	 }
	
	cout<<dp[0][0][n-1];
	
	
}