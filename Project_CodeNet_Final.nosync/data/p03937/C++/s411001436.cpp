
#include <iomanip>
#include <utility>
#include <algorithm>
#include <type_traits>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
#include <memory>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <vector>
#include <array>
#include <chrono>
#include <random>
#include <forward_list>
#include <iomanip>
#include <functional>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <numeric>

using namespace std;
#define MFOR(i,end) for(size_t i = 0, end_i = (end); i < end_i; ++ i)

int main()
{
	int H, W;
	char map[100][100];//y,x
	cin >> H >> W;
	for (size_t i = 0; i < H; ++i)
	{
		cin >> map[i];
	}
	bool impossible = false;
	for (size_t x = 0; x < W; ++x) {
		for (size_t y = 0; y < H; ++y) {

			if (map[y][x] == '#')
			{
				for (size_t y2 = 0; y2 < H; ++y2) {
					impossible |= std::any_of(map[y2], map[y2] + x, [](char c) {return c == '#'; });
				}
				for (size_t y2 = 0; y2 < y; ++y2) {
					impossible |= std::any_of(map[y2], map[y2] + W, [](char c) {return c == '#'; });
				}
				map[y][x] = '.';
			}

		}
	}
	if (impossible) {
		cout << "Impossible" << std::endl;
	}
	else {
		cout << "Possible" << std::endl;
	}
}