#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int n, a, b, c, f;
int d[1001], nd[1001];
int C[1001][1001];

int mul[1001];

int main() {
    forn(i, 1001) C[0][i] = 0;
    C[0][0] = 1;
    for (int i = 1; i < 1001; ++i) {
        C[i][0] = 1;
        for (int j = 1; j < 1001; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            if (C[i][j] >= MOD) {
                C[i][j] -= MOD;
            }
        }
    }
    cin >> n >> a >> b >> c >> f;
    memset(d, 0, sizeof d);
    d[n] = 1;
    for (int i = a; i <= b; ++i) {
        memcpy(nd, d, sizeof nd);
        mul[0] = 1;
        for (int j = 1; i * j <= n; ++j) {
            mul[j] = (LL)mul[j - 1] * C[i * j - 1][i - 1] % MOD;
        }
        forn(rem, n + 1) {
            if (d[rem] == 0) {
                continue;
            }
            for (int j = c; j <= f; ++j) {
                if (i * j > rem) {
                    break;
                }
                nd[rem - i * j] = (nd[rem - i * j] + (LL)d[rem] * C[rem][i * j] % MOD * mul[j]) % MOD;
            }
        }
        memcpy(d, nd, sizeof nd);
    }
    cout << d[0] << endl;
    return 0;
}
