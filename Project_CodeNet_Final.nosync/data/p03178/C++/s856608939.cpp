#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <iomanip>
#include <bitset>
using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;
ll dp[10005][2][103];

int main() {
	string s; cin >> s;
	int D; cin >> D;
	int n = s.size();
	dp[0][1][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int c = 0; c < D; c++) {
			for (int d = 0; d < s[i] - '0'; d++) {
				dp[i + 1][0][(c + d) % D] += (dp[i][0][c] + dp[i][1][c]) % mod;
				dp[i + 1][0][(c + d) % D] %= mod;
			}
			dp[i + 1][0][(c + s[i] - '0') % D] += dp[i][0][c];
			dp[i + 1][0][(c + s[i] - '0') % D] %= mod;
			dp[i + 1][1][(c + s[i] - '0') % D] += dp[i][1][c];
			dp[i + 1][1][(c + s[i] - '0') % D] %= mod;
			for (int d = s[i] - '0' + 1; d <= 9; d++) {
				dp[i + 1][0][(c + d) % D] += dp[i][0][c];
				dp[i + 1][0][(c + d) % D] %= mod;
			}
		}
	}
	cout << ((dp[n][0][0] + dp[n][1][0]) % mod  - 1 + mod)%mod << endl;

	return 0;
}