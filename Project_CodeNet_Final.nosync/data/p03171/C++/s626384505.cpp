#include<bits/stdc++.h>
using namespace std;
const int N = 3e3+3;
long long dp[N][N][2];
int a[N];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		dp[i][i][0] = dp[i][i][1] = a[i];
	}
	for(int len = 1; len < n; ++len)
		for(int st = 0; (st+len) < n; ++st){
			int ed = st + len;
			dp[st][ed][0] = max(a[st] - dp[st+1][ed][1], a[ed] - dp[st][ed-1][1]);
			dp[st][ed][1] = max(a[st] - dp[st+1][ed][0], a[ed] - dp[st][ed-1][0]);
		}
	cout << dp[0][n-1][0];
	return 0;
}
