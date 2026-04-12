#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
long long dp[200005];
long long a[200005];
long long sum[200005];
int main()
{
	int n;
	scanf("%d", &n);
	scanf("%lld", &a[1]);
	sum[1] = a[1];
	for(int i = 2; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		if(i & 1)
			sum[i] = sum[i - 2] + a[i];
	}
	dp[1] = 0;
	for(int i = 2; i <= n; i++)
	{
		if(i & 1)
			dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
		else
			dp[i] = max(sum[i - 1], dp[i - 2] + a[i]);
	}
	printf("%lld", dp[n]);
	return 0;
}