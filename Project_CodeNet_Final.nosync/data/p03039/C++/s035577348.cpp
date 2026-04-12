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
#define mod 1000000007

ll mod_pow(ll a,ll n){
  ll res=1;
  while(n>0){
    if(n&1)res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

ll fac[200010],finv[200010];

ll comb(ll n,ll r){
  if(n<0||r<0||n<r)return 0;
  else return (fac[n]*finv[n-r]%mod)*finv[r]%mod;
}

ll N,M,K;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  fac[0]=1;
  rep(i,200000)fac[i+1]=fac[i]*(i+1)%mod;
  rep(i,200001)finv[i]=mod_pow(fac[i],mod-2);

  cin>>N>>M>>K;

  ll suma=0,sumb=0;
  repl(i,1,N){
  	ll cnt=N-i;
  	suma+=cnt*i;
  	suma%=mod;
  }
  suma*=M; suma%=mod;
  suma*=M; suma%=mod;

  repl(i,1,M){
  	ll cnt=M-i;
  	sumb+=cnt*i;
  	sumb%=mod;
  }
  sumb*=N; sumb%=mod;
  sumb*=N; sumb%=mod;

  cout<<(suma+sumb)*comb(N*M-2,K-2)%mod<<endl;

  return 0;
}
