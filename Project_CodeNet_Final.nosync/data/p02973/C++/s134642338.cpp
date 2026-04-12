#include <bits/stdc++.h>

int main()
{
	int N;
	scanf("%d", &N);
	std::vector<int> A(N);
	for (auto& e: A) scanf("%d", &e);
	std::set<std::pair<int, int>> appeared;
	appeared.insert({1, -1});
	for (int i{}; i < N; i++)
	{
		if (-A[i] < appeared.rbegin()->first)
			appeared.erase(appeared.upper_bound({-A[i], 1 << 30}));
		appeared.insert({-A[i], i});
	}
	printf("%d\n", appeared.size());

	return 0;
}