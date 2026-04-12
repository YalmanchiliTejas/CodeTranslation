#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define PQ priority_queue
#define UM unordered_map
#define US unordered_set
#define ALL(a) (a).begin(),(a).end()
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<vvi> vvvi;
const ll INF = (1ll << 60);
typedef pair<ll,ll> pii;
const ll MOD = 1000000007;

pii extendedEuclid(ll a,ll b){
  bool swapped=false;
  if(a<b) {swap(a,b);swapped=true;}
  pii x={1,0},y={0,1};
  while(1){
    ll xv=a*x.first+b*x.second;
    ll yv=a*y.first+b*y.second;
    if(yv==0) {if(swapped) return {x.second,x.first}; else return x;}
    ll d=xv/yv;
    swap(x,y);
    y.first-=d*x.first;
    y.second-=d*x.second;
  }
}

ll inverse(ll a,ll mod) {
  return (mod+extendedEuclid(a,mod).first%mod)%mod;
}

ll power(ll a, ll b, ll mod) {
  ll tmp=a;
  ll tmpp=1;
  ll ret=1;
  while(1){
    if(b%(tmpp*2)){
      ret=ret*tmp%mod;
      b-=tmpp;
    }
    if(b==0) break;
    tmp=tmp*tmp%mod;
    tmpp*=2;
  }
  return ret;
}

int main() {
  ll N,A,B,C,D; cin>>N>>A>>B>>C>>D;
  vi v(N+1);
  vi vv(N+1);
  {v[0]=1; FOR(i,1,N+1) v[i]=v[i-1]*i%MOD;}
  REP(i,N+1) vv[i]=inverse(v[i],MOD);
  vvi dp(B+1,vi(N+1));
  dp[A-1][0]=1;
  FOR(i,A,B+1) REP(j,N+1) {
    dp[i][j]+=dp[i-1][j];
    FOR(k,C,D+1) {
      if(k*i>j) break;
      ll tmp=1;
      tmp=tmp*dp[i-1][j-k*i]*v[N-j+k*i]%MOD;
      tmp=tmp*vv[N-j]%MOD;
      tmp=tmp*power(vv[i],k,MOD)%MOD;
      tmp=tmp*vv[k]%MOD;
      dp[i][j]+=tmp;
    }
    dp[i][j]%=MOD;
  }
  cout<<dp[B][N]<<endl;
}
