#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#pragma warning (disable: 4996)
using namespace std;

int H, W, cnt;
int dp[9][9];
char c[9][9];

int main() {
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> c[i][j];
			if (c[i][j] == '#') cnt++;
		}
	}
	if (cnt != H + W - 1) {
		cout << "Impossible" << endl;
		return 0;
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (i >= 2) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (j >= 2) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			if (c[i][j] == '#') dp[i][j] += 1;
		}
	}
	
	if (dp[H][W] == cnt) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}