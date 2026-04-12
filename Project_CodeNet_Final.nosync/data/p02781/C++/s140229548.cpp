#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int dp[105][4][2];

int main() {
    string upper;
    cin >> upper;
    int N = upper.size();
    int K;
    cin >> K;
    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 2; k++) {
                int digit_num = upper[i] - '0';
                for (int d = 0; d < 10; d++) {
                    int next_i = i + 1, next_j = j, next_k = k;
                    if (d != 0) {
                        next_j++;
                    }
                    if (next_j > K) {
                        continue;
                    }
                    if (k == 0) {
                        if (d > digit_num) {
                            continue;
                        }
                        if (d < digit_num) {
                            next_k = 1;
                        }
                    }
                    dp[next_i][next_j][next_k] += dp[i][j][k];
                }
            }
        }
    }
    int ans = dp[N][K][0] + dp[N][K][1];
    cout << ans << "\n";
    return 0;
}