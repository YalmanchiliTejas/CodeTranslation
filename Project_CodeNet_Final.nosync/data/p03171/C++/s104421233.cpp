#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> a(N);
    Rep (i, N) cin >> a[i];

    vector<vector<ll>> dp(N+1, vector<ll>(N+1));
    Rep (i, N+1) dp[i][i] = 0;

    for (ll len = 1; len <= N; len++) {
        for (ll i = 0; i + len <= N; i++) {
            ll j = i + len;
            if ((N-len) % 2 == 0) {
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);
            } else {
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);
            }
        }

    }
    cout << dp[0][N] << "\n";
}