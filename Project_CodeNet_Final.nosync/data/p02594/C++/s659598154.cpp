#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;
ll power(ll a,ll n)
{
          ll result=1;
          while(n>0)
          {
               if(n&1)
                    result=result*a;
               a=a*a;
               n=n>>1;
          }
          return result;
}
ll lcm(ll a,ll b)
{
          return ((a*b)/__gcd(a,b));
}
bool ispow2(ll n)
{
          return (ceil(log2(n))==floor(log2(n)));
}
bool isprime(ll n)
{
          if(n==1)
               return false;
          else if(n==2)
               return true;
          else
          {
               for(ll i=2;i*i<=n;++i)
               {
                    if(n%i==0)
                         return false;
               }
               return true;
          }
}

ll ncr(ll n,ll r)
{
    if(r > n - r)
          r = n - r;
    ll ans = 1;
    ll i;

    for(i = 1; i <= r; i++)
     {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
int main()
{
          ios_base::sync_with_stdio(0);
          cin.tie(0);

          int t=1;
          //cin>>t;
          while(t--)
          {
                    int n;
                    cin>>n;
                    if(n>=30)
                         cout<<"Yes";
                    else
                         cout<<"No";
          }
          return 0;
}
