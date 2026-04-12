#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+100;
const int maxc=26;
const int mod=998244353;
ll dp[3500];
ll a[3500];
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    ll ans=0;
    for(int i=1;i<=n;i++){
        dp[0]++;
        for(int j=s;j>=1;j--){
            int u=j-a[i];
            if(u>=0&&u<=s){
                if(j==s)
                    {
                        ans=(ans+dp[u]*(n-i+1))%mod;
                        //cout<<i<<"  "<<dp[u]<<"  "<<u<<endl;
                    }
                else if(u)
                    dp[j]=(dp[j]+dp[u])%mod;
            }
            else
                break;
            //cout<<i<<"   "<<j<<"  "<<dp[2]<<endl;
        }
        //cout<<dp[2]<<endl;
        if(a[i]<=s)
            dp[a[i]]=(dp[a[i]]+i)%mod;
        //cout<<ans<<endl;
    }
    printf("%lld\n",ans);
    return 0;
}
/*

*/
