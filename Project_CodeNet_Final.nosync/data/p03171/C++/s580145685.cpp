#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int>a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // dp[p][q]は区間[p, q]でのX-Yの値
    ll dp[N][N] = {};
    for (int i = 1; i <= N; ++i) { // 長さ
        for (int j = 0; j <= N - i; ++j) { // 区間[j, j+i-1]を更新
            int flag = (N - i + 1) % 2; // 1なら太郎の番
            if(flag == 0) flag--;
            if(i == 1){
                dp[j][j] = a[j] * flag;
            } else{
                ll rx = dp[j][j+i-2] + a[j+i-1] * flag;
                ll lx = dp[j+1][j+i-1] + a[j] * flag;
                if(flag == 1){
                    dp[j][j+i-1] = max(rx, lx);
                } else{
                    dp[j][j+i-1] = min(rx, lx);
                }
            }
        }
    }
    cout << dp[0][N-1];
    return 0;
}