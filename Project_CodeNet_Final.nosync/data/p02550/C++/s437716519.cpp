#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,ans,m,x;
ll f[100005];
ll vis[100005];
ll pre[100005];
int main()
{
    for(int i=0;i<100003;i++) f[i] = -1;
    a = 1;
    ans=-1;
    scanf("%lld%lld%lld",&n,&x,&m);
    for(int i=1;i<=n;i++)
    {
        if(i==1) a = x%m;
        else a = a*a%m;
        if(vis[a]==0)
        {
            f[i] = a;
            vis[a] = i;
            pre[i] = f[i]+pre[i-1];
            //cout<<i<<" "<<f[i]<<endl;
        }
        else
        {
            //从vis[a]到i-1是一个循环节
            ll len = i-vis[a];
            ll yu = (n-i+1)%len;
            ans = pre[i-1]+(n-i+1)/len*(pre[i-1]-pre[vis[a]-1]) + pre[vis[a]+yu-1]-pre[vis[a]-1];
            break;
        }
    }
    if(ans==-1) ans = pre[n];
    printf("%lld\n",ans);
    return 0;
}
