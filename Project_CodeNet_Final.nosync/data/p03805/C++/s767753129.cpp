#include <iostream>
using namespace std;

bool connected[10][10];
int dp[1 << 10][10];

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        connected[a][b] = connected[b][a] = true;
    }
    dp[1][0] = 1;
    for (int mask = 1; mask < (1 << N); mask++) {
        for (int tail = 0; tail < N; tail++) {
            if (dp[mask][tail] == 0) continue;

            for (int to = 0; to < N; to++) {
                if (!connected[tail][to] || ((mask >> to) & 1)) continue;

                dp[mask | (1 << to)][to] += dp[mask][tail];
            }
        }
    }

    int ans = 0;
    for (int tail = 0; tail < N; tail++) {
        ans += dp[(1 << N) - 1][tail];
    }
    cout << ans << endl;

    return 0;
}
