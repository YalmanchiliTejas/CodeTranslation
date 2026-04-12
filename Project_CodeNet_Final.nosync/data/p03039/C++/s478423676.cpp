#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(LL i = 0; i < (n); i++)
#define repp(i, l, r) for(LL i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)

typedef long long LL;
typedef long double LD;

LL inv(LL x){
  LL ans=1;
  LL a=MOD-2;
  while(a){
    if(a&1) ans=ans*x%MOD;
    x=x*x%MOD;
    a>>=1;
  }
  return ans;
}

int main(){
  LL n,m,k;
  cin >> n >> m >> k;
  LL s=0,t=0;
  rep(i,n){
    s=(s+i*(i+1)/2+(n-i)*(n-i-1)/2)%MOD;
  }
  s=s*m*m%MOD;
  rep(i,m){
    t=(t+i*(i+1)/2+(m-i)*(m-i-1)/2)%MOD;
  }
  t=t*n*n%MOD;
  LL ans = (s+t)%MOD;
  vector<LL> fact(n*m+1);
  fact[0]=1,fact[1]=1;
  repp(i,1,n*m+1) fact[i]=fact[i-1]*i%MOD;
  ans=ans*fact[n*m-2]%MOD*inv(fact[k-2])%MOD*inv(fact[n*m-k])%MOD*inv(2)%MOD;
  cout << ans << endl;
  return 0;
}
