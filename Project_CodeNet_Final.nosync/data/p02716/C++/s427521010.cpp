#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 200005;

int n, a[N];

ll dp[N][5];

ll f(int i, int left) {
	if(left < 0) return (ll)-1e18;
	if(i >= n) return left <= 1 ? 0 : (ll)-1e18;
	ll &ans = dp[i][left];
	if(~ans) return ans;
	ans = f(i + 1, left - 1);
	ans = max(ans, f(i + 2, left) + a[i]);
	return ans;
}

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", a + i);

	printf("%lld\n", f(0, n % 2 == 0 ? 1 : 2));
}
