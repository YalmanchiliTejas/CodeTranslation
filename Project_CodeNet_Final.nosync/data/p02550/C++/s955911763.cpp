#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int visited[100005],f[100005];
ll s[100005];
int main()
{
    ll n;
    int x,m;
    cin>>n>>x>>m;
    f[1]=x,visited[x]=1;s[1]=x;
    for(ll i=2;i<=n;i++)
    {
        f[i]=1ll*f[i-1]*f[i-1]%m;
        s[i]=s[i-1]+f[i];
        if(visited[f[i]])
        {
            int t=visited[f[i]],r=i-t;
            int c=(n-t+1)%t;
            ll tmp=s[t-1]+(n-t+1)/(i-t)*(s[i]-s[t]);
            for(int j=1;j<=(n-t+1)%r;j++)tmp+=f[t-1+j];
            printf("%lld",tmp);
            return 0;
        }
        visited[f[i]]=i;
    }
    printf("%lld",s[n]);
    return 0;
}