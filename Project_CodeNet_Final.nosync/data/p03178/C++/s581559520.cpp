#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

string k;
vector<int> a;
int d, n;
int dp[2][101];

void layer(int l) {
	for (int i = 0; i < d; i++) dp[l & 1][i] = 0;
	for (int i = 0; i < d; i++) {
		for (int put = 0; put < 10; put++) {
			dp[l & 1][(i + put) % d] += dp[l & 1 ^ 1][i];
			if (dp[l & 1][(i + put) % d] >= md)
				dp[l & 1][(i + put) % d] -= md;
		}
	}
	if (OO) {
		cout << "layer " << l << '\n';
		for (int i = 0; i < d; i++) {
			cout << "dsum " << i << ": " << dp[l & 1][i] << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> k >> d;
	n = k.size();
	a.resize(n);
	for (int i = 0; i < n; i++) {
		a[i] = k[i] - '0';
		if (i) a[i] += a[i - 1];
		a[i] %= d;
	}
	int ans = 0;
	for (int put = 0; put <= k.back() - '0'; put++)
		if (((n == 1 ? 0 : a[n - 2]) + put) % d == 0) ans++;
	dp[0][0] = 1;
	for (int i = 1; i < n; i++) {
		layer(i);
		for (int put = 0; put < k[n - 1 - i] - '0'; put++) {
			ans += dp[i & 1][((d - ((n - 2 - i < 0 ? 0 : a[n - 2 - i]) + put)) % d + d) % d];
			if (ans >= md)
				ans -= md;
		}
	}
	ans--; // counted 0
	if (ans < 0) ans += md;
	finish(ans);
}