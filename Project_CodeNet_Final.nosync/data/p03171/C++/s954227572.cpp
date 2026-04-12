#pragma GCC optimize "03"
#include "bits/stdc++.h"
using namespace std;
 
#define int long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 3e3 + 5;
const int mod = 1e9 + 7;
const int inf = 1e9 + 9;

int dp[N][N][2], a[N];

int rec(int l, int r, int c){
	if(l > r)
		return 0;
	if(dp[l][r][c] != -1)
		return dp[l][r][c];
	if(c == 0)
		dp[l][r][c] = max(a[l] + rec(l+1, r, 1), a[r] + rec(l, r-1, 1));
	else
		dp[l][r][c] = min(-a[l] + rec(l+1, r, 0), -a[r] + rec(l, r-1, 0));
	return dp[l][r][c];
}
 
signed main() {
	IOS;
	#ifdef LOCAL
		freopen("input.txt","r", stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n;	cin >> n;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			dp[i][j][0] = dp[i][j][1] = -1;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	cout << rec(1, n, 0);
	return 0;
}