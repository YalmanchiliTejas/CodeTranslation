#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007 
#define pb push_back
//#define mp make_pair
#define INF 2000000011LL
#define INFLL 1000000000000000011LL
#define eps 1e-9
#define pp pair < pair<ll,ll> , ll> 
#define fo(i,j,k) for(int i=j;i<=k;i++)
#define foll(i,j,k) for(ll i=j;i<=k;i++)
#define clr(a) memset(a,0,sizeof(a))
#define vi vector<int>
#define vll vector<ll>
#define sz(a) a.size()
#define len(a) a.length()
#define all(a) a.begin(),a.end()
#define io_file freopen("Contest/input_file.in", "r", stdin); freopen("Contest/output_file.in", "w", stdout)

const int MAXN = 2e5+5;
using namespace std;
ll power(ll x, ll y)
{
  ll res = 1;
  while(y>0)
  {
    if(y&1)
       {
         res = (res*x)%mod;
        }
     x = (x*x)%mod;
     y = y>>1;
  }
    return res;
}
// std::vector<ll> divi[100004];
// void divisor(int n)
// {
//    for(ll i=1;i<=n;i++)
//    {
//      for(ll j=i;j<=n;j+=i)
//      {
//        divi[j].pb(i);
//      }
//    }
// }
ll n,m,k;
ll fact[200005];
ll rev[200005];

ll ncr(ll n,ll r)
{
  if(n < r) return 0;
  return (((fact[n]*rev[n-r])%mod)*rev[r])%mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    fact[0] = 1;
    rev[0] = 1;
    for(ll i = 1;i<=200004;i++)
    {
      fact[i] = (fact[i-1]*i)%mod;
      rev[i] = (rev[i-1]*power(i,mod-2))%mod;
    }
    ll ans = 0;
    for(ll i=1;i<=n;i++)
    {
      for(ll j=1;j<=m;j++)
      {
        ll x = ((((i-1LL)*i)/2LL + ((n-i+1LL)*(n-i))/2LL)*m)%mod;
        ll y = ((((j-1LL)*j)/2LL + ((m-j+1LL)*(m-j))/2LL)*n)%mod;
        ans = (ans + x + y)%mod;
      }
    }
    ans = (ans*ncr(n*m-2LL,k-2LL))%mod;
    ans = (ans*power(2LL,mod-2LL))%mod;
    cout<<ans<<endl;
    return 0;

}

