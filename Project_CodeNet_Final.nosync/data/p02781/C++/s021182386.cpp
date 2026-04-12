#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
long long dp[101][2][101] = { 0 };
int main() {
	string n;
	int ka;
	cin >> n >> ka;
	dp[0][0][0] = 1;
	for (int i = 0; i < n.size(); i++) {
		for (int k = 0; k < 101; k++) {
			dp[i + 1][1][k + 1] += dp[i][1][k] * 9;
			dp[i + 1][1][k] += dp[i][1][k];
		}
		for (int k = 0; k < 101; k++) {
			if (n[i] == '0') {
				dp[i + 1][0][k] += dp[i][0][k];
			}
			else {
				dp[i + 1][0][k + 1] += dp[i][0][k];
				dp[i + 1][1][k + 1] += dp[i][0][k] * int(n[i] - '0' - 1);
				dp[i + 1][1][k] += dp[i][0][k];
			}
		}
	}

	cout << dp[n.size()][0][ka] + dp[n.size()][1][ka] << endl;
	return 0;
}
