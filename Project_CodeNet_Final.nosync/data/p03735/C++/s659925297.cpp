#include <cstdio>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int MAXN = 200004;
static const int   INF32 = 0x7fff0fff;
static const int64 INF64 = 0x7fffffffffffffffLL;

int n, x[MAXN], y[MAXN];

std::pair<int, int> ev[MAXN * 2];
int occ[MAXN] = { 0 };

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        if (x[i] > y[i]) std::swap(x[i], y[i]);
    }

    auto x_mm = std::minmax_element(x, x + n);
    auto y_mm = std::minmax_element(y, y + n);
    int p = std::min(*x_mm.first, *y_mm.first),
        q = std::max(*x_mm.second, *y_mm.second);

    int64 ans = INF64;
    // Case 1: p and q are in different colours
    int min[2] = { p, q }, max[2] = { p, q };
    for (int i = 0; i < n; ++i) {
        min[0] = std::min(min[0], x[i]);
        max[0] = std::max(max[0], x[i]);
        min[1] = std::min(min[1], y[i]);
        max[1] = std::max(max[1], y[i]);
    }
    ans = std::min(ans, (int64)(max[0] - min[0]) * (max[1] - min[1]));
    // Case 2: p and q are in the same colour
    int valid = 0;
    for (int i = 0; i < n; ++i) {
        if ((x[i] == p && y[i] != q) || (x[i] != p && y[i] == q)) { valid = 2; break; }
        if (x[i] == p && y[i] == q && ++valid == 2) break;
    }
    if (valid >= 2) {
        int ev_ct = 0;
        for (int i = 0; i < n; ++i) {
            ev[ev_ct++] = { x[i], i };
            ev[ev_ct++] = { y[i], i };
        }
        if (ev_ct == 0) { ans = 0; goto print; }
        std::sort(ev, ev + ev_ct);
        int head = 0, tail = 0;
        int occ_ct = 0;
        while (occ_ct < n) {
            if (++occ[ev[tail].second] == 1) ++occ_ct;
            ++tail;
        }
        int range = ev[tail - 1].first - ev[head].first;
        while (tail < ev_ct) {
            if (--occ[ev[head].second] == 0) --occ_ct;
            ++head;
            while (tail < ev_ct && occ_ct < n) {
                if (++occ[ev[tail].second] == 1) ++occ_ct;
                ++tail;
            }
            if (occ_ct == n)
                range = std::min(range, ev[tail - 1].first - ev[head].first);
        }
        ans = std::min(ans, (int64)(q - p) * range);
    } //else fputs("> <\n", stderr);

print:
    printf("%lld\n", ans);
    return 0;
}
