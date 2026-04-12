
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

constexpr int32_t N = 200;//頂点数
std::vector<int32_t> graph[N];//木
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	int32_t t; in >> t;
	std::string s(N,'0');
	int32_t count = 0;
	for (int32_t i = 0; i < N; ++i)
	{
		s[i] = '1';
		for (int32_t j = i+1; j < N; ++j)
		{
			s[j] = '1';

			out << "? " << s<<endl;
			in >> t;
			if (t == 1) {
				graph[i].push_back(j);
				++count;
				if (count >= N-1) {
					goto res_out;
				}
			}

			s[j] = '0';
		}
		s[i] = '0';
	}
res_out:
	out << '!';
	for (int32_t i = 0; i < N; ++i)
	{
		for (auto& j : graph[i]) {
			out << " (" << i << ',' << j << ')';
		}
	}

	return 0;
}
#endif