#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const int L = 10 * 1000 + 7;
const int S = 107;
const int MOD = 1000 * 1000 * 1000 + 7;

void add(int& x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int f[L][S][2];

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    string s;
    cin >> s;
    int n = s.size();
    int d;
    cin >> d;
    f[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < 2; k++) {
                int r = 9;
                if (k == 0) {
                    r = s[i] - '0';
                }
                for (int cd = 0; cd <= r; cd++) {
                    int gk = k;
                    if (cd < s[i] - '0') {
                        gk = 1;
                    }
                    add(f[i + 1][(j + cd) % d][gk], f[i][j][k]);
                }
            }
        }
    }

    int ans = (f[n][0][0] + f[n][0][1]) % MOD;
    ans = (ans + MOD - 1) % MOD;
    cout << ans << "\n";
    return 0;
}

