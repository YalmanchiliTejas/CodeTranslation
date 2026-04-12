#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define ld long double
#define ft first
#define sd second
using namespace std;

const int N = 3e3 + 9;
ll a[N];
ll dp[N][N][2];

ll solve(int l, int r, bool turn) {
    if(l > r) return 0;
    ll &ret = dp[l][r][turn];
    if(ret != -1) return ret;
    if(turn) {
        ret = min(solve(l+1, r, turn^1)-a[l], solve(l, r-1, turn^1)-a[r]);

    } else {    
        ret = max(solve(l+1, r, turn^1)+a[l], solve(l, r-1, turn^1)+a[r]);
        
    }
    return ret;
}

signed main() {

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << solve(1, n, 0);
    
    return 0;
}