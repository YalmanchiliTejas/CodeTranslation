// O(2^N * N^2)

#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)
#define FOR(i,a,b) for (int i=(a);i<(b);++i)

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> g(N, vector<bool>(N, false));
    REP(_, M) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a][b] = true;
        g[b][a] = true;
    }

    vector<vector<int>> dp(1 << (N - 1), vector<int>(N, 0));
    dp[0][0] = 1;
    FOR(bit, 1, 1 << (N - 1)) FOR(u, 1, N) {
        //cout << "dp[" << bitset<7>(bit) << "][" << u << "] start" << endl;
        if (bit & 1 << (u - 1)) {
            REP(v, N) {
                if (v != u && (v == 0 || (bit & 1 << (v - 1))) && g[v][u]) {
                    int bit_prev = bit ^ (1 << (u - 1));
                    //cout << "+= dp[" << bitset<7>(bit_prev) << "][" << v << "] = " << dp[bit_prev][v] << endl;
                    dp[bit][u] += dp[bit_prev][v];
                }
            }
        }
        //cout << "dp[" << bitset<7>(bit) << "][" << u << "] = " << dp[bit][u] << endl;
    }
    int result = 0;
    FOR(u, 1, N) {
        result += dp[(1 << (N - 1)) - 1][u];
    }
    cout << result << endl;
    return 0;
}