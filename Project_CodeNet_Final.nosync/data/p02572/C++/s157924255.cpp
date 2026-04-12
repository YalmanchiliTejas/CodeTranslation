#include <iostream>

using namespace std;
long long cur[200100];
long long sum[200100];
const int mod = 1e9+7;
int main()
{
    long long ans = 0;
    int n;
    scanf("%d",&n);
    sum[0] = 0;
    for(int i = 1;i <= n;i++) {
        scanf("%lld",&cur[i]);
        sum[i] = cur[i] + sum[i-1];
    }
    for(int i = 1;i <= n;i++) {
        ans += ((sum[n]-sum[i])%mod)*cur[i];
        ans %= mod;
    }
    printf("%lld\n",ans);
    return 0;
}
