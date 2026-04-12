#include <bits/stdc++.h>

int main()
{
	int N;
	scanf("%d", &N);
	int count{}, max{};
	for (int i{}; i < N; i++)
	{
		int H;
		scanf("%d", &H);
		if (max <= H) count++;
		max = std::max(max, H);
	}
	printf("%d\n", count);

	return 0;
}