#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int M = (int)2e5;
const int N = (int)5e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;
const double eps = 1e-6;

int n, a[M + 5];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    ll sum = 0, ans = 0;
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), sum = (sum + a[i]) % mod;
    for(int i = 1; i <= n; ++i)
    {
        sum = (sum - a[i]) % mod;
        ans = (ans + sum * a[i] % mod) % mod;
    }
    ans = (ans % mod + mod) % mod;
    printf("%lld\n", ans);
    return 0;
}
