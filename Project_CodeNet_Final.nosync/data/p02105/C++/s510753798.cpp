
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

#define in std::cin
#define out std::cout

int64_t N, MAX, MIN;
int32_t count[5] = {};
int64_t item[5][500][2] = {};
int32_t hash[5] = {0,1,2,3,4};

std::pair<int64_t, int64_t> patt_A[200 * 200 * 200];
auto patt_A_end = patt_A;
std::pair<int64_t, int64_t> patt_B[500*500];
auto patt_B_end = patt_B;

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> N>>MIN>>MAX;
	for (size_t t = 0; t < 5; t++)
	{
		item[t][count[t]][0] = 0;
		item[t][count[t]][1] = 0;
		++count[t];
	}
	for (int32_t i = 0; i < N; i++)
	{
		int64_t t, x, y;
		in >> t >> x >> y; --t;
		item[t][count[t]][0] = x;
		item[t][count[t]][1] = y;
		++count[t];
	}
	std::sort(hash, hash + 5, [](int i, int j) {return count[i] < count[j]; });

	for (int i = 0; i < count[hash[0]]; i++)
		for (int j = 0; j < count[hash[1]]; j++)
			for (int k = 0; k < count[hash[2]]; k++)
	{
		(*patt_A_end).first  = item[hash[0]][i][0] + item[hash[1]][j][0] + item[hash[2]][k][0];
		(*patt_A_end).second = item[hash[0]][i][1] + item[hash[1]][j][1] + item[hash[2]][k][1];
		++patt_A_end;
	}
	std::sort(patt_A, patt_A_end, std::greater<>{});
	for (int i = 0; i < count[hash[3]]; i++)
		for (int j = 0; j < count[hash[4]]; j++)
	{
		(*patt_B_end).first  = item[hash[3]][i][0] + item[hash[4]][j][0];
		(*patt_B_end).second = item[hash[3]][i][1] + item[hash[4]][j][1];
		++patt_B_end;
	}
	std::sort(patt_B, patt_B_end);

	std::multiset<int64_t> sets;
	auto B_beg_iter = patt_B, B_end_iter = patt_B;
	for (auto iter = patt_A; iter != patt_A_end; ++iter)
	{
		//push
		while (B_end_iter != patt_B_end && B_end_iter->first <= MAX - iter->first) {
			sets.insert(B_end_iter->second);
			++B_end_iter;
		}
		//pop
		while (B_beg_iter != B_end_iter &&B_beg_iter->first < MIN - iter->first) {
			sets.erase(sets.find(B_beg_iter->second));
			++B_beg_iter;
		}

		auto iter1 = sets.lower_bound(MIN - iter->second);
		if (iter1 != sets.end() && *iter1 + iter->second <= MAX) {
			out << "Yes" << endl;
			return 0;
		}
	}
	out << "No" << endl;

	return 0;
}
#endif