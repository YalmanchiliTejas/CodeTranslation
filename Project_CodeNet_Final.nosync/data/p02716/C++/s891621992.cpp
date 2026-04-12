#include <bits/stdc++.h>

using namespace std;

long long n;
long long a[200010];
long long dp[200010][10];

int main(void)
{
	scanf("%lld", &n);
	
	for(long long i = 0 ; i < n ; i++)
		scanf("%lld", &a[i]);
	
	dp[0][0] = a[0];
	dp[1][1] = a[1];
	
	if(n > 2)
	{
		dp[2][2] = a[2];
		dp[2][0] = a[0] + a[2];
	}
	
	if(n > 3)
		dp[3][1] = max(a[0] + a[3], a[1] + a[3]);
	
	for(int i = 4 ; i < n ; i++)
	{
		if(i % 2 == 0)
			dp[i][0] = dp[i - 2][0] + a[i];
		dp[i][1] = max(dp[i - 2][1] + a[i], dp[i - 3][0] + a[i]);
		dp[i][2] = max(dp[i - 2][2] + a[i], max(dp[i - 3][1] + a[i], dp[i - 4][0] + a[i]));
	}
	
	if(n % 2 == 0)
		printf("%lld", max(dp[n - 1][1], dp[n - 2][0]));
	else
		printf("%lld", max(max(dp[n - 1][2], dp[n - 2][1]), dp[n - 3][0]));
	
	return 0;
}