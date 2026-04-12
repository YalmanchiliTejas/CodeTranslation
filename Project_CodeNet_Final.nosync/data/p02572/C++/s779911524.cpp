#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<queue>
#include<map>
#include<math.h>

#define ll long long
#define dd double
#define scl(n)        scanf("%lld",&n)
#define scd(n)        scanf("%lf",&n)
#define scc(n)        scanf("%c",&n)
#define scs(n)        scanf("%s",&n)
#define ptl(n)        printf("%lld",n)
#define ptd(n)        printf("%f",n)
#define ptc(n)        printf("%c",n)
#define pts(n)        printf("%s",n)
#define nline         printf("\n")
#define pb            push_back
#define FOR(i,n)      for(ll i=0;i<n;i++)
#define FOR1(i,n)     for(ll i=1;i<=n;i++)
#define FORran(i,a,b) for(ll i=a;i<=b;i++)
#define pi            2*acos(0.0)
#define pii           pair<ll,ll>
#define uu            first
#define vv            second
#define mod   1000000007
using namespace std;
ll a[200005],cum[200005];
int main()
{
    ll n,sum=0;
    scl(n);
    FOR(i,n)
    {
        scl(a[i]);
        if(i>0)
            cum[i]=cum[i-1]+a[i];
        else
            cum[i]=a[i];
    }
    FOR1(i,n)
    {
        sum=(sum%mod)+(((a[i]%mod)*(cum[i-1]%mod))%mod);
    }
    ptl(sum);
    return 0;
}
