#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    vector<vector<ll>> dp(N + 1, vector<ll>(S + 1));
    for (int i = 0; i < N; ++i) {
        if (A[i] <= S)
            dp[i + 1][A[i]] += (i + 1);
        for (int j = 0; j <= S; ++j) {
            dp[i + 1][j] += dp[i][j];
            if (j > A[i])
                dp[i + 1][j] += dp[i][j - A[i]];
            dp[i + 1][j] %= MOD;
        }
    }

    ll ans = 0;
    for (int i = 0; i <= N; ++i)
        (ans += dp[i][S]) %= MOD;
    cout << ans << endl;
    return 0;
}
