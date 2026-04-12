#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e18 + 7, N = 2e5 + 7;

int dp[N][3], a[N];

int take(int i, int j) {
	return (i + 1 + 1) / 2 - j;
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	dp[0][0] = a[0], dp[0][1] = 0, dp[0][2] = -INF;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			dp[i][j] = -INF;
			int want = take(i, j);
			for(int k = 0; k < 3; k++) {
				if(take(i-1, k) == want) dp[i][j] = max(dp[i][j], dp[i-1][k]);
			}
			if(i-2 >= 0) {
				for(int k = 0; k < 3; k++) {
					if(take(i-2, k) + 1 == want) dp[i][j] = max(dp[i][j], dp[i-2][k] + a[i]);
				}
			} else {
				if(want == 1) dp[i][j] = max(dp[i][j], a[i]);
			}
			// cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
		}
	}

	cout << dp[n-1][n & 1] << endl;
}



