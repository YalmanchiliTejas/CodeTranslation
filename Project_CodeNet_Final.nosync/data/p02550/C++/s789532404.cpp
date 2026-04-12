#include <bits/stdc++.h>

int main()
{
    long long n;
    int x, m;
    std::cin >> n >> x >> m;

    long long ans = 0;
    bool *flg;
    flg = new bool[m]();
    for (; n; --n)
    {
        if (flg[x])
            break;
        ans += x;
        flg[x] = true;
        x = 1ll * x * x % m;
    }
    int tmp = x, cnt = 0;
    long long sum = 0;
    n--;
    x = 1ll * x * x % m;
    for (; n; --n)
    {
        cnt++;
        sum += x;
        if (x == tmp)
            break;
        x = 1ll * x * x % m;
    }
    ans += (n / cnt + 1) * sum;
    n %= cnt;
    for (; n; --n)
    {
        ans += x;
        x = 1ll * x * x % m;
    }
    std::cout << ans << std::endl;
    return 0;
}