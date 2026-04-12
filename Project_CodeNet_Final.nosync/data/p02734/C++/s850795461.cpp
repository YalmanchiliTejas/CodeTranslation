#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()
#define int ll

#define pt pair<int, int>
#define x first
#define y second

const int MOD = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) a += MOD;
	return a;
}

int mul(int a, int b) {
	return (ll) a * b % MOD;
}

const int MAXN = 3010;
int n, s;
int a[MAXN];
int pows[MAXN];

void precalc() {
	pows[0] = 1;
	for (int i = 1; i < MAXN; i++)
		pows[i] = mul(2, pows[i - 1]);
}

int dp[MAXN];

void solve() {
	precalc();
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			int len = r - l + 1;
			ans = add(ans, sub(pows[len], 1));
		}
	}
	//cout << ans << endl;
	for (int i = 0; i < MAXN; i++)
		dp[i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int w = s + 1; w >= 1; w--) {
			int nxt = w + a[i];
			if (nxt > s + 1) nxt = s + 1;
			dp[nxt] = add(dp[nxt], dp[w]);
		}
		int nxt = a[i];
		if (nxt > s + 1) nxt = s + 1;
		dp[nxt] = add(dp[nxt], i);
		for (int w = 1; w <= s + 1; w++) {
			if (w == s) continue;
			ans = sub(ans, dp[w]);
		}
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