
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 1e4, ksz = 1e2, mod = 1e9 + 7;
int n, k, dp[nsz + 5][ksz + 5][2];
string dat;

void inline upd(int &a, int b) {
    (a += b) && a >= mod && (a -= mod);
}

int inline modulo(int a) {
    return (a % mod + mod) % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> dat >> k;
    n = (int) dat.size();
    loop (d, dat[0] - 48) {
        upd(dp[1][d % k][0], 1);
    }
    dp[1][(dat[0] - 48) % k][1] = 1;
    circ (i, 1, n - 1) {
        loop (s, k) {
            loop (d, 10) {
                upd(dp[i + 1][(s + d) % k][0], dp[i][s][0]);
            }
            loop (d, dat[i] - 48) {
                upd(dp[i + 1][(s + d) % k][0], dp[i][s][1]);
            }
            upd(dp[i + 1][(s + dat[i] - 48) % k][1], dp[i][s][1]);
        }
    }
    cout << modulo(dp[n][0][0] + dp[n][0][1] - 1) << ln;
}