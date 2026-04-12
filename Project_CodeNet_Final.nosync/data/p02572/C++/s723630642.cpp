#include <bits/stdc++.h>
using namespace std;
#define  gcd(a,b)         __gcd(a,b)
#define  lcm(a,b)         (a*b)/gcd(a,b)
#define  ll               long long int
#define  pb               push_back
#define  mod              1000000007
#define  End              return 0;
#define  pi               acos(-1)
int main()
{
    ll n,m,j,x,y,i,k,ttt;
    cin>>n;
    ll a[n+1];
    ll sum=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum=sum+a[i];
    }
    ll c=0,ans=0;
    for(i=0;i<n-1;i++)
    {
        sum-=a[i];
        c=(a[i]%mod)*(sum%mod);
        c%=mod;
        ans+=c;
        ans%=mod;
    }
    cout<<ans;


}
