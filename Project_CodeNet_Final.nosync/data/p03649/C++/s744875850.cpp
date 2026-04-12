#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 51;
ll a[MAXN], b[MAXN];
int n;
bool check(ll x)
{
    ll sum = 0, t;
    for (int i = 1; i <= n; i++) a[i] = b[i] + x;
    for (int i = 1; i <= n; i++) if (a[i] >= n)
    {
        t = max(0ll, (a[i] - n + 1) / (n + 1));
        a[i] -= (n + 1) * t;
        while (a[i] >= n) sum++, a[i] -= n;
        sum += t;
    }
    return sum <= x;
}
bool cmp(ll &x, ll &y) {return x > y;}
int main() 
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
    sort(b + 1, b + 1 + n, cmp);
    // for (int i = 0; i <= 100; i++) printf("%d ", check(i));
    ll l = 0, r = 1e18;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    ll ans;
    for (ll x = max(0ll, l - n * n - 1); x <= l; x++) 
        if (check(x)) {ans = x; break;}
    printf("%lld\n", ans);
    return 0;
}