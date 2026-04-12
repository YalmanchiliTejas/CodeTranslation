#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3005;
const int mod = 998244353;
ll qpow(ll a,ll b){ll res=1;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll dp[maxn][maxn],cnt[maxn][maxn];
int a[maxn];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;++i)scanf("%d",&a[i]);
    ll ans = 0;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 0;j <= m;++j)
        {
            cnt[i][j]=cnt[i-1][j];
            if(j>=a[i]){
                cnt[i][j]+=cnt[i-1][j-a[i]];
                cnt[i][j]%=mod;
                dp[i][j]=cnt[i-1][j-a[i]];
            }
        }
        cnt[i][a[i]]+=i;
        cnt[i][a[i]]%=mod;
        dp[i][a[i]]=(dp[i][a[i]]+i)%mod;
        ans=(ans+1ll*(n-i+1)*(dp[i][m]))%mod;
    }
    cout<<ans<<endl;
    return 0;
}
