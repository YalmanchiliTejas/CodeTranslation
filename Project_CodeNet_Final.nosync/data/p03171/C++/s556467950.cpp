#include <bits/stdc++.h>
#define FAST_INPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

using namespace std;

const int mxn = 3005;
ll dp[mxn][mxn];

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int l = n - 1; l >= 0; l--) {
		for (int r = l; r < n; r++) {
			if (l == r) {
				dp[l][r] = a[l];
			} else {
				dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
			}
		}
	}

	cout << dp[0][n - 1] << endl;
}

int main() {
    FAST_INPUT;

    solve();

    return 0;
}
