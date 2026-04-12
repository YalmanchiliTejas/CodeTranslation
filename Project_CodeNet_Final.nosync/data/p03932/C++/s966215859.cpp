
#if 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>
#include <assert.h>

#define in std::cin
#define out std::cout

int32_t H,W;
int32_t num[200][200];
constexpr int64_t INF = int64_t(200) * 200 * 100000*100;

template<typename T>
void fill_all(T& arr, const T& v) {
	arr = v;
}
template<typename T, typename ARR>
void fill_all(ARR& arr, const T& v) {
	for (auto& i : arr) { fill_all(i, v); }
}

int64_t dp[200][200][200];
int64_t func(int h1, int w1, int h2, int w2)
{
	if (h1 >= H || h2 >= H || w1 >= W || w2 >= W) {
		return -INF;
	}
	auto& memo = dp[h1][w1][h2];
	if (memo != -1) {
		return memo;
	}
	memo = std::max(memo, func(h1 + 1, w1, h2, w2 + 1));
	memo = std::max(memo, func(h1 + 1, w1, h2 + 1, w2));
	memo = std::max(memo, func(h1, w1 + 1, h2, w2 + 1));
	memo = std::max(memo, func(h1, w1 + 1, h2 + 1, w2));
	if (w1 == w2 && h1 == h2) {
		memo += num[h1][w1];
	}
	else {
		memo += num[h1][w1] + num[h2][w2];
	}
	return memo;
}

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	fill_all<int64_t>(dp, -1);
	in >> H>>W;
	for (size_t i = 0; i < H; i++)for (size_t j = 0; j < W; j++)
	{
		in >> num[i][j];
	}

	out << func(0, 0, 0, 0)+1<<endl;

	return 0;
}
#endif
