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
#define bcnt __builtin_popcount

#define INF 1e16

ll mod_pow(ll a,ll n,ll mod){
  ll res=1;
  while(n>0){
    if(n&1)res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

ll N,M;
ll p[3001*3001 + 1];
ll f[3001],finv[3001];
ll S[3001][3001];

ll comb(ll n,ll r,ll mod){
  if(n<0||r<0||n<r)return 0;
  else return (f[n]*finv[n-r]%mod)*finv[r]%mod;
}

int main(){
  cin>>N>>M;
  f[0]=1;
  rep(i,3000)f[i+1]=f[i]*(i+1)%M;
  rep(i,3001)finv[i]=mod_pow(f[i],M-2,M);
  p[0]=1;
  rep(i,3001*3001)p[i+1]=p[i]*2%M;
  S[0][0]=1;
  for(int i=1;i<=3000;i++){
    for(int j=1;j<=i;j++)S[i][j]=(S[i-1][j-1]+j*S[i-1][j])%M;
  }

  ll res=0;
  rep(i,N+1){
    ll crt=0;
    rep(j,i+1){
      (crt+=S[i][j]*p[(N-i)*j]%M)%=M;
      (crt+=(S[i][j+1]*(j+1)%M)*p[(N-i)*j]%M)%=M;
    }
    (crt*=comb(N,i,M))%=M;
    (crt*=mod_pow(2,mod_pow(2,N-i,M-1),M))%=M;

    if(i%2==0)(res+=crt)%=M;
    else (res+=M-crt)%=M;
  }
  cout<<res<<endl;
  return 0;
}
