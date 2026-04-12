#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<LL> v(n+2);
	for(int i=1; i<=n; i++) cin >> v[i];

	vector<vector<LL> > dp(n+2, vector<LL>(n+2,0));

	for(int len=1; len<=n; len++)
		for(int i=1, j=len; j<=n; i++, j++)
			if(len%2 == n%2)
				dp[i][j] = max(dp[i+1][j]+v[i], dp[i][j-1]+v[j]);
			else
				dp[i][j] = min(dp[i+1][j]-v[i], dp[i][j-1]-v[j]);

	cout << dp[1][n] << "\n";
	return 0;
}