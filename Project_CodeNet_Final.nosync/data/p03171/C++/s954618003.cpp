#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long i,l,j,n;
	cin >> n;
	long long a[n+1];
	long long dp[n+1][n+1] = { };
	a[0] = 0;
	for(i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(i=n;i>0;i--)
	{
		for(j=i;j<=n;j++)
		{
			if(i==j)
			dp[i][j]=a[i];
			else
			dp[i][j] = max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
		}
	}
	cout << dp[1][n] <<endl;
}