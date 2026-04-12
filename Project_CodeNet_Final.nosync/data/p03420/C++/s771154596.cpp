#include <bits/stdc++.h>

#include <iostream>

using namespace std;

typedef long long ll;

int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    if(k == 0) return !printf("%lld", 1LL * n * n);
    ll ans = 0;
    for(int b = k + 1; b <= n; b++)
    {
        ans += n / b * (b - k);
        if(n % b >= k) ans += n % b - k + 1;
    }
    printf("%lld", ans);
    return 0;
}