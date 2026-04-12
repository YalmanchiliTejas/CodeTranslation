#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
double const PI = acos(-1);
int const N = 3000 + 10;
int a[N], n;
ll dp[N][N];

ll solve(int l, int r){
	if (l > r)
		return 0;
	ll &dp = ::dp[l][r];
	if (dp != -1)
		return dp;
	if ((n - r + l) & 1)
		dp = max(solve(l + 1, r) + a[l], solve(l, r - 1) + a[r]);
	else
		dp = min(solve(l + 1, r) - a[l], solve(l, r - 1) - a[r]);
	return dp;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	cout << solve(0, n - 1);
	return 0;
}
