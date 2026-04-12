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

const int INF = 1e9 + 7, M = 998244353;

int dp[3003][3003], a[3003];

signed main()
{
	IO_OP;
	
	int n, s, ans = 0;
	cin >> n >> s;
	for(int i=1;i<=n;i++) cin >> a[i];
	dp[0][0] = 0;
	for(int i=1;i<=n;i++) {
		dp[i][a[i]] += i ;
		for(int j=0;j<=s;j++) {
			dp[i][j] += dp[i-1][j];
			if(j >= a[i]) {
				dp[i][j] = (dp[i][j] + dp[i-1][j-a[i]]) % M;
			}
		}
		ans += dp[i][s];
	}
	cout << ans % M << endl;
}



