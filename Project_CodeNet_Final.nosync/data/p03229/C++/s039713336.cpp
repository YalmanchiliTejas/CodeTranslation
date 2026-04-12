#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define sn(n) scanf("%d",&n)
#define pr(n) printf("%lld",n)
#define pn printf("\n")
#define ll long long
#define p 1000000005
using namespace std;
int n,m;
ll ans;
ll a[100005];
ll b[100005];
ll c[100005];
ll look;
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    if(n%2==0)
    {
        for(int i=1;i<=n/2-1;i++)
        {
            ans+=a[n-i+1];
            ans-=a[i];
        }
        ans*=2;
        ans+=a[n/2+1];
        ans-=a[n/2];
    }
    else
    {
        for(int i=1;i<=n/2-1;i++)
        {
            ans+=a[n-i+1];
            ans-=a[i];
        }
        ans*=2;
        int x=a[n/2+2]*2-a[n/2+1]-a[n/2];
        int y=a[n/2+2]+a[n/2+1]-2*a[n/2];
        ans+=max(x,y);
    }
    pr(ans);
    pn;
    return 0;
}


/*

Lucas(卢卡斯)定理

ll pow_quick(ll a, ll b)

{

    ll  ans =1;

    while(b)

    {

        if(b &1)  ans = ans * a % p;

        b>>=1;

        a = a*a % p;

    }

    return  ans;

}

ll C(ll n, ll m)

{

    if(m > n)  return 0;

    ll ans = 1;
    for(ll i=1; i<=m; i++)
    {
        ll a = (n+i-m)%p;

        ll b = i%p;

        ans = (ans*(a*pow_quick(b,p-2)%p))%p;

    }
    return ans;
}

ll Lucas(ll n, ll m )

{

    if(m ==0)  return 1;

    else return  (C(n%p, m%p)*Lucas(n/p, m/p))%p;

}


*/
