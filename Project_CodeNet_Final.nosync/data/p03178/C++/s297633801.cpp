#include <iostream>
#include <string>
using namespace std;

const int mod = 1000000007;

// K の桁数
int N;
int D;

// K の上から n 桁目 (0-indexed)
int K[10009];

int dp[10009][2][109];

int main() {
    // K は文字列として受け取る
    string s;
    cin >> s;
    N = s.size();
    for(int i = 0; i < N; i++)
        K[i] = s[i] - '0';

    cin >> D;

    dp[0][0][0] = 1;

    for(int i = 0; i < N; i++) {
        for(int d = 0; d < D; d++) {
            // j = 1 -> j = 1
            for(int k = 0; k <= 9; k++)
                if((dp[i + 1][1][(d + k) % D] += dp[i][1][d]) >= mod)
                    dp[i + 1][1][(d + k) % D] -= mod;
            // j = 0 -> j = 1
            for(int k = 0; k < K[i]; k++)
                if((dp[i + 1][1][(d + k) % D] += dp[i][0][d]) >= mod)
                    dp[i + 1][1][(d + k) % D] -= mod;
            // j = 0 -> j = 0
            if((dp[i + 1][0][(d + K[i]) % D] += dp[i][0][d]) >= mod)
                dp[i + 1][0][(d + K[i]) % D] -= mod;
        }
    }

    // 0 が含まれているので、1 引く
    int res = dp[N][0][0] + dp[N][1][0] - 1;
    if(res >= mod) res -= mod;
    if(res < 0) res += mod;
    cout << res << endl;

    return 0;
}
