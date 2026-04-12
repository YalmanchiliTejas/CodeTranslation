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
int x[125252],y[125252];


set<int> S;
set<pii> xx, yy;
set<pair<int,int>> mmm[4]; // ph -> (cost, id)

void po(int id){
  // remove id & insert near 4
  S.erase(id);
  xx.erase(pii(x[id],id));
  yy.erase(pii(y[id],id));
  // right & left
  {
    auto it = xx.lower_bound(pii(x[id],-1));
    if(it != xx.end()){
      int cost = abs(it->first - x[id]);
      int nid = it->second;
      mmm[0].insert(pii(cost,nid));
    }
    if(it!=xx.begin()){
      it--;
      int cost = abs(it->first - x[id]);
      int nid = it->second;
      mmm[1].insert(pii(cost,nid));
    }
  }
  {
    auto it = yy.lower_bound(pii(y[id],-1));
    if(it != yy.end()){
      int cost = abs(it->first - y[id]);
      int nid = it->second;
      mmm[2].insert(pii(cost,nid));
    }
    if(it!=yy.begin()){
      it--;
      int cost = abs(it->first - y[id]);
      int nid = it->second;
      mmm[3].insert(pii(cost,nid));
    }
  }
}

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%d%d",x+i,y+i);
  ll ans = 0;
  REP(i,n)xx.insert(pii(x[i],i)), yy.insert(pii(y[i],i));
  REP(i,n)S.insert(i);
  po(0);
  REP(_,n-1){
    int id=-1, cost=1025283025;
    REP(i,4){
      while(mmm[i].size()){
        int yo = mmm[i].begin()->second;
        if(S.count(yo)){
          if(mmm[i].begin()->first < cost){
            cost = mmm[i].begin()->first;
            id = yo;
          }
          break;
        }
        mmm[i].erase(mmm[i].begin());
      }
    }
    assert(id!=-1);
    ans += cost;
    po(id);
  }
  printf("%lld\n",ans);
  return 0;
}
