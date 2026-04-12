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
set<int> g[125252];
int cnt[125252];

int main(){
  scanf("%d",&n);
  REP(i,n-1){
    int a,b;
    scanf("%d%d",&a,&b);
    --a;--b;
    g[a].insert(b);
    g[b].insert(a);
  }
  queue<int> leaves;
  REP(i,n)if(g[i].size()==1)leaves.push(i);
  while(!leaves.empty()){
    int p = leaves.front(); leaves.pop();
    int to = *g[p].begin();
    // erase to
    for(int yo : g[to]){
      g[yo].erase(to);
      if(g[yo].size()==1)leaves.push(yo);
      if(yo != p && g[yo].size()==0){
        puts("First");
        return 0;
      }
    }
  }
  puts("Second");
  return 0;
}
