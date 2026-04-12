#include <cstdio>
#include <algorithm>

using namespace std;

long long n, k, ans;

int main()
{
    scanf("%lld%lld", &n, &k);
    if (!k) {printf("%lld\n", n * n); return 0;}
    for(int i = k + 1; i <= n; ++i)
        ans += n / i * (i - k) + max(n % i - k + 1, 0LL);
    printf("%lld\n", ans);
    return 0;
}
