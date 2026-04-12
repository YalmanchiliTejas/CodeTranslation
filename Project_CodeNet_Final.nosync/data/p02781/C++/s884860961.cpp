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


int64_t dp[101][4];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);

	string s; cin >> s;
	int k; cin >> k;

	dp[0][0] = 1;
	dp[0][1] = (s[0] - '0') - 1;
	if (k == 1) dp[0][1]++;
	int c =	1;
	FOR_LT(i, 1, s.size()) {
		int v = s[i] - '0';

		if (c < k) {
			if (v != 0) {
				dp[i][c + 1] += v - 1;
				if (c + 1 == k) dp[i][c + 1]++;
				dp[i][c]++;
				c++;
			}
		}

		dp[i][0] = dp[i - 1][0];
		FOR_LE(j, 1, k) {
			dp[i][j] += dp[i - 1][j - 1] * 9 + dp[i - 1][j];
		}
	}

	cout << dp[s.size() - 1][k] << endl;

	return 0;
}