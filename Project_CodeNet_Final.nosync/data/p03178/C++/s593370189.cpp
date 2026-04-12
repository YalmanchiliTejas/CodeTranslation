#include <iostream>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <string>

#include <algorithm>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

const long long MOD = 1000000007;
long long dp[10005][105][2];

string s;
int d;

long long calc(int i, int m, int tight) {
	if (i < 0) {
		if (m == 0) return 1;
		else return 0;
	}
	if (dp[i][m][tight] != -1) return dp[i][m][tight];

	dp[i][m][tight] = 0;

	if (tight) {
		for (int j = 0; j < s[i]-48; j++) {
			dp[i][m][tight] += calc(i-1, (m+j)%d, 0);
		}
		dp[i][m][tight] += calc(i-1, (s[i]-48 + m+100*d)%d, tight);
	}
	else {
		for (int j = 0; j < 10; j++) {
			dp[i][m][tight] += calc(i-1, (m+j)%d, 0);
		}	
	}

	dp[i][m][tight] %= MOD;

	return dp[i][m][tight];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 10005; i++) {
		for (int j = 0; j < 105; j++) {
			dp[i][j][0] = dp[i][j][1] = -1;
		}
	}

	cin >> s >> d;
	reverse(s.begin(), s.end());
	cout << (calc(s.size()-1, 0, 1) + MOD - 1) % MOD << endl;

	return 0;
}
