#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long inf = 123456789123456789;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<vector<long long> > dp(N + 1);
	dp[0] = vector<long long>(N + 1, 0);
	for (int i = 1; i <= N; ++i) {
		dp[i] = vector<long long>(N - i + 1, -inf);
		for (int j = 0; j <= N - i; ++j) {
			dp[i][j] = max(A[j + i - 1] - dp[i - 1][j], A[j] - dp[i - 1][j + 1]);
		}
	}
	cout << dp[N][0] << '\n';
	return 0;
}