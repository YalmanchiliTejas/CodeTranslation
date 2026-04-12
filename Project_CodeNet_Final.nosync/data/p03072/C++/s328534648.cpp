#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <array>
#include <queue>
#include <stack>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <type_traits>

int main()
{
	int N;
	std::vector<int> H;

	std::cin >> N;
	H.resize(N);
	for (auto& h : H)
		std::cin >> h;

	int ret = 1;
	int hmax = H[0];
	for (int i = 1; i < N; ++i) {
		if (H[i] >= hmax) {
			++ret;
			hmax = H[i];
		}
	}

	std::cout << ret << "\n";
}
