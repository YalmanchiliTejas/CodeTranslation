#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

int main()
{

    //freopen("input.txt", "r", stdin);

    int n, k;
    scanf("%d%d", &n, &k);

    if (k == 0)
    {
        printf("%lld", n * 1ll * n);
        return 0;
    }

    ll ans = 0;
    for (int i = k + 1; i <= n; ++i)
    {
        ans += n / i * 1ll * (i - k);
        if (n % i >= k)
            ans += n % i - k + 1;
    }

    printf("%lld", ans);
}
