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

int n;
ll a[52];

ll calc(){
  ll ans = 0;
  while(true){
    ll add = 0;
    REP(i,n){
      ll sub = a[i]/n;
      a[i] -= sub*(n+1);
      add += sub;
    }
    if(add==0)break;
    ans += add;
    REP(i,n)a[i]+=add;
  }
  return ans;
}

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%lld",a+i);
  ll ans = calc();
  printf("%lld\n",ans);
  return 0;
}
