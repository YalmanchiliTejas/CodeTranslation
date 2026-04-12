#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <tuple>
#include <bitset>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>
int main() {
	int h, w; std::cin >> h >> w;
	std::vector<std::string> state(h); for (auto& line : state) std::cin >> line;
	std::vector<int> row, column;
	for (auto i = 0; i < h; ++i) for (auto j = 0; j < w; ++j) {
		if (state[i][j] == '#') {
			row.push_back(i);
			column.push_back(j);
		}
	}
	std::sort(row.begin(), row.end()); std::sort(column.begin(), column.end());
	row.erase(std::unique(row.begin(), row.end()), row.end()); column.erase(std::unique(column.begin(), column.end()), column.end());
	for (const auto& r : row) {
		std::string line;
		for (const auto& c : column) {
			line.push_back(state[r][c]);
		}
		std::cout << line << '\n';
	}
}
