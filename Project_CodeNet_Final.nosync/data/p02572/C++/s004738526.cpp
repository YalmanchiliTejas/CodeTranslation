#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const long double pi=acos(-1);
#define x  first
#define y  second
#define read(n,a) for(int i=0;i<n;i++)cin>>a[i];
#define rep(z,n)  for(int i=z;i<n;i++)

ll a[200002]={};
ll b[200003]={};
ll n,m;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    ///freopen("ss.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--)
    {
       cin>>n;
       read(n,a);
       ll mod=1e9;
       mod+=7;
       rep(1,n+1)b[i]=b[i-1]+a[i-1];
       ll ans=0;
       rep(0,n)
       {
           ans+=((a[i]%mod) * ((b[n]-b[i+1])%mod))%mod;
           ans%=mod;
       }
       cout<<ans;
    }
    return 0;
}
