#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }

using Graph = vector<vector<int>>;
using P = pair<int, int>;
using Tuple = tuple<int, int, int>;


int main() {
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    // dpテーブルの用意
    // dp[i][0] = a[0]~a[i]までからi/2個をとるときの最大値
    // dp[i][1] = a[0]~a[i]までから(i+1)/2個をとるときの最大値

    // 初期値は十分小さな値にしておくこと
    // a[i]が全て `-10^9` だとしたら、-10^9 * 10^5(nの最大値)より小さい値でないとだめ
    vector<vector<ll>> dp(n, vector<ll>(2, -1e17));
    // 初期値を埋めておく
    dp[0][0] = 0;
    dp[0][1] = a[0];
    dp[1][0] = max(a[0], a[1]);
    dp[1][1] = max(a[0], a[1]);

    // dpテーブルを埋めていく
    for(int i=2; i<n; i++) {
        // i番目を選んで, i/2が選ばれている状態
        dp[i][0] = max(dp[i][0], dp[i-2][0] + a[i]);
        // i番目を選ばずに, i/2が選ばれている状態
        dp[i][0] = max(dp[i][0], dp[i-1][1]);

        if(i%2==0) {
            // 奇数の場合 ... i+1が実際の番号...
            // i番目を選んで, (i+1)/2個選ばれてる状態
            dp[i][1] = max(dp[i][1], dp[i-2][1] + a[i]);
        } else {
            // 偶数の場合はi/2 == (i+1)/2
            // i番目を選んで, (i+1)/2個選ばれてる状態(偶数個の場合はi/2の状態と同じ)
            dp[i][1] = max(dp[i][1], dp[i][0]);
        }

        // iを選ばず, (i+1)/2個選ばれてる状態は存在しない
    }

    // 奇数でも偶数でもi/2を選んでる状態を出せばいい(nが奇数の時に(i+1)/2を選んだ状態出したら取りすぎになる
    cout << dp[n-1][0] << endl;

    return 0;
}