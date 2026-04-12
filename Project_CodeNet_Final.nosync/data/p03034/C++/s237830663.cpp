#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100005;

int n, s[N];
long long ans = 0, le[N], ri[N];

void upd(long long bit[N], int u, int v)
{
    for (++u; u <= n; u += u & -u)
        bit[u] += v;
}

long long que(long long bit[N], int u)
{
    long long ret = 0;
    for (++u; u > 0; u -= u & -u)
        ret += bit[u];
    return ret;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int ab = 1; ab < n; ab++)
    {
        for (int i = 0; i < n; i += ab)
            upd(le, i, s[i]);
        for (int i = n - 1; i >= 0; i -= ab)
            upd(ri, i, s[i]);
        for (int i = 0; i < n; i += ab)
        {
            int a = n - 1 - i;
            if (a <= ab)
                continue;
            if (a % ab == 0)
            {
                int tmp = a / ab;
                if (1LL * tmp * a - 1LL * (tmp - 1) * (a - ab) < n - 1)
                    continue;
            }
            ans = max(ans, que(ri, n - 1) - que(ri, a - 1) + que(le, i));
        }
        for (int i = 0; i < n; i += ab)
            upd(le, i, -s[i]);
        for (int i = n - 1; i >= 0; i -= ab)
            upd(ri, i, -s[i]);
    }
    cout << ans;
}
