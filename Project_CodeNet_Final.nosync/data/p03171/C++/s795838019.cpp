#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[4096][4096];
int a[4096], vis[4096][4096];

long long calc(int l, int r, int turn) {
    auto &y = dp[l][r];
    if(vis[l][r]) return y;
    vis[l][r] = 1;
    if(l == r) return y = (turn == 0 ? a[l] : -a[l]);
    if(turn == 0) {
        return y=max(a[l]+calc(l+1, r, 1), a[r]+calc(l, r-1, 1));
    }
    else {
        return y=min(calc(l+1, r, 0)-a[l], calc(l, r-1, 0)-a[r]);
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
	cin >> n;
	for(int i=1; i<=n; ++i) {
	    cin >> a[i];
    }
	cout << calc(1, n, 0) << endl;
	return 0;
}
