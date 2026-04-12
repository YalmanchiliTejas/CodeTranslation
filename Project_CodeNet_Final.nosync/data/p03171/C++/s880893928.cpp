#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <cstring>
//#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define de(x,y) cout<<#x<<" :"<<x<<y;
#define int long long
#define SZ(xx) ((int)xx.size())
#define lowbit(xx) (xx&(-xx))
#define pb push_back
typedef pair<int,int> pii;

const int maxn = 3e3+5;

int dp[maxn][maxn], arr[maxn];

int dfs(int l,int r,int level) {
	if (l == r) {
		if (level & 1) return dp[l][r] = arr[l];
		else return dp[l][r] = -arr[l];
	}	
	else if (dp[l][r] != -1) return dp[l][r];
	else {
		int fg = 0;
		if (level & 1) fg = 1;
		else fg = -1;
		int A = dfs(l + 1, r, level + 1) + arr[l] * fg, B = dfs(l, r - 1, level + 1) + arr[r] * fg;
		if (level & 1) dp[l][r] = max(A, B);
		else dp[l][r] = min(A, B); 
		return dp[l][r];
	}
}

main() {
	IOS
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		cin >> arr[i]; 
	cout << dfs(1, n, 1) << "\n";
}
