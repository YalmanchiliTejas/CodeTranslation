#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<complex>
#include<algorithm>
#include<vector>

int main()
{
	int n;
	long long a[100000], sum{};
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", a + i);
	}

	std::sort(a, a + n);

	if (n & 1)
	{
		int les = std::min(a[n / 2] - a[n / 2 - 1], a[n / 2 + 1] - a[n / 2]);
		for (int i = 0; i < n; ++i)
		{
			sum += std::abs(a[i] - a[n / 2]) * 2;
		}
		sum -= les;
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			sum += std::abs(a[i] - a[n / 2]) * 2;
		}
		sum -= a[n / 2] - a[n / 2 - 1];
	}

	printf("%lld\n", sum);

	return 0;
}