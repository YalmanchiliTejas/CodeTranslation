#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    string N;
    int K;
    cin >> N >> K;
    int n = N.size();
    vector<vector<ll>> dp0(n + 1, vector<ll>(K + 1, 0)), dp1(n + 1, vector<ll>(K + 1, 0));
    dp0[0][0] = 1;
    rep(i, n) {
        rep(j, K + 1) {
            if (N[i] == '0') {
                dp0[i + 1][j] = dp0[i][j];
                dp1[i + 1][j] = dp1[i][j];
                if (j > 0) dp1[i + 1][j] += dp1[i][j - 1] * 9;
            } else {
                dp1[i + 1][j] = dp0[i][j] + dp1[i][j];
                if (j > 0) {
                    dp0[i + 1][j] += dp0[i][j - 1];
                    dp1[i + 1][j] += dp0[i][j - 1] * (N[i] - '1') + dp1[i][j - 1] * 9;
                }
            }
        }
    }
    cout << dp0[n][K] + dp1[n][K] << "\n";
    /*
    rep(i, n + 1) {
        rep(j, K + 1) {
            cout << dp0[i][j] << "," << dp1[i][j] << "/";
        }
        cout << "\n";
    }
    */
}