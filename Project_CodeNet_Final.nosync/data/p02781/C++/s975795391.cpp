#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string N;
    int K, Nlen;
    cin >> N >> K;
    Nlen = N.length();

    static ll dp[103][6][2];
    dp[0][0][0] = 1;

    for (int i = 0; i < Nlen; ++i) {
        int num = N[i] - '0';
        for (int j = 0; j <= K; ++j) {
            dp[i + 1][j + (num != 0)][0] += dp[i][j][0];
            for (int k = 0; k < 10; ++k) {
                if (k < num)
                    dp[i + 1][j + (k != 0)][1] += dp[i][j][0];
                dp[i + 1][j + (k != 0)][1] += dp[i][j][1];
            }
        }
    }

    cout << dp[Nlen][K][0] + dp[Nlen][K][1] << endl;

    return 0;
}
