#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <tuple>
#include <queue>

int main(int /*argc*/, char** /*argv*/)
{
	int N;
	std::cin >> N;
	std::vector<uint64_t> A(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> A[i];
	}
	uint64_t ans = 0;
	uint64_t AJ = 0;
	for (int i = 0; i < N; ++i) {
		AJ += A[i];
	}
	for (int i = 0; i < N; ++i) {
		AJ -= A[i];
		ans = (ans + A[i] * (AJ% 1000000007ULL)) % 1000000007ULL;
	}


	std::cout << ans << std::endl;
	return 0;
}
