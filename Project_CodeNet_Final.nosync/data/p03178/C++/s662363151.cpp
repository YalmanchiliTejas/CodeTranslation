// https://abc007.contest.atcoder.jp/tasks/abc007_4

#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

static const long long mod = 1000000007;

void add_mod(long long& lhs, long long rhs) {
	auto res = (lhs + rhs) % mod;
	if (res < 0) res += mod;
	lhs = res;
}

int main (int argc, char* argv[]) {
	string s;
	int d;
	cin >> s >> d;

	vector<vector<vector<long long>>> dp(s.size() + 1, vector<vector<long long>>(2, vector<long long>(d, 0)));
	dp[0][0][0] = 1;
	for (int i = 0; i < s.size(); i++) {
		int c_num = s[i] - '0';
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < d; k++) {
				for (int l = 0; l <= (j == 1 ? 9 : c_num); l++) {
					int next_mod = (k + l) % d;
					add_mod(dp[i + 1][(j || l < c_num) ? 1 : 0][next_mod], dp[i][j][k]);
				}
			}
		}
	}

	long long res = 0;
	add_mod(res, dp[s.size()][0][0]);
	add_mod(res, dp[s.size()][1][0]);
	add_mod(res, -1);

	cout << res << endl;
}
