#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int size = s.size();
	int k;
	cin >> k;

	long long dp[size+1][2][k+1];
	fill((long long *)dp, (long long *)dp + sizeof(dp)/sizeof(long long), 0);
	dp[0][0][0] = 1;
	for (int i = 0; i < size; ++i) {
		const int D = s[i] - '0';
		for (int smaller = 0; smaller <= 1; ++smaller) {
			for (int j = 0; j <= k; ++j) {
				int x_max = smaller ? 9 : D;
				for (int x = 0; x <= x_max; ++x) {
					int next_j = x==0 ? j : j+1;
					if (next_j > k) continue;
					dp[i+1][smaller || x<D][next_j] += dp[i][smaller][j];
				}
			}
		}
	}
	long long ans = dp[size][0][k] + dp[size][1][k];
	cout << ans << endl;
	return 0;
}