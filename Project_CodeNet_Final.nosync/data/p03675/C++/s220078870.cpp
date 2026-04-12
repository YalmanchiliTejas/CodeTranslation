
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

auto& in = std::cin;
auto& out = std::cout;

int32_t N;
std::deque<int32_t> arr;

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N;
	for (int32_t i = 0; i < N; ++i)
	{
		int a;
		in >> a;
		if (i & 1) {
			arr.push_front(a);
		}
		else {
			arr.push_back(a);
		}
	}
	if (N & 1) {
		auto iter = arr.rbegin();
		out << *iter; ++iter;
		for (; iter != arr.rend(); ++iter) {
			out << ' ' << *iter;
		}
	}
	else {
		auto iter = arr.begin();
		out << *iter; ++iter;
		for (; iter != arr.end(); ++iter) {
			out << ' ' << *iter;
		}
	}
	out << endl;
	return 0;
}
#endif
