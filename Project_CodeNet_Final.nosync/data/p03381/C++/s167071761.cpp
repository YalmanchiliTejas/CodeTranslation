#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

std::vector<uint32_t> nums;
std::vector<uint32_t> sNums;

void input() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	uint32_t n;
	std::cin >> n;
	nums.resize(n);
	for (uint32_t &i : nums) {
		std::cin >> i;
	}

	sNums = nums;
	std::sort(sNums.begin(), sNums.end());
}

uint32_t find_ind(uint32_t a) {
	uint32_t l = 0;
	uint32_t r = sNums.size();
	while (r - l > 1) {
		uint32_t m = (r + l) / 2;
		if (sNums[m] > a) {
			r = m;
		} else {
			l = m;
			//sNums[m] = l;
		}
	}
	return l;
}

int main() {
	input();
	for (uint32_t i = 0;i < nums.size();i++) {
		uint32_t cInd = find_ind(nums[i]);
		uint32_t med = nums.size() / 2 - 1;
		if (cInd <= med) {
			med++;
		}
		std::cout << sNums[med] << "\n";
	}
}
