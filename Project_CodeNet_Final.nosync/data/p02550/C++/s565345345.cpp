#include<cstdio>
const int maxn=100005;
int pos[maxn],a[maxn<<1];
int main()
{
    long long n,x,m,ans=0,pp=0,ppp=0;
    scanf("%lld%lld%lld",&n,&x,&m);
    ans+=x;
    a[1]=x;
    for (int i = 2; i <= n; i++)
    {
        x=x*x%m;
        a[i]=x;
        if(pos[x])
        {
            pp=pos[x];
            ppp=i;
            // ans+=x;
            break;
        }
        else
        {
            pos[x]=i;
            ans+=x;
        }
    }
    // printf("%lld\n",ppp);
    if(pp)
    {
        long long t=0;
        for (int i = pp; i < ppp; i++)
        {
            t+=a[i];
        }
        ans-=t;
        n-=(pp-1);
        ans+=n/(ppp-pp)*t;
        int board=pp+n%(ppp-pp);
        for (int i = pp; i < board; i++)
        {
            ans+=a[i];
        }
    }
    printf("%lld\n",ans);
    return 0;
}