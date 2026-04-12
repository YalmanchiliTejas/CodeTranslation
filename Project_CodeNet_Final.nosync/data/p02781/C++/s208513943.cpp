#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    string n;
    cin >> n;
    int K;
    cin >> K;
    int N = n.size();
    ll dp[105][2][105] = {0};

    dp[0][0][0] = 1;

    // i桁目まで走査した時、smallerで場合分けして、０以外の数が桁にj個含まれている個数。
    rep(i, N) {
        rep(j, N) {
            // 1から１への遷移
            dp[i + 1][1][j + 1] += dp[i][1][j] * 9; // i+1桁目が0以外
            dp[i + 1][1][j] += dp[i][1][j];         // i+1桁目が0

            // 0から1への遷移
            int ni = n[i] - '0';
            if (ni > 0) {
                dp[i + 1][1][j + 1] +=
                    dp[i][0][j] * (ni - 1); // i+1桁目がni以下かつ0でない
                dp[i + 1][1][j] += dp[i][0][j]; // i+1桁目が0
            }

            // 0から0への遷移
            if (ni > 0) {
                dp[i + 1][0][j + 1] += dp[i][0][j];
            } else if (ni == 0) {
                dp[i + 1][0][j] += dp[i][0][j];
            }
        }
    }

    cout << dp[N][0][K] + dp[N][1][K] << endl;
}