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

//ll dp[200005][2][3];

int main() {
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<ll>> dp(n, vector<ll>(2, -1LL<<60));
    dp[0][0] = 0;
    dp[0][1] = a[0];
    dp[1][0] = max(a[0], a[1]);
    dp[1][1] = max(a[0], a[1]);

    for(int i=2; i<n; i++) {
        // iを選んで, i/2の状態
        dp[i][0] = max(dp[i][0], dp[i-2][0] + a[i]);
        // iをえらばず, i/2の状態
        dp[i][0] = max(dp[i][0], dp[i-1][1]);

        if(i%2==0) {
            // iを選んで, (i+1)/2個選ばれてる状態
            dp[i][1] = max(dp[i][1], dp[i-2][1] + a[i]);
        } else {
            // iを選んで, (i+1)/2個選ばれてる状態(偶数個の場合はi/2の状態と同じ)
            dp[i][1] = max(dp[i][1], dp[i][0]);
        }
        // iを選ばず, (i+1)/2個選ばれてる状態(ありえないはず)
//        cout << dp[i][0] << endl;
//        cout << dp[i][1] << endl;
    }

    if(n%2==0) {
        cout << dp[n-1][0] << endl;
    } else {
        cout << dp[n-1][0] << endl;
    }

    return 0;
}