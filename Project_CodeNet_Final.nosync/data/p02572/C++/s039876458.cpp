#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

const int mod=1e9+7;
const int inf=-1;
const int sz=2e5;

#define pi acos(-1)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define gap ' '
#define lb lower_bound
#define ub upper_bound
#define SIN(x) sin(x * pi / 180.0)
#define COS(x) cos(x * pi / 180.0)
#define clr(x) memset(x,0,sizeof(x))
#define all(x) sort(x.begin(),x.end())
#define rall(x) reverse(x.begin(),x.end())
#define dbg puts("finding wrong")
#define case(x,y) printf("Case %lld: %lld\n",++x,y)
#define fastio ios::sync_with_stdio(false);cin.tie(0)


ll ar[sz];

ll bigmod(ll a, ll b, ll m)
{
  if(b==0) return 1;
 
  ll x=bigmod(a,b/2,m);
  x=(x*x)%m;
  if(b%2==1)x=(x*a)%m;
 
  return x;
}

int main()
{
  fastio;
  ll  ans=0, i, n, res=0, sum=0, r;
  
  cin>>n;
  for(i=1; i<=n; i++)
  {
  cin>>ar[i];
  sum=(sum+ar[i])%mod;
  r=(ar[i]*ar[i])%mod;
  ans=(ans+r)%mod;
  }
  sum=bigmod(sum,2,mod);
  res=(sum-ans+mod)%mod;
  res=(res*bigmod(2,mod-2,mod))%mod;
  cout<<res<<endl;
}
