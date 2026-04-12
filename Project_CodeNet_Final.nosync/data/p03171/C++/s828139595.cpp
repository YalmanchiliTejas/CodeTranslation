#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define ppp pop_back
#define pii pair<int,int>
#define fi first
#define se second

const int N = 3005;

int a[N];
ll dp[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++) {
		if (n & 1) dp[i][i] = a[i];
		else dp[i][i] = -a[i];
	}
	for (int s=2; s<=n; s++) {
		for (int i=1; i<=n-s+1; i++) {
			if ((n - s + 1) & 1) {
				dp[i][i+s-1] = max(dp[i][i+s-2] + a[i+s-1], dp[i+1][i+s-1] + a[i]);
			}
			else {
				dp[i][i+s-1] = min(dp[i][i+s-2] - a[i+s-1], dp[i+1][i+s-1] - a[i]);
			}
		}
	}
	cout << dp[1][n] << "\n";
    return 0;
}
