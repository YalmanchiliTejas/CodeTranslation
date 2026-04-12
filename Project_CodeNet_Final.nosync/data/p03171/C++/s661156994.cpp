#include <bits/stdc++.h>
using namespace std;
long long int a[3004];
long long int dp[3004][3004];

long long int calculate(int i,int j)
{
	if(i==j)
	{
		dp[i][j]=a[i];
		return dp[i][j];
	}
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	dp[i][j]=max(a[j]-calculate(i,j-1) , a[i]-calculate(i+1,j));
	return dp[i][j];
}
int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i <=n; ++i)
	{
		for (int j = 0; j <=n; ++j)
		{
			dp[i][j]=-1;
		}
	}
	printf("%lld\n",calculate(0,n-1));

}