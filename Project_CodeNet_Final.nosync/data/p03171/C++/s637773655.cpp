#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e3+7;
int a[N];
ll sum[N], f[N][N];
int main()
{
	int n;
	ll ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum[i] = sum[i-1]+a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		f[i][i] = a[i];
	}
	for(int i = 2; i <= n; i++)
	{
		for(int l = 1, r = i; r <= n; l++, r++)
		{
			f[l][r] = max(sum[r]-sum[l-1]-f[l+1][r], sum[r]-sum[l-1]-f[l][r-1]);
		}
	}
	printf("%lld\n", 2*f[1][n]-sum[n]);
	return 0;
}