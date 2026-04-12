#include <iostream>
using namespace std;
long long dp[200005][5];
long long a[200005];
int main(int argc, char** argv) {
	long long n;
	cin >> n;
	for(long long i=1;i<=n;i++)
		cin >> a[i];
	long long k=n%2+1;
	for(long long i=1;i<=n+4;i++)
	{
		for(long long j=0;j<=2;j++)
			dp[i][j]=-1e18;
	}
	for(long long i=1;i<=n;i++)
	{
		if(i<=k+1)
			dp[i][i-1]=max(dp[i][i-1],a[i]);
		for(long long j=0;j<=k;j++)
		{
			if(j>-1&&i>1)dp[i][j]=max(dp[i][j],dp[i-2][j]+a[i]);
			if(j>0&&i>2) dp[i][j]=max(dp[i][j],dp[i-3][j-1]+a[i]);
			if(j>1&&i>3) dp[i][j]=max(dp[i][j],dp[i-4][j-2]+a[i]);
		}
	}
	long long ans=max(dp[n][k],dp[n-1][k-1]);
	if(k==2) ans=max(ans,dp[n-2][k-2]);
	cout << ans; 
	return 0;
}