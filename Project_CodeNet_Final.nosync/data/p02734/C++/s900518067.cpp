#include <bits/stdc++.h>
#define f(i,n) for(int i=0;i<n;i++)
#define P pair<int,int>
#define F first
#define S second
#define int long long
#define mod 1000000007
#define mmod 998244353
#define all(v) v.begin(), v.end()
#define INF LLONG_MAX/3
using namespace std;
int mypow(int a, int b, int c) {
	if (b == 0)return 1;
	if (b % 2)return mypow(a, b - 1, c)*a%c;
	int z = mypow(a, b / 2, c);
	return z * z%c;
}
int dp[3010][3010];
int c[3010];
signed main() {
	int a, b;
	cin >> a >> b;
	f(i, a)cin >> c[i];
	dp[0][0] = 1;
	f(i, a) {
		f(j, b+1) {
			if (j == 0)dp[i + 1][0] = (dp[i][0] + 1)%mmod;
			else if (j >= c[i]) {
				dp[i + 1][j] = (dp[i][j] + dp[i][j - c[i]])%mmod;
			}
			else dp[i + 1][j] = dp[i][j];
		}
	}
	int ans = 0;
	f(i, a) {
		ans += dp[i + 1][b];
	}
	cout << ans%mmod << endl;
}