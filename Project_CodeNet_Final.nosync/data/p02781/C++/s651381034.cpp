#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;


int main() {
	string N; int K;
	cin >> N >> K;
	// 上からi桁目 N以下 0以外を何回
	ll dp[101][2][5] = {};
	
	dp[0][0][0] = 1;

	for (int i = 0; i < N.size(); i++)for (int j = 0; j < 2; j++)for (int k = 0; k < 4; k++) {
		for (int x = 0; x <= (j ? 9 : (N[i] - '0')); x++) {
			dp[i + 1][j || (x < N[i] - '0')][k + (x != 0)] += dp[i][j][k];
		}
	}
	
	cout << dp[N.size()][1][K] + dp[N.size()][0][K] << endl;
}