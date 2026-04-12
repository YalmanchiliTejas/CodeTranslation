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

ll a[3001];
ll dp[3001][3001];

ll solve(int l, int r) {

	if (l > r)
		return INT_MIN;
	if (l == r)
		return a[l];
	if (l == r - 1)
		return max(a[l], a[r]);

	if (dp[l][r] == -1)
		dp[l][r] = max(a[l] + min(solve(l + 2, r), solve(l + 1, r - 1)), a[r] + min(solve(l + 1, r - 1), solve(l, r - 2)));

	return dp[l][r];
}

int main() {

	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << 2 * solve(0, n - 1) - sum;
	return 0;
}