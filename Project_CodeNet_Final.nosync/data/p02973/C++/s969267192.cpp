#include <stdio.h>
#include <map>

int main()
{
	int N;
	scanf("%d", &N);

	std::map<int, int, std::greater<int>> map;
	for (int i = 0; i < N; i++) {
		int A;
		scanf("%d", &A);

		auto it = map.upper_bound(A);
		if (it != map.end()) {
			if (it->second == 1) {
				map.erase(it);
			}
			else {
				it->second--;
			}
		}
		auto it2 = map.find(A);
		if (it2 == map.end()) {
			map.emplace(A, 1);
		}
		else {
			it2->second++;
		}
	}

	int ans = 0;
	for (auto &e : map) {
		ans += e.second;
	}
	printf("%d\n", ans);

	return 0;
}
