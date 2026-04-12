#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5+10;
LL num[maxn],sum[maxn];
const LL mod =1e9+7;
int main()
{
    LL n;
    cin >> n;
    for(int i = 1;i<=n;++i)
    {
        cin >> num[i];
        sum[i] = (sum[i-1]+num[i])%mod;
    }
    LL ans = 0;
    for(int i = 1;i<=n;++i)
    {
        ans = (ans+num[i]*(sum[n]-sum[i]+mod))%mod;
    }
    cout << ans << "\n";
    return 0;
}
