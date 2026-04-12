#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define endl        "\n"
#define si(a)       scanf("%d",&a)
#define si2(a,b)    scanf("%d%d",&a,&b)
#define si3(a,b,c)  scanf("%d%d%d",&a,&b,&c)
#define sl(a)       scanf("%lld",&a)
#define sl2(a,b)    scanf("%lld%lld",&a,&b)
#define sl3(a,b,c)  scanf("%lld%lld%lld",&a,&b,&c)
#define pb          push_back
#define mk          make_pair
#define loop(n)     for(int i=0; i<n; i++)
#define FOR(a,b)    for(int i=a; i<=b; i++)
#define sz          size()
#define pY          printf("YES")
#define pN          printf("NO")
#define py          printf("Yes")
#define pn          printf("No")
#define mem(a,val)  memset(a, val, sizeof(a))
#define md          1000000007




ll a[200010], cs[200010];
int main()
{
    ll t,n,i,j,k,l,mn=0, mx=0,m;

    sl(n);

    for(int i=1; i<=n; i++)
    {
        sl(a[i]);
    }

    for(int i=1; i<=n; i++)
    {
       cs[i]=cs[i-1]+a[i];
       cs[i]%=md;
    }

    ll ans=0;

    for(int i=1; i<=n; i++)
    {
       ans =((ans%md)+ (a[i]*cs[i-1])%md)%md;
    }

    cout<<ans<<endl;

}





