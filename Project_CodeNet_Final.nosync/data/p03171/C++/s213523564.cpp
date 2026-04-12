#include <bits/stdc++.h>

using vll = std::vector<long long>;

int main()
{
	int n;
	scanf("%d", &n);
	std::vector<long long> a(n);
	for (int i{}; i < n; i++)
		scanf("%lld", &a[i]);
	std::vector<vll> dif(n, vll(n));
	for (int i{}; i < n; i++)
	{
		if (n & 1)
			dif[i][i] = a[i];
		else
			dif[i][i] = -a[i];
	}
	for (int n_i{n - 1}; n_i > 0; n_i--)
	{
		for (int left{}; left < n_i; left++)
		{
			int right{n - n_i + left};
			if (n_i & 1)
				dif[left][right] = std::max(dif[left][right - 1] + a[right], dif[left + 1][right] + a[left]);
			else
				dif[left][right] = std::min(dif[left][right - 1] - a[right], dif[left + 1][right] - a[left]);
		}
	}
	printf("%lld\n", dif[0][n - 1]);

	return 0;
}