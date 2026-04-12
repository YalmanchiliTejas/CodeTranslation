#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<cassert>
#include<queue>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

int board[222][222];
int dp[222][222][222][2];
int H, W;

int dfs(int row, int col1, int col2, int flag) {
	int& ret = dp[row][col1][col2][flag];
	if (ret >= 0) return ret;
	ret = 0;
	if (row == H+1) return ret;
	if (flag == 0) {
		// 左の人が右に移動
		if (col1+1 < col2) {
			ret = max(ret, board[row][col1+1] + dfs(row, col1+1, col2, 0));
		}
		ret = max(ret, dfs(row, col1, col2, 1));
	} else {
		// 右の人が右に移動
		if (col2 < W+1) {
			ret = max(ret, board[row][col2+1] + dfs(row, col1, col2+1, 1));
		}
	}
	// 一段下に移動
	ret = max(ret, board[row+1][col1] + board[row+1][col2] + dfs(row+1, col1, col2, 0));
	return ret;
}

int main() {
	cin >> H >> W;
	for (int i = 1; i <= H; i++) for (int j = 1; j <= W; j++)
		cin >> board[i][j];
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0, 1, 0) << endl;
	return 0;
}
