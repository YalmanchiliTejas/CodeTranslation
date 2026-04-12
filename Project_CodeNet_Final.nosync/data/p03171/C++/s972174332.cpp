
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int l,i,j,n,k;
	int a[100009];
	cin>>n;
	long long int dp[n+1][n+1][2];
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			dp[i][j][0]=0;
			dp[i][j][1]=0;
		}
	}
	for(l=1;l<=n;l++)
	{
		for(i=0;i<n-l+1;i++)
		{
		//for(j=i;j<n;j++)
		//{
		//	l=j-i+1;
			j=i+l-1;
			if(i==j)
			{
				dp[i][j][0]=a[i];
				dp[i][j][1]=0;
			}
			else
			{
				if(dp[i+1][j][1]+a[i]-dp[i+1][j][0] > dp[i][j-1][1]+a[j]-dp[i][j-1][0])
				{
					dp[i][j][0] = dp[i+1][j][1]+a[i];
					dp[i][j][1] = dp[i+1][j][0];
				}
				else
				{
					dp[i][j][0] = dp[i][j-1][1]+a[j];
					dp[i][j][1] = dp[i][j-1][0];
				}
			}
				
		}
	}
		cout<<dp[0][n-1][0]-dp[0][n-1][1]<<endl;
	return 0;
}
