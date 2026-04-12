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
#include <bitset>
#include <numeric>
#include <ccomplex>
#include <cassert>
#include <random>
using namespace std;
using ll = long long;


ll dp[102][2][5];

int main() {
	string s; cin >> s;
	int n = s.size();
	int k; cin >> k;
	
	dp[0][1][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i + 1][0][j] += dp[i][0][j];
			dp[i + 1][0][j + 1] += dp[i][0][j] * 9;
			if (s[i] >= '1') {
				dp[i + 1][0][j] += dp[i][1][j];
				dp[i + 1][0][j + 1] += dp[i][1][j] * (s[i] - '1');
			}
			dp[i + 1][1][j + (s[i] != '0')] += dp[i][1][j];
		}
	}
	cout << dp[n][0][k] + dp[n][1][k] << endl;
	return 0;
}
