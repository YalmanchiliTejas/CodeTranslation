#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template <typename T>
using Vec = std::vector<T>;

int main() {
	std::string s;
	int k;
	std::cin >> s >> k;

	//if (s.size() == 1) {
	//	std::cout << (k == 1 ? s : "0") << std::endl;
	//	return 0;
	//}
	//if (s.size() == 2) {
	//	std::cout << (
	//		k == 2 ? (s[0] - '0' - 1) * 9 + (s[1] - '0') :
	//		k == 1 ? (s[0] - '0') + 9 :
	//		0
	//		) << std::endl;

	//	return 0;
	//}

	Vec<Vec<Vec<int>>> dp(s.size() + 1, Vec<Vec<int>>(2, Vec<int>(k + 1)));
	
	dp[0][1][0] = 1;
	for (int i = 1; i <= s.size(); ++i)
		dp[i][0][0] = 1;

	for (int i = 1; i <= s.size(); ++i) {
		for (int j = 1; j <= i && j <= k; ++j) {
			int x = s[i - 1] - '0';

			dp[i][0][j] = dp[i - 1][0][j] + dp[i - 1][0][j - 1] * 9;
			if (x != 0) {
				dp[i][0][j] += dp[i - 1][1][j - 1] * (x - 1) + dp[i - 1][1][j];
				dp[i][1][j] = dp[i - 1][1][j - 1];
			}
			else
				dp[i][1][j] = dp[i - 1][1][j];
		}
	}

	std::cout << dp[s.size()][0][k] + dp[s.size()][1][k] << std::endl;
}