#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX_N=3005;
LL dp[MAX_N][MAX_N];
int a[MAX_N];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(n%2)dp[i][i]=a[i];
		else dp[i][i]=-a[i];
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=n;i++)
		{
			int j=i+l-1;
			if(j>n)continue;
			if(l%2!=n%2)dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
			else dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}
