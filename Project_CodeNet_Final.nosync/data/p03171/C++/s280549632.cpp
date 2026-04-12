#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	vi a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i], b[i] = b[i - 1] + a[i];
	V<vi> dp(n + 2, vi(n + 2));
	for(int r = 1; r <= n; r++) {
		for(int l = r; l >= 1; l--) {
			dp[l][r] = max(dp[l][r], b[r] - b[l] - dp[l + 1][r] + a[l]);
			dp[l][r] = max(dp[l][r], b[r-1] - b[l-1] - dp[l][r-1] + a[r]);
		}
	}
	cout << 2 * dp[1][n] - b[n] << endl;

}

