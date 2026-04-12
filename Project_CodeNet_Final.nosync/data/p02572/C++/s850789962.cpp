#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define sz 200009
#define mx 10000000000008
#define mod 1000000007
ll n,m,i,j,k,l,t,arr[sz],brr[sz],crr[sz];
vector<ll>v;
int main()
{
     t=1;
   // scanf("%lld",&t);
    while(t--)
    {
     scanf("%lld",&n);
     for(i=1;i<=n;i++)
     {
         scanf("%lld",&arr[i]);
         brr[i]=brr[i-1]+arr[i];
         brr[i]%=mod;
     }
     for(i=2;i<=n;i++)
     {
         crr[i]=(brr[i-1]*arr[i])%mod;
         l=(l+crr[i])%mod;
     }
     printf("%lld\n",l);
    }
    return 0;
}
