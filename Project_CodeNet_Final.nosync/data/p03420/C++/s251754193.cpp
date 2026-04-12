#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	long long ans = 0;
	int n, k;
	scanf("%d %d", &n, &k);
	for (int b = k + 1; b <= n; b++)
	{
		for (int p = 0;; p++)
		{
			if (b*p + k > n)
				break;
			ans += min(p*b + b - 1, n) - max(p*b + k, 1) + 1;
		}
	}
	printf("%lld", ans);
	return 0;
}