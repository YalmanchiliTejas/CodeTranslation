#include <bits/stdc++.h>
#define int long long
#define N 3011

using namespace std;

int n, arr[N], dp[2][N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	for(int k=0; k<n; k++) {
		for(int i=0; i+k<n; i++) {
			for(int x=0; x<2; x++) {
				if(k == 0) dp[x][i][i+k] = (x ? -arr[i] : arr[i]);
				else {
					if(x == 0) dp[x][i][i+k] = max(dp[1-x][i+1][i+k] + arr[i], dp[1-x][i][i+k-1] + arr[i+k]);
					else dp[x][i][i+k] = min(dp[1-x][i+1][i+k] - arr[i], dp[1-x][i][i+k-1] - arr[i+k]);
				}
			}
		}
	}
	cout << dp[0][0][n-1] << endl;
	return 0;
}