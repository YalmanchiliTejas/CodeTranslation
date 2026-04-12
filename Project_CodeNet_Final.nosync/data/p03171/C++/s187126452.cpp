#include <bits/stdc++.h>

const int32_t MAX_N = 3000;

bool isCalc[MAX_N + 5][MAX_N + 5][2];
int32_t a[MAX_N + 5];
int64_t dp[MAX_N + 5][MAX_N + 5][2];

int64_t CalcDp(int32_t low, int32_t high, int32_t turn) {
	if(low > high) {
		return 0;
	}
	else if(isCalc[low][high][turn]) {
		return dp[low][high][turn];
	}

	if(turn == 0) {
		dp[low][high][turn] = std::max(CalcDp(low + 1, high, 1) + a[low], CalcDp(low, high - 1, 1) + a[high]);
	}
	else {
		dp[low][high][turn] = std::min(CalcDp(low + 1, high, 0) - a[low], CalcDp(low, high - 1, 0) - a[high]);
	}

	isCalc[low][high][turn] = true;
	return dp[low][high][turn];
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int32_t n;
	std::cin >> n;

	for(int32_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::cout << CalcDp(0, n - 1, 0) << '\n';
}

