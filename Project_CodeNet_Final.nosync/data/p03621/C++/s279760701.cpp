// Copyright (C) 2017 __debug.

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; version 3

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; If not, see <http://www.gnu.org/licenses/>.


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>

#define x first
#define y second
#define MP std::make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using std::pair;
using std::vector;
using std::string;

typedef long long LL;
typedef pair<int, int> Pii;

const int oo = 0x3f3f3f3f;

template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return b < a ? a = b, true : false; }
string procStatus()
{
    std::ifstream t("/proc/self/status");
    return string(std::istreambuf_iterator<char>(t), std::istreambuf_iterator<char>());
}
template<typename T> T read(T &x)
{
    int f = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        f = (ch == '-' ? -1 : 1);
    for (x = 0; isdigit(ch); ch = getchar())
        x = 10 * x + ch - '0';
    return x *= f;
}
template<typename T> void write(T x)
{
    if (x == 0) {
        putchar('0');
        return;
    }
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    static char s[20];
    int top = 0;
    for (; x; x /= 10)
        s[++top] = x % 10 + '0';
    while (top)
        putchar(s[top--]);
}
// EOT

const int MAXN = 32771;
const int MOD = 998244353;

int N;
char A[MAXN], B[MAXN];

void input()
{
    scanf("%s", A + 1);
    scanf("%s", B + 1);
    N = strlen(A + 1);
}

LL fpm(LL base, LL exp)
{
    LL ret = 1;
    for (; exp; exp >>= 1) {
        if (exp & 1)
            (ret *= base) %= MOD;
        (base *= base) %= MOD;
    }
    return ret;
}

namespace Poly
{

int n, rev[MAXN];
LL in, wn[MAXN];

void init(int n_)
{
    int step = 0;
    for (n = 1; n < n_; n <<= 1) ++step;
    for (int i = 0; i < n; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (step - 1));
    in = fpm(n, MOD - 2);
    int w = fpm(3, (MOD - 1) / n);
    wn[0] = 1;
    for (int i = 1; i <= n; ++i) wn[i] = wn[i - 1] * w % MOD;
}

void dft(LL a[], int f)
{
    for (int i = 0; i < n; ++i) {
        if (i < rev[i])
            std::swap(a[i], a[rev[i]]);
    }
    for (int k = 1; k < n; k <<= 1) {
        int t = n / (k << 1);
        for (int i = 0; i < n; i += k << 1) {
            for (int j = 0; j < k; ++j) {
                LL x = a[i + j];
                LL y = a[i + j + k] * (f == 1 ? wn[j * t] : wn[n - j * t]) % MOD;
                a[i + j] = (x + y) % MOD;
                a[i + j + k] = (x - y + MOD) % MOD;
            }
        }
    }
    if (f == -1) {
        for (int i = 0; i < n; ++i) (a[i] *= in) %= MOD;
    }
}

void mult(LL a[], const LL b_[], int len)
{
    static LL b[MAXN];
    init(len * 2 - 1);
    std::copy(b_, b_ + n, b);
    dft(a, +1); dft(b, +1);
    for (int i = 0; i < n; ++i) (a[i] *= b[i]) %= MOD;
    dft(a, -1);
    std::fill(a + len, a + n, 0);
}

}

void solve()
{
    static LL fac[MAXN], ifac[MAXN];

    fac[0] = 1;
    for (int i = 1; i <= N + 1; ++i) fac[i] = fac[i - 1] * i % MOD;
    ifac[N + 1] = fpm(fac[N + 1], MOD - 2);
    for (int i = N + 1; i >= 1; --i) ifac[i - 1] = ifac[i] * i % MOD;

    int m = 0, e = 0;
    for (int i = 1; i <= N; ++i) if (A[i] == '1') ++(B[i] == '1' ? m : e);

    static LL ret[MAXN], base[MAXN];

    ret[0] = 1;
    for (int i = 0; i <= m; ++i) base[i] = ifac[i + 1];
    for (int exp = e; exp; exp >>= 1) {
        if (exp & 1)
            Poly::mult(ret, base, m + 1);
        Poly::mult(base, base, m + 1);
    }

    LL ans = 0;
    for (int i = 0; i <= m; ++i) (ans += ret[i]) %= MOD;
    (ans *= fac[e] * fac[m] % MOD * fac[e + m] % MOD) %= MOD;

    printf("%lld\n", ans);
}

int main()
{
#ifdef __DEBUG
    freopen("E.in", "r", stdin);
    freopen("E.out", "w", stdout);
#endif

    input();
    solve();

    return 0;
}

// 采菊东篱下，悠然见南山。
//     -- 陶渊明《饮酒·其五》
