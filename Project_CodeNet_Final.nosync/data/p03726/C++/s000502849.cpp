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

const int MAXN = 1e5 + 5;

struct Edge {
    int v, next;
    Edge() { }
    Edge(int v_, int next_): v(v_), next(next_) { }
};

int N;
int tote, head[MAXN];
Edge edge[MAXN * 2 + 5];

inline void addEdge(int u, int v)
{
    edge[++tote] = Edge(v, head[u]);
    head[u] = tote;
}

void input()
{
    read(N);
    for (int i = 1; i < N; ++i) {
        int u, v;
        read(u); read(v);
        addEdge(u, v);
        addEdge(v, u);
    }
}

int calc(int u, int f)
{
    int ret = 1;
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (v == f) continue;
        int t = calc(v, u);
        if (t) {
            if (!~t || !ret) return -1;
            ret = 0;
        }
    }
    return ret;
}

void solve()
{
    puts(calc(1, 0) ? "First" : "Second");
}

int main()
{
#ifdef __DEBUG
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
#endif

    input();
    solve();

    return 0;
}

//                学弈
//            [先秦] 佚名
// 弈秋，通国之善弈者也。
// 使弈秋诲二人弈，其一人专心致志，惟弈秋之为听；
// 一人虽听之，一心以为有鸿鹄将至，思援弓缴而射之。
// 虽与之俱学，弗若之矣。
// 为是其智弗若与？曰：非然也。
