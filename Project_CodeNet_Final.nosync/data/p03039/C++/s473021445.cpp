#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5 + 10, Mod = 1e9 + 7;
inline int Power(int a, int b)
{
    int ret = 1;
    for (; b; b >>= 1, a = (ll)a * a % Mod)
        if (b & 1) ret = (ll)ret * a % Mod;
    return (ret);
}
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    ll cn = 1;
    for (int i = 1; i <= k; i++)
        cn = cn * i % Mod;
    cn = Power(cn, Mod - 2);
    cn = cn * k % Mod * (k - 1) % Mod;
    for (int i = n * m - k + 1; i <= n * m - 2; i++)
        cn = cn * i % Mod;
    ll tot = 0;
    for (int i = 1; i < n; i++)
        tot = (tot + (ll)(n - i) * m % Mod * m % Mod * i) % Mod;
    for (int i = 1; i < m; i++)
        tot = (tot + (ll)(m - i) * n % Mod * n % Mod * i) % Mod;
    tot = tot * cn % Mod;
    printf("%lld\n", tot);
    return 0;
}