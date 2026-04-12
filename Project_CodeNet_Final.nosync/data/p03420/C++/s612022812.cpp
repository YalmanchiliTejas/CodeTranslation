#include "bits/stdc++.h"
using namespace std;
int main()
{
    long long n, k, total = 0;
    scanf("%lld %lld", &n, &k);
    for (long long i = k + 1; i <= n; ++i)
    {
        if (k)
        {
            total += n / i * (i - k) + max(0ll, n % i - k + 1);
        }
        else
        {
            total += n / i * (i - k) + max(0ll, n % i - k);
        }
    }
    printf("%lld\n", total);
}

