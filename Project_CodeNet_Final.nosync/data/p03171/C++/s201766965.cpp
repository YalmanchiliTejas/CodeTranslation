#include <bits/stdc++.h>

#define ALL(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve(void) {

	int n;
	cin >> n;
	vi A(n);

	for(int& x : A) cin >> x;

	vector<vector<ll>> dp(n, vector<ll>(n));
	// dp[i][j] = ans for A[i, .. , j]
	for(int l = n - 1; l >= 0; l--) {
		for(int r = l; r < n; r++) {
			bool turn = (n - (r-l+1)) % 2 == 0;

			if(l == r) {
				dp[l][r] = A[l]*(turn ? 1 : -1);
			} else if(turn) {
				dp[l][r] = max(dp[l+1][r] + A[l], dp[l][r-1] + A[r]);
			} else {
				dp[l][r] = min(dp[l+1][r] - A[l], dp[l][r-1] - A[r]);
			}
		}
	}

	cout << dp[0][n-1] << '\n';

}

int main(void) {

	solve();
	return 0;
}
