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

const int MAXN = 4e5 + 5;

int N;
pair<LL, LL> A[MAXN];

void input()
{
    read(N);
    for (int i = 0; i < N * 2; ++i) {
        read(A[i].x);
        A[i].y = i;
    }
}

void solve()
{
    static LL val[MAXN];

    for (int i = 0; i < N * 2; i += 2) {
        if (A[i].x > A[i+1].x)
            std::swap(A[i].x, A[i+1].x);
        val[i] = A[i].x;
        val[i+1] = A[i+1].x;
    }

    LL x0 = +oo, x1 = -oo, y0 = +oo, y1 = -oo;
    for (int i = 0; i < N * 2; i += 2) {
        chkmin(x0, A[i].x); chkmax(x1, A[i].x);
        chkmin(y0, A[i+1].x); chkmax(y1, A[i+1].x);
    }
    LL ans = (x1 - x0) * (y1 - y0);

    if (N > 1) {
        std::sort(A, A + N * 2);
        LL curmax = x1;
        for (int i = 0; i < N * 2; ++i) {
            chkmin(ans, (A[N*2-1].x - A[0].x) * (curmax - A[i].x));
            if (A[i].y & 1) break;
            chkmax(curmax, val[A[i].y^1]);
        }
    }

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

// 会桃花之芳园，序天伦之乐事。
//     -- 李白《春夜宴桃李园序 / 春夜宴从弟桃花园序》
