
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
#include <bitset>
#include <list>

auto& in = std::cin;
auto& out = std::cout;
#define all_range(C) std::begin(C), std::end(C)
const double PI = 3.141592653589793238462643383279502884197169399375105820974944;


template<typename T, typename U>
std::enable_if_t<std::rank<T>::value == 0> fill_all(T& arr, const U& v) {
	arr = v;
}
template<typename ARR, typename U>
std::enable_if_t<std::rank<ARR>::value != 0> fill_all(ARR& arr, const U& v) {
	for (auto& i : arr) {
		fill_all(i, v);
	}
}

int32_t N;
constexpr int64_t INF = 30001000000000555;
int64_t A[3100];
int64_t dp[3100][3100];
//[]
int64_t func(int l, int r)
{
	if (r < l) { return 0; }

	auto& memo = dp[l][r];
	if (memo != INF) {
		return memo;
	}
	return memo = std::max(
		A[l] - func(l + 1, r),
		A[r] - func(l, r - 1)
	);
}


int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);
	fill_all(dp, INF);
	in >> N;
	for (size_t i = 0; i < N; i++)
	{
		in >> A[i];
	}

	out << func(0, N - 1) << endl;

	return 0;
}
#endif
