#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <random>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
#include <cstdint>
using namespace std;
using LL = long long;

LL dp[234567][3];

int main() {
	int N;
	cin >> N;
	vector<LL>A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	memset(dp, 0x88, sizeof(dp));
	dp[1][0] = A[0];
	dp[2][1] = A[1];
	dp[3][2] = A[2];
	dp[3][0] = A[0] + A[2];
	for (int i = 4; i <= N; ++i) {
		for (int d = 0; d < 3; ++d) {
			for (int x = 0; x <= d; ++x) {
				dp[i][d] = max(dp[i][d], dp[i - 2 - (d - x)][x] + A[i - 1]);
			}
		}
	}
	if (N % 2) {
		LL ans = max(dp[N - 2][0], max(dp[N - 1][1], dp[N][2]));
		cout << ans << endl;
	}
	else {
		LL ans = max(dp[N - 1][0], dp[N][1]);
		cout << ans << endl;
	}

	return 0;
}
