#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

int n,a,b,c,d;

// dp[i][j] : 残りi人をj人以下のグループで構成する方法
// dp[i][j] = dp[i][j-1] + dp[i-j][j-1] * iCj + dp[i-2j][j-1] * iC2j / 2! + ...
ll dp[1252][1252];

ll fact[1252];
void extgcd(int a,int b,int &x,int &y){
  int g=a;x=a;y=0;
  if(b!=0){
    extgcd(b,a%b,y,x);
    y -= (a/b)*x;
  }
}
int inv(int x){
  int m = MOD;
  int a,b;
  extgcd(x,m,a,b);
  return (a+MOD)%MOD;
}
ll ifact[1252];
ll comb(ll a,ll b){
  return fact[a]*ifact[b]%MOD*ifact[a-b]%MOD;
}

int main(){
  scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
  fact[0] = 1;
  FOR(i,1,1252)fact[i]=fact[i-1]*i%MOD;
  FOR(i,0,1252)ifact[i]=inv(fact[i]);

  REP(j,b+1)dp[0][j] = 1;
  FOR(i,1,n+1)FOR(j,a,b+1){
    dp[i][j] = dp[i][j-1];
    ll mul = 1;
    FOR(k,1,d+1){
      if(i-k*j>=0){
        mul = mul * comb(i-(k-1)*j,j) % MOD;
        if(k<c)continue;
        dp[i][j] += dp[i-k*j][j-1] * mul % MOD * ifact[k] % MOD;
        if(dp[i][j]>=MOD)dp[i][j]-=MOD;
      }
    }
  }
  printf("%lld\n",dp[n][b]);
  return 0;
}
