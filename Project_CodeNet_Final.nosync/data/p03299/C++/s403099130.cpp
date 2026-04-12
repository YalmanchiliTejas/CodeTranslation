#include <cstdio>
#include <algorithm>
#include <utility>
#include <tuple>
using namespace std;

constexpr int mod = 1000000007;

int pow2(int n) {
    // fprintf(stderr, "pow2(%d) = ", n);
    long ans = 1, x = 2;
    for (; n; n >>= 1, x = x * x % mod)
        if (n & 1)
            ans = ans * x % mod;
    // fprintf(stderr, "%d\n", (int) ans);
    return ans;
}

pair<int, int> solve(int *bg, int *ed) {
    int m = *min_element(bg, ed);
    for_each(bg, ed, [m](int &x) { x -= m; });

    long f = 1, s = 2;
    int n = 0;
    for (int *p = bg; p != ed;) {
        if (*p) {
            int *q = find(p, ed, 0);
            auto pa = solve(p, q);
            f = f * (pa.first + pa.second) % mod;
            s = s * pa.second % mod;
            p = q;
        } else {
            n++;
            p++;
        }
    }
    f = f * pow2(n) % mod;

    f = (f - s + mod) % mod;
    s = s * pow2(m - 1) % mod;
    f = (f + s) % mod;

    return make_pair(f, s);
}

int h[100];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", h + i);
    
    printf("%d\n", solve(h, h + n).first);
}
