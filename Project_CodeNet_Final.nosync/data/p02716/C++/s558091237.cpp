#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 2e5 + 10;
ll c[N], sum[N], dp[N];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &c[i]);
	sum[1] = c[1];
	for (int i = 3; i <= n; i += 2)
		sum[i] = sum[i - 2] + c[i];
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (i & 1)
			dp[i] = max(dp[i - 1], dp[i - 2] + c[i]);
		else 
			dp[i] = max(dp[i - 2] + c[i], sum[i - 1]);
	}
	printf("%lld", dp[n]);
}
/*
27
18 -28 18 28 -45 90 -45 23 -53 60 28 -74 -71 35 -26 -62 49 -77 57 24 -70 -93 69 -99 59 57 -49
*/