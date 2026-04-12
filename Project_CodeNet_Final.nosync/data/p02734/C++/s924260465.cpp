#include <iostream>
#include <cstdio>
using namespace std;
const long long N = 3010;
const long long S = 3010;
const long long mod = 998244353;
long long n, s;
long long a[N];
long long dp[S];
long long ans;
int main() {
    scanf("%lld%lld", &n, &s);
    for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (long long i = 1; i <= n; i++) {
        if (s == a[i]) {
            ans += i * (n - i + 1) % mod;
            ans %= mod;
        } else if (s > a[i]) {
            ans += dp[s - a[i]] * (n - i + 1) % mod;
            ans %= mod;
        }
        for (long long j = s; j >= a[i]; j--) {
            dp[j] += (dp[j - a[i]] + (j == a[i] ? i : 0)) % mod;
            dp[j] %= mod;
        }
    } 
    printf("%lld", ans);
    return 0;
}
