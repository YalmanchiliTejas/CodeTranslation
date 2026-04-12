#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<set>
#include<queue>

using namespace std;

#define INF (1000000000000000009)

int main()
{
	long long n;
	cin >> n;
	vector<long long> a(n);
	for(long long i=0;i<n;i++)
		cin >> a[i];
	vector<vector<vector<long long>>> dp(2,vector<vector<long long>>(3,vector<long long>(n,(-1)*INF)));

	dp[1][0][0]=a[0];
	dp[0][1][0]=0;

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			dp[1][j][i]=dp[0][j][i-1]+a[i];
			if(j==0)
				dp[0][j][i]=dp[1][j][i-1];
			else
				dp[0][j][i]=max(dp[1][j][i-1],dp[0][j-1][i-1]);
		}
	}

	long long ans=(-1)*INF;
	for(int i=0;i<2;i++)
		for(int j=0;j<3;j++)
		{
			if(n%2==0 and j==2)continue;
			if(n%2==1 and j==0)continue;
//			cout << i << " " << j << " " << dp[i][j][n-1] << endl;
			if(ans<dp[i][j][n-1])
				ans=dp[i][j][n-1];
		}
	
	cout << ans << endl;


}
