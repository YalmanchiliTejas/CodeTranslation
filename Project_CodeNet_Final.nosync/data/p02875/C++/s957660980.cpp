#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF 1e16
#define mod 998244353

ll mod_pow(ll x,ll n){
  ll res=1;
  while(n>0){
    if(n&1)res=res*x%mod;
    x=x*x%mod;
    n>>=1;
  }
  return res;
}


ll N;
ll fac[10000010],finv[10000010];

ll comb(ll n,ll r){
  if(n<0||r<0||n<r) return 0;
  else return (fac[n]*finv[n-r]%mod)*finv[r]%mod;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  fac[0]=1;
  rep(i,10000000)fac[i+1]=fac[i]*(i+1)%mod;
  rep(i,10000001)finv[i]=mod_pow(fac[i],mod-2);

  cin>>N;
  ll res=mod_pow(3,N);
  repl(A,(N/2)+1,N+1){
    ll cnt=comb(N,A)*mod_pow(2,N-A);
    res=(res-cnt+mod)%mod;
    res=(res-cnt+mod)%mod;
  }
  cout<<res<<endl;

  return 0;
}
