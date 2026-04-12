#include <bits/stdc++.h>

int main()
{
	int N;
	scanf("%d", &N); 
	std::vector<int64_t> A(N);
	for (auto& e: A) scanf("%lld", &e);
	std::set<int64_t> primeSet;
	for (auto e: A)
	{
		for (int i{2}; i * i <= e; i++)
		{
			if (e % i) continue;
			primeSet.insert(i);
			while (e % i == 0) e /= i;
		}
		if (e > 1) primeSet.insert(e);
	}
	int64_t max{};
	for (auto& e: primeSet)
	{
		int64_t sum{};
		for (auto& f: A)
			if (f % e == 0)
				sum += f;
		max = std::max(max, sum);
	}
	printf("%lld\n", max);

	return 0;
}
