#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e3, M=998244353;
int n, s, a[mxN];
ll dp[mxN+1][mxN+1], ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		memcpy(dp[i+1], dp[i], sizeof(dp[0]));
		//start a new sequence
		dp[i+1][a[i]]=(dp[i+1][a[i]]+i+1)%M;
		for(int j=0; j+a[i]<=s; ++j)
			dp[i+1][j+a[i]]=(dp[i+1][j+a[i]]+dp[i][j])%M;
		ans=(dp[i+1][s]+ans)%M;
	}
	cout << ans;
}
