#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <functional>
using namespace std;

long long N, X, dp[100], dp2[100], sum = 0;

int main() {
	cin >> N >> X;
	dp[0] = 1; for (int i = 1; i <= N; i++) dp[i] = dp[i - 1] * 2 + 3;
	dp2[0] = 1; for (int i = 1; i <= N; i++) dp2[i] = dp2[i - 1] * 2 + 1;

	for (int i = N; i >= 1; i--) {
		if (X <= 1) {
			sum += 0; X = 0;
		}
		else if (X <= 1 + dp[i - 1]) {
			X -= 1;
		}
		else if (X <= 2LL + dp[i - 1]) {
			sum += dp2[i - 1] + 1; X = 0;
		}
		else if (X <= 2LL + 2LL * dp[i - 1]) {
			X -= (2LL + dp[i - 1]);
			sum += dp2[i - 1] + 1;
		}
		else {
			X = 0; sum += dp2[i];
		}
	}
	if (X >= 1) sum += 1;
	cout << sum << endl;
	return 0;
}