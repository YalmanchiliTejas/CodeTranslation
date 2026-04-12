#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 200005;
map<int,int> dp[maxn];
int a[maxn];
int n;

int recur(int pos, int took) {
    if (dp[pos].count(took) != 0) return dp[pos][took];
    if (took == n/2) return 0;
    if (pos >= n) return -1e18;
    int rem = ceil((double)(n-pos)/2);
    if (took+rem < n/2) return -1e18;
    int res = max(recur(pos+1, took), recur(pos+2, took+1)+a[pos]);
    dp[pos][took] = res;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int res = recur(0,0);
    cout << res << '\n';
}
/*

 */