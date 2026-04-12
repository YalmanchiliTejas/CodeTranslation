#include <bits/stdc++.h>
using namespace std;

using LL = long long;

LL a[3030] = {};
LL dp[2][3030][3030] = {};
bool vis[2][3030][3030] = {};

LL rec(int l, int r, int t) {
	if(l>r) return 0;
	if(vis[t][l][r]) return dp[t][l][r];
	vis[t][l][r] = true;
	LL ret;
	if(t == 0) {
		ret = max(rec(l+1, r, t^1) + a[l], rec(l, r-1, t^1) + a[r]);
	} else {
		ret = min(rec(l+1, r, t^1) - a[l], rec(l, r-1, t^1) - a[r]);
	}
	dp[t][l][r] = ret;
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	// cout << n << endl;
	for(int i=0;i<n;i++) {
		scanf("%d", &a[i]);
	}
	cout << rec(0, n-1, 0);
}