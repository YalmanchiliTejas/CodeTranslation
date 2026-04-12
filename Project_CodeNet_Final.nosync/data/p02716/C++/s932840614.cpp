#include <bits/stdc++.h>
#define ll long long
using namespace std;
const long long mod = 1e9+7;
long long power(long long a, long long b, long long m = mod) {
    if(b < 0) {
        return power(power(a, -b), mod-2);
    }
    long long x = 1;
    while(b) {
        if(b & 1) {
            x = 1ll * x * a % m;
        }
        a = 1ll * a * a % m;
        b /= 2;
    }
    return x;
}
const int N = 3e5+9;
vector<ll> a;
int n;
vector<vector<ll>> memo;
const int off = 4;
const ll inf = 1e18;
ll solve(int ind, int taken) {
    if(ind >= n) {
        if(taken == n/2) return 0;
        return -inf;
    }
    if(ind-2*taken > 3 || ind-2*taken < -3) return -inf;
    ll &ret = memo[ind][ind-2*taken+off];
    if(ret != -inf-1) return ret;
    return ret = max(solve(ind+1, taken), a[ind]+solve(ind+2, taken+1));
}
signed main() {  
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memo.assign(n+2, vector<ll>(11, -inf-1));
    cout << solve(0, 0) << "\n";
    // f[i][j] = f[i-2][j], f[i-3][j+1], f[]





    return 0;
    
}