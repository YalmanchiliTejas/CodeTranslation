#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

const auto INF = numeric_limits<long long>::max();

long long solve(int N, const vector<long long>& A)
{
	if (N % 2 == 0) {
		vector<vector<long long>> dp(2, vector<long long>(N, -INF));

		dp[0][0] = A[0];
		for (int i = 2; i < N; i += 2) {
			dp[0][i] = dp[0][i - 2] + A[i];
		}
		dp[1][1] = A[1];

		for (int i = 3; i < N; i += 2) {
			dp[1][i] = dp[1][i - 2] + A[i];
			dp[1][i] = max(dp[1][i], dp[0][i - 3] + A[i]);
		}

		auto ans = max(dp[0][N - 2], dp[1][N - 1]);

		return ans;
	}
	else {

		vector<vector<long long>> dp(3, vector<long long>(N, -INF));

		dp[0][0] = A[0];
		for (int i = 2; i < N - 2; i += 2) {
			dp[0][i] = dp[0][i - 2] + A[i];
		}
		dp[1][1] = A[1];
		dp[2][2] = A[2];

		for (int i = 3; i < N; i += 2) {
			dp[1][i] = dp[1][i - 2] + A[i];
			dp[1][i] = max(dp[1][i], dp[0][i - 3] + A[i]);
			if (i + 1 < N) {
				dp[2][i + 1] = dp[2][i - 1] + A[i + 1];
				dp[2][i + 1] = max(dp[2][i + 1], dp[1][i - 2] + A[i + 1]);
				dp[2][i + 1] = max(dp[2][i + 1], dp[0][i - 3] + A[i + 1]);
			}
		}

		auto ans = max({ dp[0][N - 3], dp[1][N - 2], dp[2][N - 1] });

		return ans;
	}
}

int main()
{
	int N;
	cin >> N;
	vector<long long> A(N);
	for (auto& x : A) {
		cin >> x;
	}
	cout << solve(N, A) << endl;
}
