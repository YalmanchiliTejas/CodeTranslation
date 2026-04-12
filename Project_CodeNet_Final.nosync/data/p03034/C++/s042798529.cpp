#include <bits/stdc++.h>

int main()
{
	int N;
	scanf("%d", &N);
	std::vector<int64_t> s(N);
	for (auto& e: s) scanf("%lld", &e);
	int64_t max{};
	for (int delta{1}; delta < N - 2; delta++)
	{
		int64_t sum{};
		if ((N - 1) % delta)
		{
			for (int i{1}; delta < N - 1 - i * delta; i++)
			{
				sum += s[i * delta] + s[N - 1 - i * delta];
				max = std::max(max, sum);
			}
		}
		else
		{
			for (int i{1}; i * delta < N - 1 - i * delta; i++)
			{
				sum += s[i * delta] + s[N - 1 - i * delta];
				max = std::max(max, sum);
			}
		}
	}
	printf("%lld\n", max);

	return 0;
}