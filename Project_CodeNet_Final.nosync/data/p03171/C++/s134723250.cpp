#include <stdio.h>
#include <iomanip>
using namespace std;
#define brk system("pause");

const int N = 3001;
long long dp[N][N], a[N], n;

long long calc(int l, int r, int t = 0)
{
	if(l == r) return a[l] - 2 * a[l] * t;
	if(dp[l][r] != -1) return dp[l][r];
	
	if(t) dp[l][r] = min(calc(l + 1, r, t ^ 1) - a[l], calc(l, r - 1, t ^ 1) - a[r]);
	else dp[l][r] = max(calc(l + 1, r, t ^ 1) + a[l], calc(l, r - 1, t ^ 1) + a[r]);
	
	return dp[l][r];
}

main()
{
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			dp[i][j] = -1ll;
	
	printf("%lld\n", calc(1, n));
}
