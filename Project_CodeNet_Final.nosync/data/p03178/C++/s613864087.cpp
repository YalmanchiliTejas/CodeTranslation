#include <bits/stdc++.h>

using namespace std;

const int module = 1e9 + 7;
void doc() {
    freopen("OB.inp", "r", stdin);
    freopen("OB.out", "w", stdout);
}

void solve() {
    string K;
    int D;
    cin >> K >> D;
    int n = (int)K.size();
    int F[n + 1][D][2];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < D; j++) {
            for (int k = 0; k < 2; k++) F[i][j][k] = 0;
        }
    }
    for (int i = 0; i < (K[0] - '0'); i++) F[0][i % D][0] += 1;
    int S = (K[0] - '0') % D;
    F[0][S][1] += 1;
    for (int i = 1; i < n; i++) {
        S = (S + (K[i] - '0')) % D;
        F[i][S][1] = 1;
        for (int d = 0; d < D; d++) {
            for (int j = 0; j < 10; j++) {
                for (int prev_equal = 0; prev_equal < 2; prev_equal++) {
                    bool GreaterOrEqual = j >= (K[i] - '0');
                    if (prev_equal & GreaterOrEqual) break;
                    ///cout << i - 1 << " " << ((d - j) % D + D) % D << " " << prev_equal << " " << F[i - 1][((d - j) % D + D) % D][prev_equal] << '\n';
                    F[i][d][0] = (F[i][d][0] + F[i - 1][((d - j) % D + D) % D][prev_equal]) % module;
                    ///cout << i << " " << d << " " << j << " " << equal << " " << F[i][d][equal] << '\n';
                }
            }
        }
    }
    int Res = (F[n - 1][0][0] + F[n - 1][0][1]) % module;
    Res = (Res - 1 + module) % module;
    cout << Res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    ///doc();
    solve();
}
