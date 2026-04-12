#include <bits/stdc++.h>

#define reg register
#define pr std::pair<int, int>
#define fi first
#define se second
#define FIN(s) freopen(s, "r", stdin)
#define FOUT(s) freopen(s, "w", stdout)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define lep(i, l, r) for (int i = l; i < r; ++i)
#define irep(i, r, l) for (int i = r; i >= l; --i)
#define ilep(i, r, l) for (int i = r; i > l; --i)
#define Rep(i, n) rep(i, 1, n)
#define Lep(i, n) lep(i, 1, n)
#define IRep(i, n) irep(i, n, 1)
#define ILep(i, n) ilep(i, n, 1)
typedef long long ll;
typedef long double ld;

namespace modular {
    const int MOD = 1000000007;
    inline int add(int x, int y) { return (x += y) >= MOD ? x -= MOD : x; }
    inline void inc(int &x, int y) { (x += y) >= MOD ? x -= MOD : 0; }
    inline int mul(int x, int y) { return 1LL * x * y % MOD; }
    inline int qpow(int x, int y) {
        int ans = 1;
        for (; y; y >>= 1, x = mul(x, x))
            if (y & 1) ans = mul(ans, x);
        return ans;
    }
};  // namespace modular
using namespace modular;

namespace Base {
    template <typename Tp>
    inline Tp input() {
        Tp x = 0, y = 1;
        char c = getchar();
        while ((c < '0' || '9' < c) && c != EOF) {
            if (c == '-') y = -1;
            c = getchar();
        }
        if (c == EOF) return 0;
        while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getchar();
        return x *= y;
    }
    template <typename Tp>
    inline void read(Tp &x) {
        x = input<Tp>();
    }
    template <typename Tp>
    inline void chmax(Tp &x, Tp y) {
        x < y ? x = y : 0;
    }
    template <typename Tp>
    inline void chmin(Tp &x, Tp y) {
        x > y ? x = y : 0;
    }
};  // namespace Base
using namespace Base;
/*----------------------------------------------------------------------------*/

#define MAX_N 300007

int N, M;
int f[MAX_N], g[MAX_N];
char s[MAX_N];

int main() {
    read(N), read(M);
    scanf("%s", s + 1);
    bool vis = false;
    int len = 0, mn = N;
    Rep(i, M) {
        if (s[i] != s[1]) {
            if (!vis || (len & 1)) chmin(mn, len / 2 + 1);
            vis = true, len = 0;
        } else
            ++len;
    }
    // printf("%d\n", len);
    if (!vis) {
        int a = 0, b = 1;
        Lep(i, N) {
            std::swap(a, b);
            inc(b, a);
        }
        printf("%d\n", add(mul(a, 2), b));
        return 0;
    }
    if (N & 1) return puts("0"), 0;
    N >>= 1;
    f[0] = g[0] = 1;
    Rep(i, N) {
        f[i] = g[i - 1];
        if (i > mn) inc(f[i], MOD - g[i - mn - 1]);
        // printf("%d %d %d\n", i, g[i - 1], f[i]);
        g[i] = add(f[i], g[i - 1]);
    }
    int res = 0;
    Rep(i, mn) inc(res, mul(mul(i, 2), f[N - i]));
    printf("%d\n", res);
    return 0;
}
