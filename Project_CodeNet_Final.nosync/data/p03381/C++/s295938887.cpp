
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
#define all(C) std::begin(C), std::end(C)
const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

int32_t N;
int32_t pos[200000];
std::pair<int32_t, int32_t> v[200000];

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N;
	for (int32_t i = 0; i < N; i++)
	{
		in >> v[i].first;
		v[i].second = i;
	}
	std::sort(v, v + N);
	for (int32_t i = 0; i < N; i++)
	{
		pos[v[i].second] = i;
	}
	for (int32_t i = 0; i < N; i++)
	{
		if (pos[i] < N / 2) {
			out << v[N / 2].first<<endl;
		}
		else {
			out << v[N / 2-1].first << endl;
		}
	}

	return 0;
}
#endif
