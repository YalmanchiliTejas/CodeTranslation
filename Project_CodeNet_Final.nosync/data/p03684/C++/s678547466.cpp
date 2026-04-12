#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
#include <stack>
#include <vector>
#define INF 0x3f3f3f3f
#define MOD 1000000009
# define FOR(i,a,n) for(register int i=a; i<=n; ++i)
# define FDR(i,a,n) for(register int i=a; i>=n; --i)
typedef long long ll;

using namespace std;
struct A
{
    int l;
    int r;
    int q;
};
struct B
{
    int a;
    int b;
    int num;
};
B bb[300005];
A aa[300005];
int a[100005], b[100005];
int f[100005];
int finds(int x)
{
    return f[x] == x?x:f[x] = finds(f[x]);
}
int cmp1(B a, B b)
{
    return a.a < b.a;
}
int cmp2(B a, B b)
{
    return a.b < b.b;
}
int cmp3(A a, A b)
{
    return a.q < b.q;
}
int main()
{
    int n;
    scanf("%d", &n);
    FOR(i,1,n)
    {
        scanf("%d%d", &bb[i].a, &bb[i].b);
        bb[i].num = i;
    }
    int ji = 0;
    sort(bb+1, bb+1+n, cmp1);
    for(int i = 1; i < n; i++)
    {
        aa[ji].l = bb[i].num;
        aa[ji].r = bb[i+1].num;
        aa[ji++].q = min(abs(bb[i].a-bb[i+1].a), abs(bb[i].b-bb[i+1].b));
    }
    sort(bb+1, bb+1+n, cmp2);
    for(int i = 1; i < n; i++)
    {
        aa[ji].l = bb[i].num;
        aa[ji].r = bb[i+1].num;
        aa[ji++].q = min(abs(bb[i].a-bb[i+1].a), abs(bb[i].b-bb[i+1].b));
    }
    sort(aa, aa+ji, cmp3);
    FOR(i,1,n)
    f[i] = i;
    ll ans = 0;
    for(int i = 0; i < ji; i++)
    {
        int x = finds(aa[i].l);
        int y = finds(aa[i].r);
        if(x != y)
        {
            f[x] = y;
            ans += aa[i].q;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
