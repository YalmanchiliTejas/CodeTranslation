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

char s[12525];
int d;
int n;
ll dp[12525][2][125];

int main(){
  scanf("%s",s);
  scanf("%d",&d);
  n = strlen(s);
  dp[0][0][0] = 1ll;
  REP(i,n)REP(less,2)REP(mod,d){
    REP(j,10)if(less || j<=s[i]-'0'){
      (dp[i+1][less || j<s[i]-'0'][(mod+j)%d] += dp[i][less][mod]) %= MOD;
    }
  }
  ll ans = (dp[n][0][0] + dp[n][1][0]) % MOD;
  ans = (ans + MOD - 1) % MOD;
  printf("%lld\n",ans);
  return 0;
}
