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

char t[525252];
char p[525252];

int go[525252], ni[525252];
int s[525252];

int main(){
  scanf("%s%s",t,p);
  int n = strlen(t);
  int m = strlen(p);
  
  int cur = -1;
  REP(i,n){
    if(cur+1 < m && p[cur+1] == t[i]){
      cur++;
      s[cur] = i;
    }
    go[i] = cur;
  }

  if(cur != m-1){
    puts("no");
    return 0;
  }

  cur = m;
  FORR(i,0,n){
    if(cur-1 >= 0 && p[cur-1] == t[i]){
      cur--;
    }
    ni[i] = cur;
  }

  REP(i,m){
    // not use s[i]
    int pos = s[i];
    int mae = pos==0 ? -1 : go[pos-1];
    int usiro = pos==n-1 ? m : ni[pos+1];
    if(usiro-mae <= 1){
      puts("no");
      return 0;
    }
  }
  puts("yes");
  return 0;
}