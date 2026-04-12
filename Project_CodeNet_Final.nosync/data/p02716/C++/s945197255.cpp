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
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(3, vector<ll>(2, -1e18)));
    dp[0][1][0] = 0;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (dp[i][j][k] <= -1e18)
                    continue;
                int nxt = j - (i & 1);
                if (nxt >= 0)
                    dp[i + 1][nxt][0] = max(dp[i][j][k], dp[i + 1][nxt][0]);
                nxt++;
                if (k == 0 && nxt < 3)
                    dp[i + 1][nxt][1] = max(dp[i][j][k] + A, dp[i + 1][nxt][1]);
            }
        }
    }

    cout << max(dp[N][1][0], dp[N][1][1]) << endl;

    return 0;
}
