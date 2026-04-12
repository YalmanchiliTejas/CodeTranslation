#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3010;
int n;
ll a[N], dp[N][N][2];
bool vis[N][N][2];

ll rec(int l, int r, int t) {
	if (l > r)
		return 0;
	if (vis[l][r][t])
		return dp[l][r][t];
	vis[l][r][t] = true;
	if (t == 0) {
		return dp[l][r][t] = max(a[l] + rec(l + 1, r, 1), a[r] + rec(l, r - 1, 1));
	} else {
		return dp[l][r][t] = min(-a[l] + rec(l + 1, r, 0), -a[r] + rec(l, r - 1, 0));
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll answer = rec(0, n - 1, 0);
	cout << answer;

	return 0;
}