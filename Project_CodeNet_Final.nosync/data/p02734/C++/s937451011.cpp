#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 3010;
const int mod = 998244353;
int a[M];
ll dp[M];
int main(){
    int n, s;
    scanf("%d%d", &n, &s);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        dp[0]++;
        for(int j = s; j >= a[i]; j--) {
            dp[j] += dp[j - a[i]];
            dp[j] %= mod;
        }
        ans = (ans + dp[s]) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
