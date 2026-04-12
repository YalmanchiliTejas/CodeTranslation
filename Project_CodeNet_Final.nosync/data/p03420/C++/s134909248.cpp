#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	/*
	for(int i = k + 1; i <= n; ++i)
	{
		for(int j = k; j < i; ++j)
		{
			ans += (n - j) / i + (j > 0);
		}
	}
	*/
	for(int i = k + 1; i <= n; ++i)
	{
		for(int j = 0; j + k <= n; j += i)
		{
			int l = max(1, j + k);
			int r = min(n, j + i - 1);
			ans += r - l + 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}