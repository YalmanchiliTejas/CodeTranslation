#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
	int H, W;
	std::cin >> H >> W;
	std::vector<std::string> result;
	std::vector<int> erase_rows;
	std::string row;
	for (int i = 0; i < H; ++i) {
		std::cin >> row;
		if (row[0] == '.' && std::all_of(row.begin(), row.end(), [&](char c) { return c == row[0]; })) {
			erase_rows.push_back(i);
		}
		result.push_back(row);
	}
	int w = W;
	for (int i = 0; i < w; ) {
		char c = result[0][i];
		bool b = true;
		if (c == '.') {
			for (int j = 1; j < H; ++j) {
				if (c != result[j][i]) {
					b = false;
					break;
				}
			}
		}
		else {
			b = false;
		}
		if (b) {
			for (int j = 0; j < H; ++j) {
				result[j].erase(i, 1);
			}
			--w;
		}
		else {
			++i;
		}
	}
	for (int i = 0; i < H; ++i) {
		if (std::find(erase_rows.begin(), erase_rows.end(), i) != erase_rows.end()) {
			continue;
		}
		auto& row = result[i];
		std::cout << row << std::endl;
	}
	return 0;
}