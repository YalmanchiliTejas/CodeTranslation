#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>
#include <bitset>
#include <functional>
#include <iomanip>
#include <random>

#define FOR_LT(i, beg, end) for (int i = (int)(beg); i < (int)(end); i++)
#define FOR_LE(i, beg, end) for (int i = (int)(beg); i <= (int)(end); i++)
#define FOR_DW(i, beg, end) for (int i = (int)(beg); (int)(end) <= i; i--)
#define REP(n)              for (int repeat_index = 0; repeat_index < (int)n; repeat_index++)


using namespace std;

int64_t f(int64_t i, int64_t k, int64_t n, vector<int64_t>& as)
{
	if (k == 0) return 0;

	int64_t idx = i * 200001LL + k;
	static unordered_map<int64_t, int64_t> msmo;
	auto it = msmo.find(idx);
	if (it != msmo.end()) return it->second;

	int64_t rn = n - i;
	if (rn == k * 2 - 1) {
		int64_t ans = 0;
		do {
			ans += as[i];
			i += 2;
		} while (i < n);
		return ans;
	}

	int64_t ans = max(f(i + 1, k, n, as), f(i + 2, k - 1, n, as) + as[i]);
	msmo[idx] = ans;
	return ans;
}

int64_t dp[200001][3][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);

	int64_t n; cin >> n;
	vector<int64_t> as(n); for (auto& a : as) cin >> a;

	dp[0][0][1] = as[0];
	dp[0][1][0] = 0;
	dp[0][0][0] = -10000000000000000;
	dp[0][1][1] = -10000000000000000LL;
	dp[0][2][0] = -10000000000000000LL;
	dp[0][2][1] = -10000000000000000LL;
	FOR_LT(i, 1, n) {
		// take case
		dp[i][0][1] = dp[i - 1][0][0] + as[i];
		dp[i][1][1] = dp[i - 1][1][0] + as[i];
		dp[i][2][1] = dp[i - 1][2][0] + as[i];

		// comp not take
		dp[i][0][0] = dp[i - 1][0][1];
		dp[i][1][0] = max(dp[i - 1][1][1], dp[i - 1][0][0]);
		dp[i][2][0] = max(dp[i - 1][2][1], dp[i - 1][1][0]);
	}

	if (n & 1) {
		cout << max(dp[n - 1][1][0], max(dp[n - 1][2][0], dp[n - 1][2][1])) << endl;
	}
	else {
		cout << max(dp[n - 1][0][0], max(dp[n - 1][1][0], dp[n - 1][1][1])) << endl;
	}

	/*
	int64_t ans = f(0, n / 2, n, as);
	cout << ans << endl;
	*/

	return 0;
}