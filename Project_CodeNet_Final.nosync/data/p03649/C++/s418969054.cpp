// > <
#include <cstdio>
#include <algorithm>
#include <functional>
#include <set>
#include <utility>
typedef long long int64;
static const int MAXN = 52;

int n;
int64 a[MAXN];

inline bool check(int64 w)
{
    static int64 b[MAXN];
    for (int i = 0; i < n; ++i) b[i] = a[i] + w;
    std::set<std::pair<int64, int>, std::greater<std::pair<int64, int>>> s, g;
    int p = std::max_element(b, b + n) - &b[0];
    for (int i = 0; i < n; ++i)
        if (i != p) s.insert(std::make_pair(b[i], i));
    g.insert(std::make_pair(0, p));
    int64 gval = b[p], _w = w;

    while (w > 0 && g.size() < n) {
        auto q = *s.begin();
        s.erase(s.begin());
        int64 c = std::min<int64>(w / g.size(), std::max(0LL, (gval + g.begin()->first - q.first - (n + 1)) / (n + 1)));
        w -= c * g.size();
        gval -= c * (n + 1);
        while (w > 0 && g.begin()->first >= q.first - gval) {
            g.insert(std::make_pair(g.begin()->first - (n + 1), g.begin()->second));
            g.erase(g.begin());
            --w;
        }
        g.insert(std::make_pair(q.first - gval, q.second));
        //printf("After %lld step(s) enters #%d with delta=%lld\n", c, q.second, q.first - gval);
    }
    //for (auto q : s) b[q.second] = q.first;
    //for (auto q : g) b[q.second] = q.first + gval;
    //printf("%lld |", _w);
    //for (int i = 0; i < n; ++i) printf(" %lld", b[i]); putchar('\n');
    if (g.size() == n) {
        gval -= (w / n) * (n + 1);
        w %= n;
    }

    for (auto q : s) b[q.second] = q.first;
    for (auto q : g) b[q.second] = q.first + gval;
    while (w > 0) {
        p = std::max_element(b, b + n) - &b[0];
        b[p] -= (n + 1);
        --w;
    }
    //printf("%lld |", _w);
    //for (int i = 0; i < n; ++i) printf(" %lld", b[i]); putchar('\n');
    //printf("%lld ", *std::max_element(b, b + n));
    //puts(*std::max_element(b, b + n) < n ? "Yes" : "No");
    return (*std::max_element(b, b + n) < n);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);

    /*int64 lo = -1, hi = 5.1e17, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (check(mid)) hi = mid; else lo = mid;
    }
    printf("%lld\n", hi);*/
    int64 sum = -(n + 1) * (n + 1);
    for (int i = 0; i < n; ++i) sum += a[i];
    for (int64 i = std::max(sum, 0LL); ; ++i)
        if (check(i)) { printf("%lld\n", i); break; }

    return 0;
}
