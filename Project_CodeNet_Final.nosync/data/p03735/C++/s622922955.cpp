#include <algorithm>
#include <cstdio>
using std::max;
using std::min;
using std::sort;
using std::swap;
struct rec
{
    int a, b;
    rec()
    {
        a = b = 0;
    }
    rec(int x, int y)
    {
        a = x;
        b = y;
    }
    friend bool operator<(const rec a, const rec b)
    {
        if (a.a == b.a)
        {
            return a.b < b.b;
        }
        return a.a < b.a;
    }
} a[200010];
int main()
{
    int n;
    rec mx(0, 0), mn(1e9, 1e9);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i].a, &a[i].b);
        if (a[i].a > a[i].b)
        {
            swap(a[i].a, a[i].b);
        }
        mx.a = max(mx.a, a[i].a);
        mx.b = max(mx.b, a[i].b);
        mn.a = min(mn.a, a[i].a);
        mn.b = min(mn.b, a[i].b);
    }
    long long ans = 1LL * (mx.a - mn.a) * (mx.b - mn.b);
    sort(a + 1, a + n + 1);
    mx = {a[n].a, mx.b};
    mn = {1000000000, a[1].a};
    for (int i = 1; i < n; i++)
    {
        mx.a = max(mx.a, a[i].b);
        mn.a = min(mn.a, a[i].b);
        ans = min(ans, 1LL * (mx.a - min(mn.a, a[i + 1].a)) * (mx.b - mn.b));
    }
    printf("%lld\n", ans);
    return 0;
}