#include<bits/stdc++.h> 
#define Re register
#define fo(i, a, b) for (Re int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (Re int i = (a); i >= (b); --i)
#define edge(i, u) for (Re int i = head[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define pb push_back
#define F first
#define S second
#define ll long long
#define inf 1000000007
#define mp std::make_pair
#define lowbit(x) (x & -x)
#define eps 1e-4
#define itset std::set<node>::iterator
#define lb lower_bound
#define N 100005
#define M 4000005
#define mod 1000000007
ll n, m, k, a[N], ans, b[N], x;
inline void search (int d)
{
    if (d == 0) {++ans, --x; return;}
    if (a[d] <= x)
    {
        x -= a[d];
        ans += b[d];
        return;
    }
    --x;
    if (x == 0) return;
    search(d - 1);
    if (x == 0) return;
    ++ans, --x;
    if (x == 0) return;
    search(d - 1);
    if (x == 0) return;
    --x;
    return;
}
int main ()
{
    scanf("%lld %lld", &n, &x);
    a[0] = b[0] = 1;
    fo (i, 1, n)
    {
        a[i] = 2 * a[i - 1] + 3;
        b[i] = 2 * b[i - 1] + 1;
    }
    search(n);
    printf("%lld\n", ans);
    return 0;
}