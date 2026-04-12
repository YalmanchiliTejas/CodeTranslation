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

const int N = 1<<18;
ll dat[2*N], sum[2*N];
ll add(int l, int r, ll x, int a, int b, int k){
  if(r<=a || b<=l)return dat[k];
  if(l<=a && b<=r){
    sum[k] += x;
    return dat[k] += x;
  }
  int m = (a+b)/2;
  return dat[k] = max(add(l,r,x,a,m,2*k+1),add(l,r,x,m,b,2*k+2))+sum[k];
}
ll query(int l, int r, int a, int b, int k){
  if(r<=a || b<=l)return -1ll<<60;
  if(l<=a && b<=r)return dat[k];
  int m = (a+b)/2;
  return max(query(l,r,a,m,2*k+1), query(l,r,m,b,2*k+2)) + sum[k];
}

int n,m;
ll imo[252521];
pair<pii,int> rs[252521];

int main(){
  scanf("%d%d",&n,&m);
  REP(i,m){
    int l,r,a;
    scanf("%d%d%d",&l,&r,&a);
    --l;--r;
    imo[l] += a;
    imo[r+1] -= a;
    rs[i] = make_pair(pii(r,l),a);
  }
  REP(i,n)imo[i+1] += imo[i];
  sort(rs,rs+m);
  REP(i,m){
    int l = rs[i].first.second;
    int r = rs[i].first.first;
    int a = rs[i].second;
    add(l,N,-a,0,N,0);
  }
  ll ans = 0;
  int it = 0;
  REP(i,n){
    ll dp = max(query(0,i,0,N,0)+imo[i], imo[i]);
    add(i,i+1,dp,0,N,0);
    CHMAX(ans, dp);
    if(i==n-1)break;
    while(it<m && rs[it].first.first==i){
      int l = rs[it].first.second;
      int r = rs[it].first.first;
      int a = rs[it].second;
      it++;
      add(l,N,a,0,N,0);
    }
  }
  printf("%lld\n",ans);
  return 0;
}
