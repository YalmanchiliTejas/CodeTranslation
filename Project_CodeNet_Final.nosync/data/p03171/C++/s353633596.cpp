#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int main() {
	int n; cin >> n;
	vll a(n);
	vector<vll> dp(n, vll(n));
	for (int i = 0; i < n; i++){
		cin >> a[i];
		dp[i][i] = a[i];
	}

	for (int dx = 1; dx < n; dx++){
		for (int l = 0; l + dx < n; l++){
			int r = l + dx;
			dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
		}
	}
	cout << dp[0][n - 1] << endl;

}
