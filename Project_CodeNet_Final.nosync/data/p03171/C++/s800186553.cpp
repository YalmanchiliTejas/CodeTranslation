#include<iostream>
#include<iomanip>
#include<cstring>
#define prDouble cout << fixed << setprecision(10) << x
#define fast_io ios_base::sync_with_stdio(false)
#define ii pair<int,int>
#define ll long long int
using namespace std;
int main()
{
	fast_io;
	int n;
	cin >> n;
	ll nums[n];
	ll sum = 0;
	for(int i = 0;i < n;++i)
		cin >> nums[i],sum += nums[i];
	ll dp[n][n];
	memset(dp,0,sizeof(dp));
	for(int i = n - 1;i >= 0;--i)
	{
		for(int j = i;j < n;++j)
		{
			if(i == j)
				dp[i][j] = nums[i];
			else if(i + 1 == j)
				dp[i][j] = max(nums[i],nums[j]);
			else 
				dp[i][j] = max(nums[i]+min(dp[i+2][j],dp[i+1][j-1])
					,nums[j]+min(dp[i+1][j-1],dp[i][j-2]));
		}
	}
	cout <<(dp[0][n-1] - (sum - dp[0][n-1]))<< "\n";
	return 0;
}