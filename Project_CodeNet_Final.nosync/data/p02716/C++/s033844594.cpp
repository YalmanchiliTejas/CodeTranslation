#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;
const ll mod = 1e9 + 7;
map<int, ll>dp[N];
int n;
ll a[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%lld", &a[i]);
	dp[1][1] = a[1]; dp[1][0] = 0;
	dp[2][0] = 0; dp[2][1] = max(a[1], a[2]);
	for (int i = 3; i <= n; i++) {
		int L = n / 2 - (int)ceil(0.5*(n - i + 1)), R = (int)ceil(0.5*i);
		for (int j = L; j <= R; j++) {
			if (!dp[i - 1].count(j) && !dp[i - 2].count(j - 1))continue;
			else if (dp[i - 1].count(j) && !dp[i - 2].count(j - 1))dp[i][j] = dp[i - 1][j];
			else if (dp[i - 2].count(j - 1) && !dp[i - 1].count(j))dp[i][j] = dp[i - 2][j - 1] + a[i];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + a[i]);
		}
	}
	printf("%lld\n", dp[n][n / 2]);
	return 0;
}