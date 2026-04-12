#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,i,j,k;
	cin>>n;
	long long int dp[n+10][n+10][3];
	long long int a[n+10];
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		dp[i][i][0]=a[i];
		dp[i][i][1]=0;
	}
	for(j=2;j<=n;j++)
	{
		i=1;
		k=j;
		while(i<n&&k<=n)
		{
			dp[i][k][0]=max(a[i]+dp[i+1][k][1],a[k]+dp[i][k-1][1]);
			dp[i][k][1]=min(dp[i+1][k][0],dp[i][k-1][0]);
			i+=1;
			k+=1;
		}
	}

	cout<<dp[1][n][0]-dp[1][n][1]<<endl;
}