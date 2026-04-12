#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
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

int n;
ll aa,bb;
vector<pll> bugu[5];

const int N = 1<<15;
set<ll> seg[2*N];

bool query(int l,int r,ll ymn,ll ymx,int a,int b,int k){
  if(r<=a || b<=l)return false;
  if(l<=a && b<=r){
    ll v = *(seg[k].lower_bound(ymn));
    return ymn <= v && v <= ymx;
  }else{
    int m = (a+b)/2;
    return query(l,r,ymn,ymx,a,m,2*k+1) || query(l,r,ymn,ymx,m,b,2*k+2);
  }
}

const ll INF = 1e18;

int main(){
  scanf("%d%lld%lld",&n,&aa,&bb);
  REP(i,n){
    int t;ll x,y;scanf("%d%lld%lld",&t,&x,&y);
    --t;
    bugu[t].push_back(pll(x,y));
  }
  sort(bugu,bugu+5,[&](vector<pll> a,vector<pll> b){return a.size() > b.size();});
  REP(i,5)bugu[i].push_back(pll(0,0));

  // rekkyo
  vector<pll> mp;
  set<ll> xs;
  REP(i,bugu[3].size())REP(j,bugu[4].size()){
    ll x=0, y=0;
    x+=bugu[3][i].first;  y+=bugu[3][i].second;
    x+=bugu[4][j].first;  y+=bugu[4][j].second;
    mp.push_back(pll(x,y));
    xs.insert(x);
  }
  xs.insert(INF);
  xs.insert(-INF);
  // zaatu
  map<ll,int> ids;
  {
    int it = 0;
    for(ll x : xs){
      ids[x] = it++;
    }
  }
  // construct set on segment tree
  REP(i,N){
    seg[i+N-1].insert(INF);
    seg[i+N-1].insert(-INF);
  }
  for(pll P : mp){
    ll x = ids[P.first];
    ll y = P.second;
    seg[x+N-1].insert(y);
  }
  FOR(i,0,N-1){
    int lch = 2*i+1;
    int rch = 2*i+2;
    for(ll y : seg[lch]){
      seg[i].insert(y);
    }
    for(ll y : seg[rch]){
      seg[i].insert(y);
    }
  }

  // query
  REP(i,bugu[0].size())REP(j,bugu[1].size())REP(k,bugu[2].size()){
    ll x=0, y=0;
    x+=bugu[0][i].first;  y+=bugu[0][i].second;
    x+=bugu[1][j].first;  y+=bugu[1][j].second;
    x+=bugu[2][k].first;  y+=bugu[2][k].second;
    // a <= x + tx <= b
    // a <= y + ty <= b
    // a-x <= tx <= b-x
    // a-y <= ty <= b-y
    int leftx = ids.lower_bound(aa-x)->second;
    int rightx = ids.upper_bound(bb-x)->second;
    bool ok = query(leftx,rightx,aa-y,bb-y,0,N,0);
    if(ok){
      puts("Yes");
      return 0;
    }
  }
  puts("No");

  return 0;
}