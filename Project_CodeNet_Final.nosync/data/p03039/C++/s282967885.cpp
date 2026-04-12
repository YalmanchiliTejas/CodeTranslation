#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>



#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n-1); i >= 0; i--)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;

long long modpow(long long x,long long n,long long mod)
{
  if(n==0)return 1;
  long long res=modpow(x*x%mod,n/2,mod);
  if(n&1)res=res*x%mod;
  return res;
}
long long modinv(long long a,long long mod)
{
  return modpow(a,mod-2,mod);
}
vector<long long> fact,inv;
long long mod=1e9+7;
void init(int n){
  fact.resize(n);
  inv.resize(n);
  fact[0]=1LL;
  rep(i,n-1){
    fact[i+1]=(long long)fact[i]*(i+1)%mod;
  }
  inv[n-1]=modinv(fact[n-1],mod);
  rrep(i,n-1){
    inv[i]=(long long)inv[i+1]*(i+1)%mod;
  }
}
long long comb(ll a,ll b){
  return fact[a]*inv[b]%mod*inv[a-b]%mod;;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m,k;cin>>n>>m>>k;
  ll res=0;
  init(2e5+7);
  ll com=comb(n*m-2,k-2);
  rep(d,m){
    res+=n*n%mod*(m-d)%mod*com%mod*d%mod;
  }
  rep(d,n){
    res+=m*m%mod*(n-d)%mod*com%mod*d%mod;
  }
  cout<<res%mod<<endl;

  return 0;

}
