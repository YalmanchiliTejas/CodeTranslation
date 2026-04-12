#include <bits/stdc++.h>
using namespace std;

//dp[i][j] = max a person can get from strones from i to  j

int main()
{
	long long int n;
	cin >> n;
	vector<long long int> x(n);
	
	for(long long int i=0;i<n;i++)
		cin>>x[i];

	if(n==0)
	{
		cout<<0;
		return 0;
	}
	if(n==1)
	{
		cout<<x[0];
		return 0;
	}
	vector<long long int> ab(n+1);
	vector<vector<long long int> > dp(n+1,ab);

	for(long long int i=1;i<n;i++)
		{
			dp[i][i]=x[i-1];
			
			if(x[i-1]>x[i])
				dp[i][i+1]=x[i-1];
			else
				dp[i][i+1]=x[i];
		}

	dp[0][0]=0;
	dp[n][n]=x[n-1];

	

	for(long long int len=2;len<=n;len++)
	{
		for(long long int i=1;i<=n-len;i++)
		{
			
			long long int j=i+len;	
			
			long long int a=min(dp[i+2][j],dp[i+1][j-1]) + x[i-1];
			long long int b=min(dp[i][j-2],dp[i+1][j-1]) + x[j-1];
			
			dp[i][j]=max(a,b);
		}
	}
	long long int a=dp[1][n];
	long long int b=min(dp[2][n],dp[1][n-1]);
	cout<<a-b;
	return 0;

}