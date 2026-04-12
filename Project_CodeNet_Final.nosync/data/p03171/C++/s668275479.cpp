#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;
typedef long long li;
const li MAX = 3001;
li n, dp[MAX][MAX], a[MAX], mus = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mus += a[i];
	}
	li ch = n % 2;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j > n) continue;
			if (ch == i % 2) {
				dp[i][j] = max(dp[i - 1][j] + a[i + j - 1], dp[i - 1][j + 1] + a[j]);
			}
			else {
				if (i == 1) dp[i][j] = 0;
				else dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]);
			}
		}
	}
	cout <<dp[n][0] - (mus - dp[n][0]);
	//system("pause");
	return 0;
}