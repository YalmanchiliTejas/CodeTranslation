#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

string K;
int D;
int dp[2][102];

void add(int &a, int b) {
	a = (a+b)%mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> K >> D;

	dp[0][0] = 0;
	int cur = 0;
	int prev = 1;

	int dc;
	int csum = 0;
	for (int i = 0; i < K.length(); i++) {
		dc = K[i] - '0';
		swap(prev, cur);

		fill(dp[cur], dp[cur]+D, 0);
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < D; k++) {
				int nx = (k + j)%D;
				add(dp[cur][nx], dp[prev][k]);
			}
		}

		// cout << "meh: " << dp[cur][0] << endl;

		for (int j = 0; j < dc; j++) {
			// cout << i << " this" << endl;
			int nx = (csum + j)%D;
			// cout << " --- "  << nx << endl;
			add(dp[cur][nx], 1);
		}

		csum = (csum + dc)%D;

		// for (int j = 0; j < D;  j++) {
			// cout << i << " " <<j << " : " << dp[cur][j] << endl;
		// }
	}

	if (csum == 0) {
		add(dp[cur][0], 1);
	}
	add(dp[cur][0], mod-1); //subtract out 0

	cout << dp[cur][0] << endl;
	
}