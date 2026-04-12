#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mxN = 3010;
int N, a[mxN];
ll dp[mxN][mxN][2];
bool vis[mxN][mxN][2];

ll recursion(int l, int r, int t) {
	if (l > r)
		return 0;
	if (vis[l][r][t]) {
		return dp[l][r][t];
	}
	vis[l][r][t] = true;
	if (t == 0) {
		dp[l][r][t] = max(a[l] + recursion(l + 1, r, 1), a[r] + recursion(l, r - 1, 1));
	} else {
		dp[l][r][t] = min(-a[l] + recursion(l + 1, r, 0), -a[r] + recursion(l, r - 1, 0));
	}
	return dp[l][r][t];
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	ll answer = recursion(0, N - 1, 0);
	cout << answer;

	return 0;
}