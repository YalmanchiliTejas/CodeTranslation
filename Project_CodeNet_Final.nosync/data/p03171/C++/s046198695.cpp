#include<bits/stdc++.h>
#define M 1000000007
#define pb push_back
#define ll long long int
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	int i,j;
	for(i=0;i<n;i++)
		cin>>a[i];
	long long dp[n][n][2];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			int k = j+i;
			if(k>n-1)
				continue;
			if(j==k)
			{
				dp[j][k][0] = a[j];
				dp[j][k][1] = -a[j];
			}
			else
			{
				dp[j][k][0] = max(a[j]+dp[j+1][k][1],a[k]+dp[j][k-1][1]);
				dp[j][k][1] = min(-a[j]+dp[j+1][k][0],-a[k]+dp[j][k-1][0]);				
			}
		}
	}
	cout<<dp[0][n-1][0];
	return 0;

}
