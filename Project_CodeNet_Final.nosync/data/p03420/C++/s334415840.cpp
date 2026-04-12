#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n, k;
    scanf ("%d%d", &n, &k);
    long long ans = 0;
    for (int i = k + 1; i <= n; i++)
    {
        for (int s = 0; s * i <= n; s++)
        {
            if (n - s * i >= i) ans += i - k;
            else if (n - s * i >= k)
                ans += n - s * i - k + 1;
        }
    }
    if (k == 0) ans -= n;
    printf ("%lld\n", ans);
}