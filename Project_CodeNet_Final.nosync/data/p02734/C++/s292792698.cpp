#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;
const int MAXN = 3005;
vector<long long> dp(MAXN);

int main()
{
    int n, s;
    scanf("%i%i", &n, &s);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    long long ans = 0;
    for (int x = 0; x < n; x++)
    {
        for (int y = s; y >= arr[x] + 1; y--)
        {
            dp[y] += dp[y - arr[x]];
            dp[y] %= MOD;
        }
        dp[arr[x]] += x + 1;
        dp[arr[x]] %= MOD;
        ans += dp[s];
    }
    printf("%lli\n", ans % MOD);
}
