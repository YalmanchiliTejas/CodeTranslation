#include <bits/stdc++.h>

using ll = long long;

long long rc(long long, int);

int main()
{
    int n;
    long long x;
    scanf("%d%lld", &n, &x);
    printf("%lld\n", rc(x, n));

    return 0;
}

// levelN
long long rc(long long x, int n)
{
    if (n == 1)
    {
        if (x == 5) return 3;
        else return x - 1;
    }
    long long burger_n{((ll)1 << (n + 2)) - 3}, burger_minus{((ll)1 << (n + 1)) - 3};
    long long ban_n{(((ll)1 << (n + 1)) - 1)}, ban_minus{((ll)1 << n) - 1};
    if (x == burger_n) return ban_n;
    if (x > burger_minus + 2) return ban_minus + 1 + rc(x - (burger_minus + 2), n - 1);
    if (x == burger_minus + 2) return ban_minus + 1;
    if (x > 1) return rc(x - 1, n - 1);
    return 0;
}