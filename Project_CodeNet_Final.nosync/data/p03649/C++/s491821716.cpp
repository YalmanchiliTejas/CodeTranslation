#include <bits/stdc++.h>
#define maxN 52
#define ll long long
using namespace std;

int n;
ll a[maxN];

ll k;
void lastOp(int N)
{
    for (int i = 1; i <= N; ++ i)
        {
            int posMax = 1;

            for (int j = 2; j <= n; ++ j)
                    if (a[j] > a[posMax])
                posMax = j;
            if (a[posMax] < n)
            return ;
            ++ k;
            a[posMax] -= n + 1;
            for (int j = 1; j <= n; ++ j)
                ++ a[j];
        }
}
ll nrOp(ll m)
{
    ll ret = 0;
    for (int i = 1; i <= n; ++ i)
        if (a[i] > m)
       ret += (a[i] - m - 1) / (n + 1) + 1;
       return ret;
}
ll bs()
{
    sort(a + 1, a + n + 1);
    ll i = a[n], p = 1LL << 59;
    while (p)
    {
        if (i >= p && nrOp(i - p) <= k)
            i -= p;
        p >>= 1;
    }
    return i;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i)
        {
            scanf("%lld", &a[i]);
            k += a[i];
        }
    if (k <= n * n)
        {
            int cp = k;
            k = 0;
            lastOp(cp);
        }
    else
    {
        k -= n * n;
        for (int i = 1; i <= n; ++ i)
            a[i] += k;
        ll m = bs(), newK = nrOp(m);

        for (int i = 1; i <= n; ++ i)
            if (a[i] > m)
        a[i] -= ((a[i] - m - 1) / (n + 1) + 1) * (n + 1);
         for (int i = 1; i <= k - newK; ++ i)
            {
                sort(a + 1, a + n + 1);
                a[n] -= n + 1;
            }
        lastOp(n * n);
    }
    printf("%lld\n", k);
    return 0;
}
