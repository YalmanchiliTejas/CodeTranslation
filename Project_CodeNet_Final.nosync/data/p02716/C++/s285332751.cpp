#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
//#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
//#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
//#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
//template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
//template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }
//
//using Graph = vector<vector<int>>;
//using P = pair<int, int>;
//using Tuple = tuple<int, int, int>;

ll dp[200005][2][3];


int main() {
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    rep(i, n+1) rep(j, 2) rep(k, 3) dp[i][j][k] = -1LL<<60;
    dp[0][1][0]=0;

    rep(i, n) rep(j, 2) rep(k,3) {
        if(k+j < 3) dp[i+1][1][k+j] = max(dp[i+1][1][k+j], dp[i][j][k]);
        if(j==1) dp[i+1][0][k] = max(dp[i+1][0][k], dp[i][j][k]+a[i]);
    }

    if(n%2==0) cout << max(dp[n][1][0], dp[n][0][1]) << endl;
    else cout << max(dp[n][0][2], dp[n][1][1]) << endl;


    return 0;
}
