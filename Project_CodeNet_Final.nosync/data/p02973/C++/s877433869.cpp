#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define reg register
#define rep(i, a, b) for (reg int i = (a), i##end = (b); i <= i##end; ++i)
#define dep(i, a, b) for (reg int i = (a), i##end = (b); i >= i##end; --i)

template <typename _typer> inline _typer read() {
    _typer init = 0;
    char ch = getchar(), k = 0;
    for ( ; !isdigit(ch); ch = getchar()) k = (ch == '-');
    for ( ; isdigit(ch); ch = getchar())
        init = (init << 3) + (init << 1) + (ch ^ 48);
    return k ? -init : init;
}
const ll N = 100005, INF = 1e9;

/*******************************************************************************
 *
 *
 *
 ******************************************************************************/

int n, A[N], B[N], c[N];

int Ans, tot;
void Add(int x, int k) {
    for ( ; x <= tot; x += x & -x)
        c[x] = max(c[x], k);
}
int Que(int x) {
    int res = 0;
    for ( ; x > 0 ; x -= x & -x)
        res = max(res, c[x]);
    return res;
}

int main() {
    rep (i, 1, n = read<int>()) A[i] = B[i] = read<int>();

    sort(B + 1, B + n + 1);
    tot = unique(B + 1, B + n + 1) - B - 1;
    rep (i, 1, n) A[i] = lower_bound(B + 1, B + tot + 1, A[i]) - B;

    dep (i, n, 1) {
        int ans = Que(A[i]) + 1;
        Ans = max(Ans, ans);
        Add(A[i], ans);
    }

    cout << Ans << endl;
    return 0;
}

