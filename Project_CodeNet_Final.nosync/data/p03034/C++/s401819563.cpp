#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <queue>
#include <functional>
#include <climits>
#include <numeric>
#include <bitset>
#include <random>
#include <tuple>
#include <initializer_list>
#include <fstream>
#include <cctype>
#include <string>


int main() {
	int n; std::cin >> n;
	std::vector<long long int> leaves(n); for (auto& l : leaves) std::cin >> l;
	long long int result{ 0 };
	for (auto diff = 1; diff < n; ++diff) {
		long long int left{ 0 }, right{ 0 };
		for (auto m = 1; m * diff < n - 1; ++m) {
			if ((n - 1 - m * diff) % diff == 0 && (n - 1 - m * diff) / diff <= m) break;
			if (n - 1 - m * diff < diff) break;
		 	left += leaves[m * diff];
			right += leaves[n - 1 - m * diff];
			result = std::max(result, left + right);
		}
	}
	std::cout << result << std::endl;
}
