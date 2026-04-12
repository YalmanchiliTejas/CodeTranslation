#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e18;

ll dp[200005][4];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n+1)rep(j,n%2+2) dp[i][j] = -INF;
    dp[0][0] = 0;
    rep(i,n){
        rep(j,n%2+2){
            chmax(dp[i+1][j+1], dp[i][j]);
            ll tmp = dp[i][j];
            if((i+j)%2 == 0) tmp += a[i];
            chmax(dp[i+1][j], tmp);
        }
    }
    ll ans = dp[n][n%2+1];
    cout << ans << endl;
    return 0;
}
