#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

const ll N = 4e5 + 5;
int n,m,k;
const int MOD = 1e9 + 7;
 
ll fact[N], invfact[N];
 
ll pow(ll a, ll b, ll m)
{
  ll ans=1;
  while(b)
  {
    if(b&1)
      ans=(ans*a)%m;
    b/=2;
    a=(a*a)%m;
  }
  return ans;
}
 
ll modinv(ll k)
{
  return pow(k, MOD-2, MOD);
}
 
void precompute()
{
  fact[0]=fact[1]=1;
  for(int i=2;i<N;i++)
  {
    fact[i]=fact[i-1]*i;
    fact[i]%=MOD;
  }
  invfact[N-1]=modinv(fact[N-1]);
  for(int i=N-2;i>=0;i--)
  {
    invfact[i]=invfact[i+1]*(i+1);
    invfact[i]%=MOD;
  }
}
 
ll nCr(ll x, ll y)
{
  if(y>x)
    return 0;
  ll num=fact[x];
  num*=invfact[y];
  num%=MOD;
  num*=invfact[x-y];
  num%=MOD;
  return num;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

  cin>>n>>m>>k;
  precompute();

  ll always = nCr(n*m - 2, k-2);
  ll ans = 0;
  for (ll dist=1; dist<=n-1; dist++) {
    ll ways = n-dist;
    ll cur = 1LL*dist*ways*m*m*always;
    cur %= MOD;
    ans += cur;
    ans %= MOD;
  }
  for (ll dist=1; dist<=m-1; dist++) {
    ll ways = m-dist;
    ll cur = 1LL*dist*ways*n*n*always;
    cur %= MOD;
    ans += cur;
    ans %= MOD;
  }
  cout<<ans<<endl;
  
  return 0;
}

