#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>
#define MOD 1000000007
#define pb push_back
using namespace std;

long long dp[3030][3030];
long long a[3030];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int r = 1; r <= n; r++) {
		for (int l = r; l >= 1; l--) {
			if (l == r) dp[l][r] = a[l];
			else dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
		}
	}

	cout << dp[1][n];
	return 0;
}