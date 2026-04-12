#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
const ll INF=1e18+5;
int main(){
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vl a(n);
    rep (i, n) cin >> a[i];
 
    int m;
    if (n % 2 == 0) m = 1;
    else m = 2;
 
    vvl dp(n + 10, vl(m + 1, -INF));
    for (int i = 0; i <= m; i++) {
        dp[i][i] = 0;
    }
 
    rep (i, n) {
        rep (j, m + 1) {
            if (dp[i][j] == -INF) continue;
            chmax(dp[i + 2][j], dp[i][j] + a[i]);
            if (j + 1 <= m) {
                chmax(dp[i + 3][j + 1], dp[i][j] + a[i]);
            }
            if (j + 2 <= m) {
                chmax(dp[i + 4][j + 2], dp[i][j] + a[i]);
            }
        }
    }
 
    ll ans = -INF;
    int mi;
    if (n % 2 == 0) mi = 0;
    else mi = 1;
    for (int i = n; i <= n + 5; i++) {
        for (int j = mi; j <= m; j++) {
            chmax(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}