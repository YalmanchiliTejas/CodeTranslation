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

int n,m;
bool g[10][10];

int main(){
  scanf("%d%d",&n,&m);
  REP(i,m){
    int a,b;
    scanf("%d%d",&a,&b);
    --a;--b;
    g[a][b]=g[b][a]=true;
  }
  vi v(n);
  REP(i,n)v[i]=i;
  int ans = 0;
  do{
    bool ok = true;
    REP(i,n-1){
      if(!g[v[i]][v[i+1]])ok=false;
    }
    if(ok)ans++;
  }while(next_permutation(v.begin()+1,v.end()));
  printf("%d\n",ans);
  return 0;
}
