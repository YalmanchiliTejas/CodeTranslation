/********************************************************************************

        Code by a weak man who named CYJian, and he hope the code can get more points.

        Algorithm:

 ********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//{{{ FAST IO AND SOME FUNCTIONS
const int __SIZE = 1 << 18;
char ibuf[__SIZE], *iS, *iT;

#define ge (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
#define ri read_int()
#define rl read_ll()
#define FILE(s) freopen(s "in", "r", stdin), freopen(s "out", "w", stdout)

template <typename T> inline void read(T &x) {
    char ch, t = 0;
    x = 0;
    while (!isdigit(ch = ge))
        t |= ch == '-';
    while (isdigit(ch))
        x = x * 10 + (ch ^ 48), ch = ge;
    x = t ? -x : x;
}
inline int read_int() {
    int x;
    return read(x), x;
}
inline ll read_ll() {
    ll x;
    return read(x), x;
}

template <typename T> inline void chkmin(T &a, T b) { a = a < b ? a : b; }
template <typename T> inline void chkmax(T &a, T b) { a = a > b ? a : b; }
//}}}

const int MAXN = 200010;

int a[MAXN];
ll f[MAXN][2][2];

int main() {
#ifdef LOCAL
    FILE("");
#endif
    int n = ri, o = 0, t = 1;
    ll inf = 1LL << 62;
    for (int i = 1; i <= n; i++) {
        a[i] = ri;
        for (int x = 0; x < 2; x++)
            for (int y = 0; y < 2; y++)
                f[i][x][y] = -inf;
    }
    for (int i = 1; i <= n; i++) {
        chkmax(f[i][1][0], max(f[i - 1][0][0], f[i - 1][0][1]));
        chkmax(f[i][1][1], max(f[i - 1][0][0], f[i - 1][0][1]));
        if (i > 1) {
            for (int t = 0; t < 2; t++) {
                chkmax(f[i][t][0], f[i - 2][t][0] + a[i - 1]);
                chkmax(f[i][t][1], max(f[i - 2][t][0], f[i - 2][t][1]) + a[i]);
            }
        }
    }
    if (n & 1)
        cout << max(f[n][1][0], f[n][1][1]) << endl;
    else
        cout << max(f[n][0][0], f[n][0][1]) << endl;
    return 0;
}
