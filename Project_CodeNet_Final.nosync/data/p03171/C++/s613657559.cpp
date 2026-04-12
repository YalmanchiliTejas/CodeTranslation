#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(false), cin.tie(NULL);

using namespace std;
const int N = 5e3 + 44;
const int X[] = {1,0,-1,0,1,-1,1,-1};
const int Y[] = {0,1,0,-1,1,1,-1,-1};
const int mod = 1e9 + 7;
const long long INF = 1e18;
const int inf = 1e9;

bool u[N][N];

long long dp[N][N];

long long pref[N];

long long a[N];

long long sum (int l, int r) {
	if (l > r) return 0ll;
	return pref[r] - (l ? pref[l - 1] : 0ll);
}

long long solve (int l, int r) {
	if (l > r) return 0ll;
	if (u[l][r]) return dp[l][r];
	u[l][r] = 1;
	dp[l][r] = sum (l, r) - min (solve (l + 1, r), solve (l, r - 1));
	return dp[l][r];
}

int main () {
	boost;
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; ++ i) {
		cin >> a[i];
		pref[i] += a[i];
		pref[i + 1] = pref[i];
	}
	cout << solve (0, n - 1) - (sum (0, n - 1) - solve (0, n - 1));
}