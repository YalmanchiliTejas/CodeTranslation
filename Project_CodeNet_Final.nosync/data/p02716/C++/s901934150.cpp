#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;
const ll INF = 1E+16;

ll dp[200005][3];

ll f(ll a, ll v) {
    if (a==-INF) return -INF;
    else return a+v;
}

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans;

    if (n==2) {
        ans = max(a[0], a[1]);
        cout << ans << endl;
        return 0;
    }
    

    dp[0][0] = a[0];
    
    dp[1][1] = a[1];
    dp[2][0] = a[0] + a[2];
    dp[2][2] = a[2];

    rep(i, n) rep(j, 3) {
        if (i<=2) continue;
        if (j==0) {
            if (i%2==1) continue;
            dp[i][j] = dp[i-2][j]+a[i];
        }
        if (j==1) {
            if (i%2==0) continue;
            dp[i][j] = max(dp[i-2][j]+a[i], dp[i-3][j-1]+a[i]);
        }
        if (j==2) {
            if (i%2==1) continue;
            dp[i][j] = max(dp[i-4][j-2]+a[i], max(dp[i-2][j]+a[i], dp[i-3][j-1]+a[i]));
        }
        //cout << i << " " << j << " " << dp[i][j] << endl;
    }
    
    
    if (n%2==0) {
        ans = max(dp[n-1][1], dp[n-2][0]);
    }
    else {
        ans = max(dp[n-3][0], max(dp[n-1][2], dp[n-2][1]));
    }
    
    cout << ans << endl;
    return 0;
}
