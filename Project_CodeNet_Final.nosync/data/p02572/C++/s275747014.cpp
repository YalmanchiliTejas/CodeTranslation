#include <bits/stdc++.h>

const int p = 1e9 + 7, inv = 5e8 + 4;

int main()
{
    int n;
    std::cin >> n;

    int a, sum = 0, powsum = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a;
        sum = (sum + a) % p;
        powsum = (powsum + 1ll * a * a % p) % p;
    }

    std::cout << ((1ll * sum * sum % p - powsum) % p + p) % p * inv % p << std::endl;
    return 0;
}