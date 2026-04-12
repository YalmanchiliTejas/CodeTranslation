#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100005];
ll vis[100005];
ll sum[100005];
int main()
{
    ll n;
    scanf("%lld",&n);
    ll x,m;
    scanf("%lld%lld",&x,&m);
    a[1]=x;
    vis[x]=1;
    ll len=0;
    sum[1]=a[1];
    ll ans=0;
    int flag=0;
    ll num=0;
    ll cnt=0;
    for(ll i=2;i<=100005;i++)
    {
        ll y=(a[i-1]*a[i-1])%m;

        if(vis[y]==0)
        {
            vis[y]=i;
            a[i]=y;
            sum[i]=a[i]+sum[i-1];
        }
        else
        {
            len=i-vis[y];
            cnt=vis[y]-1;
            num=sum[i-1]-sum[vis[y]-1];
            break;
        }
    }
   // cout<<"sss"<<endl;
  //  cout<<len<<endl<<sum[len]<<endl;
//  cout<<flag<<endl;
  /*  if(flag==1)
    {
        if(n>=len)
        {
            ans=sum[len];
        }
        else
        {
            ans=sum[n];
        }
         printf("%lld\n",ans);
         return 0;
    }*/
    ans+=sum[cnt];
    ll l=(n-cnt)/len;
    ans+=l*num;
    ll p=(n-cnt)%len;
    ans+=sum[p+cnt]-sum[cnt];
    printf("%lld\n",ans);
}
