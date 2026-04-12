//IIT Kanpur FacelessMen India
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define foreach( gg,itit )  for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define mp make_pair
#define pb push_back
#define all(s) s.begin(),s.end()
#define present(c,x) ((c).find(x) != (c).end())
const double EPS = 1e-8;
const int mod = 1e9+7;
const int N = 1e6+10;
const ll INF = 1e18;

//#define DEBUG
ll power(ll x,ll y){
  ll t=1;
  while(y>0){
    if(y%2) y-=1,t=t*x%mod;
    else y/=2,x=x*x%mod;
  }
  return t;
}
#ifdef DEBUG
#define dprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#else
#define dprintf(fmt,...)
#endif

vector<pii> a;
set<int> S1,S2;
map<int,int> M; 
int main(){
  // freopen("product.in","r",stdin);
  // freopen("product.out","w",stdout);
  int n; scanf("%d",&n);
  REP(i,n){
    int x,y;
    scanf("%d%d",&x,&y);
    a.pb(mp(x,-(i+1)));
    a.pb(mp(y,(i+1)));
  }
  sort(all(a));
  int tp=0,lp=a.size()-1;
  while(S1.count(abs(a[tp].Y))==0) S1.insert(abs(a[tp].Y)),tp++;
  while(S2.count(abs(a[lp].Y))==0) S2.insert(abs(a[lp].Y)),lp--;
  ll ans=1ll*abs(a[lp].X-a[0].X)*abs(a.back().X-a[tp].X);
  if(abs(a[0].Y)!=abs(a.back().Y)){
    M[abs(a[0].Y)]=1;
    int zp=a.size()-1;
    while(M[abs(a[zp].Y)]<1) M[abs(a[zp].Y)]++,zp--;
    REPP(j,1,tp+1) if(zp<a.size()-1){
      ans=min(ans,1ll*(a.back().X-a[0].X)*(a[zp].X-a[j].X));
      M[abs(a[j].Y)]++;
      while(zp<a.size()-1&&M[abs(a[j].Y)]>1) ++zp,M[abs(a[zp].Y)]--; 
    }
  }
  printf("%lld\n",ans);
  return 0;
}
