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
    // dp[i][0] = a[0]~a[i]までから最小限をとるときの最大値
    // dp[i][1] = a[0]~a[i]までから最大限をとるときの最大値

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
        // i番目を選んで, 最小限が選ばれている状態
        dp[i][0] = max(dp[i][0], dp[i-2][0] + a[i]);
        // i番目を選ばずに, 最小限が選ばれている状態
        dp[i][0] = max(dp[i][0], dp[i-1][1]);

        // 最大限を選ぶ状態は偶奇で別れる
        if(i%2==0) {
            // 奇数の場合は、i番目を選ばないと絶対に最大限は選べない
            // i番目を選んで, 最大限選ばれてる状態
            dp[i][1] = max(dp[i][1], dp[i-2][1] + a[i]);
        } else {
            // 偶数の場合は, i番目を選ぶ時と選ばないときの2パターンがある
            dp[i][1] = max(dp[i][1], dp[i-2][1] + a[i]);
            dp[i][1] = max(dp[i][1], dp[i-1][1]);
        }
    }

    // 奇数でも偶数でも最小限を選んでる状態を出せばいい(nが奇数の時に最大限だと取りすぎになる
    cout << dp[n-1][0] << endl;

    return 0;
}