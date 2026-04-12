#include <bits/stdc++.h>

int main()
{
	while (true)
	{
		int n;
		scanf("%d", &n);
		if (!n) break;
		
		std::vector<int> points(n);
		for (auto& e: points) scanf("%d", &e);
		std::sort(points.begin(), points.end());
		int sum{};
		for (int i{1}; i < n - 1; i++)
			sum += points[i];
		printf("%d\n", sum / (n - 2));
	}

	return 0;
}
