#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
#include <map>
#include<cmath>
#include <queue>
#include <numeric>
#include <cassert>
#include<map>
#include<bitset>

using lli = long long int;
lli inf = 1000000007;
using namespace std;

// [ i桁目 ][ 現在K個使っている状態 ][ 値が超えうるかどうか ]
int dp[110][4][2];

void solve() {
	string S;
	cin >> S;

	int K;
	cin >> K;
	int m = S.size();

	
	dp[0][0][0] = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 2; k++) {
				// 桁数
				int n = S[i] - '0';
				// 数を決める
				for (int x = 0; x <= 9; x++) {
					int ni = i + 1, nj = j, nk = k;
					// 0じゃないなら使用数を増やす
					if (x != 0) { nj += 1; }
					// K 超えたら条件に反する
					if (nj > K) { continue; }
					// 現在の桁までで値が等しい場合
					if (k == 0) {
						// 現在の桁の値より大きいのは選べない
						if (x > n)continue;
						// 未満ならk = 1へ遷移する
						if (x < n)nk = 1;
					}
					dp[ni][nj][nk] += dp[i][j][k];
				}
			}
		}
	}
	int ans = dp[m][K][0] + dp[m][K][1];
	cout << ans << endl;
}

int main()
{
	solve();
	return 0;
}
