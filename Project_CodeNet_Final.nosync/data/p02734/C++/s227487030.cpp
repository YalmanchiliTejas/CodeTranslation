#include <bits/stdc++.h>
using namespace std;
#define elif else if
typedef long long ll;
typedef unsigned long long ull;
#define DEBUG(x) cout << (x) << endl
#define TGET(a, b) get<b>(a)

#define MODULE 998244353

int dp[3005] = {0};

int is_prime(ll n)
{
    double n_sqrt;
    if (n == 2 || n == 3)
    {
        return 1;
    }
    if (n <= 1 || n % 6 != 1 && n % 6 != 5)
    {
        return 0;
    }
    n_sqrt = double(sqrt((double)n));
    for (int i = 5; i <= n_sqrt; i += 6)
    {
        if (n % i == 0 | n % (i + 2) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int arr[3005] = {0};

int main()
{
    int n;
    int s;
    scanf("%d %d", &n, &s);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[0] += 1;
        for (int j = s; j >= arr[i]; j--)
        {
            dp[j] = dp[j] + dp[j - arr[i]];
            dp[j] %= MODULE;
        }
        ans += dp[s];
        ans %= MODULE;
    }
    printf("%lld\n", ans);
    return 0;
}
