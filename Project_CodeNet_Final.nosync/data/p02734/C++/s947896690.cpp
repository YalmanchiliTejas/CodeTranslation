#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3005,mod=998244353;
int n,s,a[N];
ll dp[N];
int main()
{
    scanf("%d%d",&n,&s);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        for(int j=s;j>=x;j--)
            if(j>x) (dp[j]+=dp[j-x])%=mod;
        else if(j==x) (dp[j]+=i)%=mod;
        (ans+=dp[s])%=mod;
    }
    printf("%lld\n",ans);
}
