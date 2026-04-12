#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+13;
const int mod=1e9+7;
int a[maxn];
ll b[maxn];
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
   	scanf("%d",&a[i]);
   }
   for(int i=1;i<=n;i++)
   {
   	b[i]=(b[i-1]+1ll*a[i])%mod;
   }
   ll ans=0;
   for(int i=1;i<=n;i++)
   {
   	ans+=1ll*a[i]*(b[n]-b[i]+mod)%mod;
   	ans%=mod;
   }
   printf("%lld",ans%mod);
 } 