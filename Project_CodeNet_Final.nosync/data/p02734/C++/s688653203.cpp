#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int maxn = 2e5+5;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
int t;
int n,m;
int dp[3005];
int c[3005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",&c[i]);
    dp[0] = 0;
    ll ans = 0;
    for(int i=1;i<=n;++i)
    {
        ++dp[0];
        for(int j=m;j>=c[i];--j)
        {
            dp[j] = (dp[j] + dp[j-c[i]])%mod;
        }
        ans = (ans+dp[m])%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
