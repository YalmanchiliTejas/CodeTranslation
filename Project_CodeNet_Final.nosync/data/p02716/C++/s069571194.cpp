#include <iostream>
using namespace std;

typedef long long ll;

ll dp[100005][3][2];
ll dpx[100005][2];
ll a[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if( n % 2 == 0 )
	{
		for (int i = 0; i < n / 2; i++)
		{
			int t1 = a[i*2];
			int t2 = a[i*2+1];
			if( i == 0 )
			{
				dpx[i][0] = t1;
				dpx[i][1] = t2;
			}else
			{
				dpx[i][0] = dpx[i-1][0] + t1;
				dpx[i][1] = max(dpx[i-1][0],dpx[i-1][1]) + t2;
			}
		}
		cout << max(dpx[n/2-1][0],dpx[n/2-1][1]) << '\n';
		return 0;
	} 
	for (int i = 0; i < n / 2; i++)
	{
		int t1 = a[i*2];
		int t2 = a[i*2+1];
		if( i == 0 )
		{
			dp[i][0][0] = t1;
			dp[i][0][1] = t2;
			dp[i][1][0] = max(t1,t2);
			dp[i][1][1] = a[i*2+2];
			dp[i][2][0] = -1e18;
			dp[i][2][1] = -1e18;
		}else
		{
			dp[i][0][0] = dp[i-1][0][0] + t1;
			dp[i][0][1] = max(dp[i-1][0][0],dp[i-1][0][1]) + t2;
			int t3 = a[i*2+2];
			dp[i][1][0] = max(dp[i-1][0][0] + max(t1,t2),dp[i-1][0][1] + t2);
			dp[i][1][1] = max(dp[i-1][0][0],dp[i-1][0][1]) + t3;
			int x1 = a[i*2+1];
			int x2 = a[i*2+2];
			dp[i][2][0] = max(dp[i-1][1][0],dp[i-1][2][0]) + x1;
			dp[i][2][1] = max(max(dp[i-1][1][0],dp[i-1][1][1]),max(dp[i-1][2][0],dp[i-1][2][1])) + x2;
		}
	}
	cout << max(max(dp[n/2-1][1][0],dp[n/2-1][1][1]),max(dp[n/2-1][2][0],dp[n/2-1][2][1])) << '\n';
	return 0;
}
