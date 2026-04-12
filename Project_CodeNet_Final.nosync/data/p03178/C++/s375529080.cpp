#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int kModulo = 1000 * 1000 * 1000 + 7;

int main() {
    ios::sync_with_stdio(false);

    string K; cin >> K;
    int D; cin >> D;

    vector< vector< vector<int> > > dp(2, vector<vector<int>>(K.size() + 1, vector<int>(D, 0)));
    dp[1][0][0] = 1;
    for (int i = 0; i < int(K.size()); ++i) {
        int digit = K[i] - '0';
        for (int rest = 0; rest < D; ++rest) {
            for (int add = 0; add < 10; ++add) {
                int next = (rest + add) % D;
                dp[0][i + 1][next] = (dp[0][i + 1][next] + dp[0][i][rest]) % kModulo;
                if (add < digit)
                    dp[0][i + 1][next] = (dp[0][i + 1][next] + dp[1][i][rest]) % kModulo;
                if (add == digit)
                    dp[1][i + 1][next] = (dp[1][i + 1][next] + dp[1][i][rest]) % kModulo;
            }
        }
    }

    int answer = (dp[0][K.size()][0] + dp[1][K.size()][0] - 1) % kModulo;
    if (answer < 0)
        answer += kModulo;
    cout << answer << "\n";
}
