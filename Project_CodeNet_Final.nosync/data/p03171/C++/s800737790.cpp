#include <iostream>
#include <vector>
using namespace std;

// DP テーブル
long long dp[3100][3100];

int main() {
    // 入力受け取り
    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    
    // 初期条件
    for (int i = 0; i < N; ++i) dp[i][i] = 0;
    
    // DP
    for (int len = 1; len <= N; ++len) {
        for (int left = 0; left + len <= N; ++left) {
            int right = left + len;

            // 先手番
            if ((N - len) % 2 == 0)
                dp[left][right] = max(dp[left + 1][right] + a[left], dp[left][right - 1] + a[right - 1]);
            
            // 後手番
            else
                dp[left][right] = min(dp[left + 1][right] - a[left], dp[left][right - 1] - a[right - 1]);
        }
    }
    
    // 答え
    cout << dp[0][N] << endl;
}