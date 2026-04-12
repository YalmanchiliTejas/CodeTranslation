#include <cstdio>
#include <algorithm>

using namespace std;

#define long long long

const long INF = 1e18;

long n, a[50];

void Solve()
{
    long res = INF;
    for (int rem = 0; rem < n + 1; ++rem)
    {
        bool check = true;
        long sum = 0;
        for (int i = 0; check && i < n; ++i)
            if ((a[i] + rem) % (n + 1) == n) check = false;
            else
                sum += (a[i] + rem) / (n + 1);
        if (!check || sum < rem) continue;
        res = min(res, (sum - rem) * (n + 1) + rem);      // indeed correct
    }
    printf("%lld", res);
}

int main()
{
    scanf("%lld", &n);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    Solve();
    return 0;
}
