#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 3005;
ll dp[N][N], s[N], a[N];

template <class X, class Y>
bool chkmax(X &a, const Y &b){
	return a < b ? a = b, 1 : 0;
}

ll sum(int i, int j){
	return s[j] - s[i - 1];
} 

ll calc(int i, int j){
	if (dp[i][j] != -1) return dp[i][j];
	if (i == j) return dp[i][j] = a[i];
	dp[i][j] = a[i] + sum(i + 1, j) - calc(i + 1, j);
	chkmax(dp[i][j], a[j] + sum(i, j - 1) - calc(i, j - 1));
	return dp[i][j];
}

int main(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i]; s[i] = s[i - 1] + a[i];
	}
	memset(dp, -1, sizeof dp);
	cout << calc(1, n) * 2 - s[n] << '\n';
}