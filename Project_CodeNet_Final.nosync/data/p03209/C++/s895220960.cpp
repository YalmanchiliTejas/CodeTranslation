#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

uint64_t solve(int n, uint64_t x, bool whole = false) {
	if (!n)return 1;
  if (x < 2ull&&!whole)return 0;
	if (whole)return solve(n - 1, 0, true) * 2 + 1;
	if (x > (((1ull) << (n + 2))-3)/2+1)
		return solve(n - 1, 0, true) + solve(n - 1, x - ((((1ull)<<(n+2))-3)/2+1)) + 1;
	else if (x == (((1ull) << (n + 2))-3)/2+1)
		return solve(n - 1, 0, true) + 1;
	else return solve(n - 1, x - 1);
}

int main() {
	int N;
	uint64_t X;
	std::cin >> N >> X;
	std::cout << solve(N, X) << std::endl;
}
