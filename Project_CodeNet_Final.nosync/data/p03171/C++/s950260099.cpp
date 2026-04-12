#include <iostream>

using namespace std;

typedef long long ll;

ll dp[3005][3005];

int main(int argc, char *argv[])
{
	int N, a[3005];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	for (int len = 1; len <= N; len++) {
		for (int i = 0; i < N - len + 1; i++) {
			int j = i + len;
			if ((N - len) % 2 == 0) {
				dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
			} else {
				dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
			}
		}
	}

	cout << dp[0][N] << endl;

	return 0;
}
