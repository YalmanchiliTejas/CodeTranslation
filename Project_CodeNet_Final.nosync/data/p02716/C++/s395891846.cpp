#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
using matrix = vector<vector<uint>>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<vector<ll>>> dp(N + 3, vector<vector<ll>>(3, vector<ll>(2, -1e18)));
    dp[0][1][0] = 0;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        if (i & 1) {
            dp[i + 1][1][0] = max(dp[i][1][1], dp[i + 1][1][0]);
            dp[i + 1][1][1] = max(dp[i][0][0] + A, dp[i + 1][1][1]);
            dp[i + 1][0][0] = max(dp[i][0][0], dp[i + 1][0][0]);
            dp[i + 1][0][0] = max(dp[i][0][1], dp[i + 1][0][0]);

        } else {
            dp[i + 1][0][1] = max(dp[i][0][0] + A, dp[i + 1][0][1]);
            dp[i + 1][0][0] = max(dp[i][1][0], dp[i + 1][0][0]);
            dp[i + 1][0][0] = max(dp[i][1][1], dp[i + 1][0][0]);
            dp[i + 1][1][1] = max(dp[i][1][0] + A, dp[i + 1][1][1]);
        }
    }

    cout << max(dp[N][!(N & 1)][0], dp[N][!(N & 1)][1]) << endl;

    return 0;
}
