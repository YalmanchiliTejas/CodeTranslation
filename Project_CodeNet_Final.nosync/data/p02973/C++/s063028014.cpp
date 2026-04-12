#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// using namespace std;
constexpr int64_t MOD = 1000000007;

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	size_t N;
	std::cin >> N;
	std::vector<int> A(N, 0);
	for (size_t i = 0; i < N; i++) std::cin >> A[i];
	std::vector<int> id(N);
	for (size_t i = 0; i < N; i++) id[i] = i;
	std::sort(id.begin(), id.end(), [&A](int a, int b) { return A[a] != A[b] ? A[a] < A[b] : a > b; });
	std::set<int> col;
	for (auto& i: id)
	{
		auto it = col.lower_bound(i);
		if (it == col.begin())
			col.insert(i);
		else
		{
			col.erase(*(--it));
			col.insert(i);
		}
	}
	std::cout << col.size() << std::endl;
	// for (auto& i : col) std::cout << i << std::endl;
	std::cout << std::flush;
	return 0;
}
