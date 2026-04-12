#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    string N;
    int K;
    cin >> N >> K;

    int L = N.length();
    vector<vector<ll>> dp0(L, vector<ll>(K + 1, 0)); // N未満が未確定
    vector<vector<ll>> dp1(L, vector<ll>(K + 1, 0));
    dp0[0][1] = 1;
    dp1[0][0] = 1;
    dp1[0][1] = N[0] - '0' - 1;
    for (int i = 1; i < L; i++) {
        for (int k = 0; k <= K; k++) {
            if (N[i] != '0') {
                if (k == 0) {
                    dp0[i][k] = 0;
                } else {
                    dp0[i][k] += dp0[i - 1][k - 1];
                }
            } else {
                dp0[i][k] += dp0[i - 1][k];
            }
            dp1[i][k] += dp1[i - 1][k];
            if (k != 0) {
                dp1[i][k] += dp1[i - 1][k - 1] * 9;
            }

            if (N[i] != '0') {
                dp1[i][k] += dp0[i - 1][k];
                if (k != 0) {
                    dp1[i][k] += dp0[i - 1][k - 1] * (N[i] - '0' - 1);
                }
            }
        }
    }

    cout << dp0[L - 1][K] + dp1[L - 1][K] << endl;
}
