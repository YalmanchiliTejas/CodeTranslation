/*
 * 16-11-20_chu2_D.cpp
 *
 *  Created on: 2016/11/29
 *      Author: ryoma
 */
#include<iostream>
#include<algorithm>

using namespace std;

int field[210][210];
int H, W;

int dp[210][210][410];

int rs[4] = { 0, 0, 1, 1 }, re[4] = { 0, 1, 0, 1 };

int dfs(int sj, int ej, int d) {
	if (sj > W || ej > W || d - sj > H || d - ej > H || d > H + W)
		return 0;
	if (dp[sj][ej][d] > 0) {
		return dp[sj][ej][d] - 1;
	}
	int res = 0;
	for (int i = 0; i < 4; i++) {
		res = max(res, dfs(sj + rs[i], ej + re[i], d + 1));
	}
	res += field[d - sj][sj] + field[d - ej][ej];
	if (sj == ej)
		res -= field[d - sj][sj];
	dp[sj][ej][d] = res + 1;
	return res;
}

int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> field[i][j];
		}
	}
	cout << dfs(0, 0, 0) << endl;

	return 0;
}

