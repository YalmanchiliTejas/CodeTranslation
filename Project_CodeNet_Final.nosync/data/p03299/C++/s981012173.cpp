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

int n;
ll h[125];

ll modpow(ll a, ll b){
  ll r = 1;
  while(b){
    if(b&1)r=r*a%MOD;
    a=a*a%MOD;
    b>>=1;
  }
  return r;
}

const ll INV2 = (MOD+1)/2ll;

ll memo[125][125][125][2];
// -> base = h[k], range = [l,r), nurikata
ll dfs(int l, int r, int k, int typ){
  if(l>=r)return 0ll;
  if(memo[l][r][k][typ]!=-1)return memo[l][r][k][typ];
  int base = k==n ? 0 : h[k];
  int top = 1<<30;
  int topi = -1;
  FOR(i,l,r){
    if(h[i]<top){
      top = h[i];
      topi = i;
    }
  }
  int topr = topi;
  while(topr<r){
    if(h[topr] == h[topi])topr++;
    else break;
  }
  // int topl = r;
  // while(topl>0){
  //   if(h[topl-1] == h[topi])topl--;
  //   else break;
  // }
  if(l+1==r){
    if(typ==1){
      // printf("(%d,%d,%d,%d) -> %lld\n", l,r,k,typ,modpow(2,top-base));
      return memo[l][r][k][typ] = modpow(2,top-base);
    }else{
      // printf("(%d,%d,%d,%d) -> %lld\n", l,r,k,typ,0ll);
      return memo[l][r][k][typ] = 0;
    }
  }
  if(typ==1){
    // kougo
    ll ret = 0;
    if(topi==l && topr==r){
      ret = 1;
    }else if(topi==l){
      ret = dfs(topr,r,topi,1);
    }else if(topr==r){
      ret = dfs(l,topi,topi,1);
    }else{
      ret = dfs(l,topi,topi,1) * dfs(topr,r,topi,1) % MOD;
    }
    ret = ret * modpow(2,top-base) % MOD;
    // printf("(%d,%d,%d,%d) -> %lld\n", l,r,k,typ,ret);
    return memo[l][r][k][typ] = ret;
  }else{
    // contains conseq
    ll ret = 0;
    ll l0 = dfs(l,topi,topi,0);
    ll l1 = dfs(l,topi,topi,1)*2%MOD;
    ll r0 = dfs(topr,r,topi,0);
    ll r1 = dfs(topr,r,topi,1)*2%MOD;
    ll bip = modpow(2,topr-topi);
    // printf("  %lld %lld %lld %lld\n",l0,l1,r0,r1);
    if(topi==l && topr==r){
      ret = (modpow(2,r-l)-2+MOD)%MOD;
    }else if(topi == l){
      ret = r0 * bip % MOD + r1 * (bip-1+MOD) % MOD;
      ret %= MOD;
    }else if(topr == r){
      ret = l0 * bip % MOD + l1 * (bip-1+MOD) % MOD;
      ret %= MOD;
    }else{
      ret += l0 * r0 % MOD * bip % MOD;
      ret += l0 * r1 % MOD * bip % MOD;
      ret += l1 * r0 % MOD * bip % MOD;
      ret += l1 * r1 % MOD * (2*bip-1+MOD) % MOD * INV2 % MOD;
      ret %= MOD;
    }
    // printf("(%d,%d,%d,%d) -> %lld\n", l,r,k,typ,ret);
    return memo[l][r][k][typ] = ret;
  }
}

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%lld",h+i);
  REP(i,125)REP(j,125)REP(k,125)REP(l,2)memo[i][j][k][l] = -1;
  ll ans = (dfs(0,n,n,0) + dfs(0,n,n,1)) % MOD;
  printf("%lld\n",ans);
  return 0;
}
