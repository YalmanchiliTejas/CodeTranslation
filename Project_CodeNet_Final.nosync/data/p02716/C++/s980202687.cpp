#include<iostream>
#include <algorithm>
using namespace std;

long long a[200010];
long long dp[200010];
long long presum[200010];
int n;
int main() 
{
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	presum[1] = a[1];
	for (int i = 3; i <= n; i += 2)
		presum[i] = presum[i - 2] + a[i];
	for (int i = 2; i <= n; i++)
	{
		if (i & 1)
			dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
		else
			dp[i] = max(dp[i - 2] + a[i], presum[i - 1]);

	}
	cout << dp[n] << endl;
	return 0;
}
