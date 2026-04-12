#include <bits/stdc++.h>

#define MODADD(x, y) ((x) = ((x) + (y)) % MOD)

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

string K;
int D, n;
ll dp0[2][100], dp1[2][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> K >> D;
    n = K.size();
    dp0[0][0] = 1;
    for (int i = 0; i < n; i++) {
        memset(dp1, 0, sizeof dp1);
        for (int m = 0; m < D; m++) {
            for (int d = 0; d <= 9; d++)
                MODADD(dp1[1][(m + d) % D], dp0[1][m]);
            for (int d = 0; d < K[i] - '0'; d++)
                MODADD(dp1[1][(m + d) % D], dp0[0][m]);
            MODADD(dp1[0][(m + K[i] - '0') % D], dp0[0][m]);
        }
        memcpy(dp0, dp1, sizeof dp1);
    }
    cout << (dp1[0][0] + dp1[1][0] + MOD - 1) % MOD << endl;
}
