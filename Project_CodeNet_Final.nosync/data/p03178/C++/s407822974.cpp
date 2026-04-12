#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pdd = pair<double, double>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string K;
    int D;
    cin >> K >> D;

    int N = K.length();
    static int dp[10001][100][2];
    dp[0][0][1] = 1;
    for (int i = 0; i < N; ++i) {
        int num = K[i] - '0';
        for (int j = 0; j < D; ++j) {
            for (int k = 0; k < 10; ++k) {
                int nxt = (j + k) % D;
                (dp[i + 1][nxt][0] += dp[i][j][0]) %= MOD;
                if (k < num)
                    (dp[i + 1][nxt][0] += dp[i][j][1]) %= MOD;
                else if (k == num)
                    (dp[i + 1][nxt][1] += dp[i][j][1]) %= MOD;
            }
        }
    }

    int ans = (dp[N][0][0] + dp[N][0][1] - 1) % MOD;
    cout << (ans < 0 ? ans + MOD : ans) << endl;

    return 0;
}
