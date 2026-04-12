#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    string S;
    int K;
    cin >> S >> K;
    int N = S.size();

    vec<vec<vec<ll>>> dp(2, vec<vec<ll>>(K + 2, vec<ll>(N + 1, 0)));
    dp[0][0][0] = 1;
    dp[1][0][0] = 0;
    rep(i, N) rep(k, K + 1) {
        int n = S[i] - '0';
        if (n == 0) {
            dp[0][k][i + 1] += dp[0][k][i];
            dp[1][k + 1][i + 1] += dp[1][k][i] * 9;
            dp[1][k][i + 1] += dp[1][k][i];
        } else {
            dp[0][k+1][i+1] += dp[0][k][i];
            dp[1][k+1][i+1] += dp[0][k][i]*(n-1);
            dp[1][k+1][i+1] += dp[1][k][i]*9;
            dp[1][k][i+1] += dp[0][k][i] + dp[1][k][i];
        }
    }
    cout << dp[0][K][N] + dp[1][K][N] << endl;
}
