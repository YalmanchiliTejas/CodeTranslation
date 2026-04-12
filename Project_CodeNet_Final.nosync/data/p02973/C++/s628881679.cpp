#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000 + 10;
int n, a[N], dp[N], b[N], m;
int c[N];

void upd(int x, int v) {
	for(; x <= m; x += (x & -x)) c[x] = max(c[x], v);
}
int query(int x) {
	int ans = 0;
	for(; x; x -= (x & -x)) ans = max(ans, c[x]);
	return ans;
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) a[i] = 1e9 - a[i];
	for(int i = 1; i <= n; i++) b[i] = a[i];
	sort(b + 1, b + n + 1);
	m = unique(b + 1, b + n + 1) - (b + 1);
	for(int i = 1; i <= n; i++) 
		a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b; 
	for(int i = 1; i <= n; i++) {
		dp[i] = query(a[i]) + 1;
		upd(a[i], dp[i]);
	}
	cout << *max_element(dp + 1, dp + n + 1);
	return 0;
}
