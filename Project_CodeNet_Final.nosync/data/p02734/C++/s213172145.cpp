#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()

const int MOD = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

const int MAXN = 3010;
int n, s;
int a[MAXN];
int pows[MAXN];
int dp[MAXN];

void solve() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for (int i = 0; i < MAXN; i++)
		dp[i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int w = s - a[i]; w >= 1; w--) {
			int nxt = w + a[i];
			dp[nxt] = add(dp[nxt], dp[w]);
		}
		int nxt = a[i];
		if (nxt <= s) dp[nxt] = add(dp[nxt], i);
		ans = add(ans, dp[s]);
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
	int t;
	//cin >> t;
	t = 1;
	while (t--)
		solve();
	return 0;
}