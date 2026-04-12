#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define int long long
using namespace std;
const int INF = 2e18;
const int MOD = 1e9 + 7;
const int MB = 60;

int dp[3000][3000];
int a[3000];
int n;

int rec(int l, int r) {
	if (l == r) return n % 2 ? a[l] : -a[l];
	if (dp[l][r] != INF) return dp[l][r];
	if ((r - l + 1) % 2 == n % 2) {
		dp[l][r] = max(a[l] + rec(l + 1, r), a[r] + rec(l, r - 1));
	}
	else {
		dp[l][r] = min(-a[l] + rec(l + 1, r), -a[r] + rec(l, r - 1));
	}
	return dp[l][r];
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = INF;
		}
	}
	cout << rec(0, n - 1);
}

signed main() {
	/*
	freopen("search.in", "r", stdin);
	freopen("search.out", "w", stdout);
	*/
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed;
	cout.precision(12);
	solve();
}
