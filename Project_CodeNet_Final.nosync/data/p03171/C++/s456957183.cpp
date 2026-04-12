#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <set>
#include <fstream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

#define ll long long
#define mod 1000000007

ll dp[3001][3001];

int main() {

	int n;
	cin >> n;
	ll a[n];

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	memset(dp, 0, sizeof(dp));

	for (int l = n-1; l >= 0; l--) {
		for (int r = l; r < n; r++) {
			if (l == r) {
				dp[l][r] = a[l];
			} else {
				dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
			}
		}
	}
	cout << dp[0][n - 1];

	return 0;
}