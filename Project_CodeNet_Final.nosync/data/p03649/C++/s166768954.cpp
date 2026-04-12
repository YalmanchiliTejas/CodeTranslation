#include <bits/stdc++.h>

int main()
{
    int n;
    long long a[50], k{};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", a + i);
    bool updated{true};
    while (updated)
    {
        updated = false;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < n) continue;
            updated = true;
            long long decrease = a[i] / n;
            k += decrease;
            a[i] %= n;
            for (int j = 0; j < n; j++)
                if (j != i)
                    a[j] += decrease;
        }
    }
    printf("%lld\n", k);

    return 0;
}