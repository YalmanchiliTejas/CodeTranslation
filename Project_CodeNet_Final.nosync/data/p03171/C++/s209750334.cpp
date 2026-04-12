#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using li = __int128;
using uli = unsigned __int128;

#define fi first
#define se second

template <typename T> void s_min(T& a, T b) {
	if (a > b) a = b;
}

template <typename T> void s_max(T& a, T b) {
	if (a < b) a = b;
}

const int MAXN = 3005;
int N, a[MAXN];
ll dp[MAXN][MAXN][2];
bool vis[MAXN][MAXN][2];

ll rec(int l, int r, int t) {
	if (l > r) return 0;
	if (vis[l][r][t]) return dp[l][r][t];
	vis[l][r][t] = true;
	if (t == 0) return dp[l][r][t] = max(a[l] + rec(l + 1, r, 1), a[r] + rec(l, r - 1, 1));
	else return dp[l][r][t] = min(-a[l] + rec(l + 1, r, 0), -a[r] + rec(l, r - 1, 0));
}

int main() {
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	memset(vis, false, sizeof(vis));
	ll ans = rec(0, N - 1, 0);
	cout << ans;

	return 0;
}