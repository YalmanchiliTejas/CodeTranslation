#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
    }
    ll dp[N][N];
    for ( int h = 0; h < N; h++ ) {
        ll sg = (N-h) % 2 == 1 ? 1 : -1;
        for ( int i = 0; i + h < N; i++ ) {
            ll xy = 0;
            if ( h == 0 ) {
                xy = sg * A[i];
            } else {
                ll t1 = dp[i+1][i+h] + sg * A[i];
                ll t2 = dp[i][i+h-1] + sg * A[i+h];
                if ( ( t1 - t2 ) * sg >= 0 ) xy = t1;
                else xy = t2;
            }
            dp[i][i+h] = xy;
        }
    }
    return dp[0][N-1];
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}