#include<bits/stdc++.h>
using namespace std;
main()
{
	int n;
	cin>>n;
	
	vector<long long> a(n);
	
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	vector<vector<long long>> dp(n,vector<long long> (n,1e15)),dp1(n,vector<long long> (n,1e15)),dp2(n,vector<long long> (n,1e15));
	
	for(int i=0;i<n;i++)
	{		
		if(n%2)
		{
			dp1[i][i]=a[i];
			dp2[i][i]=0;
		}
		else
		{
			dp1[i][i]=0;
			dp2[i][i]=a[i];
		}
		dp[i][i]=dp1[i][i]-dp2[i][i];
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if((n-i)%2==0)
			{
				if(dp1[j][i+j-1]-(dp2[j][i+j-1]+a[i+j])<dp1[j+1][i+j]-(dp2[j+1][i+j]+a[j]))
				{
					dp[j][i+j]=dp1[j][i+j-1]-(dp2[j][i+j-1]+a[i+j]);
					dp1[j][i+j]=dp1[j][i+j-1];
					dp2[j][i+j]=dp2[j][i+j-1]+a[i+j];
				}
				else
				{
					dp[j][i+j]=dp1[j+1][i+j]-(dp2[j+1][i+j]+a[j]);
					dp1[j][i+j]=dp1[j+1][i+j];
					dp2[j][i+j]=dp2[j+1][i+j]+a[j];
				}
			}
			else
			{
				if(dp1[j][i+j-1]+a[i+j]-dp2[j][i+j-1]<dp1[j+1][i+j]+a[j]-dp2[j+1][i+j])
				{
					dp[j][i+j]=dp1[j+1][i+j]+a[j]-dp2[j+1][i+j];
					dp1[j][i+j]=dp1[j+1][i+j]+a[j];
					dp2[j][i+j]=dp2[j+1][i+j];
				}
				else
				{
					dp[j][i+j]=dp1[j][i+j-1]+a[i+j]-dp2[j][i+j-1];
					dp1[j][i+j]=dp1[j][i+j-1]+a[i+j];
					dp2[j][i+j]=dp2[j][i+j-1];
				}
			}
		}
	}
	
	cout<<dp[0][n-1];
}