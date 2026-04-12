#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    int n;
    cin >> n;
    vector<ll> s(n);
    rep(i, n) cin >> s[i];
    vector<vector<ll>> dp(n);
    dp[0].resize(n);
    rep(j, n) dp[0][j] = 0;
    ll ans = 0;
    
    rep(i, n) {
        if (i==0) continue;
        ll z = (n-2)/i;
        dp[i].resize(z+1);
        rep(j, z+1) {
            if (j==0) continue;
            if (((n-1)%j)==0 && n-1-i*j<=i*j) continue;
            if (n-1-i*j<=j) continue;
            dp[i][j] = dp[i-1][j] + s[n-1-i*j] + s[i*j];
            chmax(ans, dp[i][j]);
        }
    }
    
    
    
    cout << ans << endl;
    return 0;
}
