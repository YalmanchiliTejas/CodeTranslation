#include <bits/stdc++.h>
#define inf 1000000009
using namespace std;
int read();
int n;
struct P {
    int x, y;
    void init() { x = read(), y = read(), x > y ? swap(x, y) : void(); }
} p[200005];

bool cmp(P a, P b) { return a.x < b.x; }

int main() {
    n = read();
    int mxx = 0, mxy = 0, mnx = inf, mny = inf;
    long long res;
    for (int i = 1; i <= n; ++i) {
        p[i].init();
        mxx = max(mxx, p[i].x), mnx = min(mnx, p[i].x);
        mxy = max(mxy, p[i].y), mny = min(mny, p[i].y);
    }
    res = 1ll * (mxx - mnx) * (mxy - mny);
    long long tmp = mxy - mnx;
    sort(p + 1, p + 1 + n, cmp), mny = inf, mxy = 0;
    res = min(res, tmp * (p[n].x - p[1].x));
    for (int i = 1; i <= n; ++i) {
        mxy = max(mxy, p[i].y), mny = min(mny, p[i].y);
        res = min(res, tmp * (max(mxy, p[n].x) -
                              min(mny, i == n ? inf : p[i + 1].x)));
    }
    printf("%lld\n", res);
    return 0;
}

int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
