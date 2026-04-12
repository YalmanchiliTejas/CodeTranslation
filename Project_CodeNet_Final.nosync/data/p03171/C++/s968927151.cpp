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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	vector<vector<long long int>>dp(N, vector<long long int>(N));
	if (N % 2) {
		for (int i = 0; i < N; i++) {
			dp[i][i] = v[i];
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			dp[i][i] = -v[i];
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j + i < N; j++) {
			if (i % 2 == N % 2) {
				dp[j][i + j] = min(dp[j + 1][i + j] - v[j], dp[j][i + j - 1] - v[i + j]);
			}
			else {
				dp[j][i + j] = max(dp[j + 1][i + j] + v[j], dp[j][i + j - 1] + v[i + j]);
			}
		}
	}

	cout << dp[0][N - 1] << endl;
	return 0;
} 