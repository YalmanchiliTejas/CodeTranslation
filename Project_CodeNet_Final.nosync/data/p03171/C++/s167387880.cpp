#include <bits/stdc++.h>

using namespace std;

long int a[3005],dp[3005][3005][2];

long int brute(int i,int j,int k)
{
	//cout<<i<<" "<<j<<" "<<k<<endl;
	if(i == j)
	{
		if(k == 0)
		return a[i];
		return -a[i];
	}
	if(dp[i][j][k] == -1)
	{
		if(k == 0)
		dp[i][j][k] = max(brute(i+1,j,1)+a[i],brute(i,j-1,1)+a[j]);
		else 	
		dp[i][j][k] = min(brute(i+1,j,0)-a[i],brute(i,j-1,0)-a[j]);
	}
	return dp[i][j][k];
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	scanf("%ld",a+i);
	/*for(int i=n;i>=0;--i)
	{
		for(int j=i;j<=n;++j)
		{
			if(i == n || j == 0)
			{
				dp[i][j][0] = 0;
				dp[i][j][1] = 0;
			}
			else if(i == j)
			{
				dp[i][j][0] = 0;
				dp[i][j][1] = 0;
			}
			else 
			{
				//0
				dp[i][j][0] = max(dp[i+1][j][1]+a[i],dp[i][j-1][1]+a[j]);
				dp[i][j][1] = min(dp[i+1][j][0]-a[i],dp[i][j-1][0]-a[j]);
			}
		}
	}*/
	memset(dp,-1,sizeof dp);
	printf("%ld\n",brute(0,n-1,0));
	return 0;
}
