#include<bits/stdc++.h>
#define ll long long

#define nl printf("\n")
#define pb(x) push_back(x)

#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define P(a) printf("%d",a)

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

#define PLC(a) printf("%lld ",a)
#define PLN(a) printf("%lld\n",a)
#define SL(a) scanf("%lld",&a)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define SL4(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)

#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define FOOL(a) memset(a,false,sizeof(a))
#define fr(i,a,n) for(ll i=a;i<=n;i++)
#define pi acos(-1.0)
#define po 1000000
#define co 1000000
#define mx 200001
#define pll pair<ll,ll>
using namespace std;
ll a[mx],b[mx];
int main()
{
    ll n,i,n2;
     SL(n);
     n2=n/2;
     for(i=1;i<=n;i++)SL(a[i]),b[i]=a[i];
     a[0]=0;
     b[0]=0;
     sort(b,b+(n+1));
     for(i=1;i<=n;i++)
     {
          if(a[i]>b[n2])PLN(b[n2]);
          else PLN(b[n2+1]);
     }
}