#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string N;
    int K;
    cin >> N >> K;

    int ni = N.size();
    int nj = K + 1;
    int nk = 2;
    int dp[ni+1][nj][nk] = {};

    dp[0][0][1] = 1;
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nj; j++) {
            for (int k = 0; k < nk; k++) {
                int next_num = N[i] - '0';
                int max_num = k ? next_num : 9;
                if (j == K) max_num = 0;
                for (int h = 0; h <= max_num; h++) {
                    dp[i+1][j + (h != 0)][k && (h == next_num)] += dp[i][j][k];
                }
            }
        }
    }

    cout << dp[ni][nj-1][0] + dp[ni][nj-1][1] << endl;

    return 0;
}

