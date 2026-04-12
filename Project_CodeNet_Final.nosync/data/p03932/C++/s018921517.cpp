#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;
	vector<vector<int>>field(H, vector<int>(W));
	for (auto &i : field)for (auto &j : i)cin >> j;
	vector<vector<vector<int>>>dp(W, vector<vector<int>>(W, vector<int>(H + W - 2)));
	dp[1][0][1] = field[0][0] + field[0][1] + field[1][0];
	for (int i = 1; i < H + W - 3; i++) {
		for (int j = 0; j < W; j++) {
			for (int k = 0; k < j; k++) {
				int ax = j, bx = k, ay = i - ax, by = i - bx;
				if (ax < 0 || bx < 0 || by < 0 || ay < 0)continue;
				if (ax >= W || ay >= H || bx >= W || by >= H)continue;
				if (ay + by != 1) {
					dp[ax][bx + 1][i + 1] = max(dp[ax][bx + 1][i + 1], dp[j][k][i] + field[ay + 1][ax] + field[by][bx + 1]);
				}
				if (ax + 1 < W) {
					dp[ax + 1][bx + 1][i + 1] = max(dp[ax + 1][bx + 1][i + 1], dp[j][k][i] + field[ay][ax + 1] + field[by][bx + 1]);
				}
				if (by + 1 < H) {
					dp[ax][bx][i + 1] = max(dp[ax][bx][i + 1], dp[j][k][i] + field[ay + 1][ax] + field[by + 1][bx]);
				}
				if (ax + 1 < W&&by + 1 < H) {
					dp[ax + 1][bx][i + 1] = max(dp[ax + 1][bx][i + 1], dp[j][k][i] + field[ay][ax + 1] + field[by + 1][bx]);
				}
			}
		}
	}
	cout << dp[W - 1][W - 2].back() + field.back().back() << endl;
}