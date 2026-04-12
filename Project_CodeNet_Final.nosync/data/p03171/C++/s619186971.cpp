#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <stack>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i ++)
using ll = long long;
int N;
int A[3001];
ll dp[3001][3001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    rep(i, N) cin >> A[i];
    rep(i, N + 1) {
        dp[0][i] = 0;
    }
    for (int l = 1; l <= N; l ++) {
        int player = (N - l) % 2;
        rep(i, N + 1 - l) {
            int x = A[i], y = A[i+l-1];
            if (player == 1) {
                dp[l][i] = min(-x + dp[l - 1][i + 1], -y + dp[l - 1][i]);
            } else {
                dp[l][i] = max(x + dp[l - 1][i + 1], y + dp[l - 1][i]);
            }
        }
    }
    cout << dp[N][0] << endl;
    return 0;
}