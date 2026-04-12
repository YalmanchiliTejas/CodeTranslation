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

ll dp[1005][1005],fac[1005][1005],inv[1005][1005];
int a,b,c,d;
ll nck(int n,int y){
  return fac[n][1]*inv[y][1]%mod*inv[n-y][1]%mod;
}
ll get(int tot,int mx){
  if(tot==0){
    return 1;
  }
 // printf("zz%d %d\n",tot,mx);
  if(mx<a) return 0;
  if(dp[tot][mx]!=-1) return dp[tot][mx];
  ll &ret=dp[tot][mx]; ret=0;

  ret=get(tot,mx-1);
  if(mx<=b){
    REPP(i,c,d+1){
      if(tot-mx*i<0) break;
      ret+=nck(tot,mx*i)*fac[mx*i][1]%mod*inv[mx][i]%mod*inv[i][1]%mod*get(tot-mx*i,mx-1)%mod;
 //     printf("%d %d %lld \n",tot,mx,ret);//,nck(tot,mx*i),fac[mx*i][1],inv[mx][i],get(tot-mx*i,mx-1),nck(tot,mx*i)*fac[mx*i][1]%mod*inv[mx][i]%mod*get(tot-mx*i,mx-1)%mod);
    }
  }
  ret%=mod;
//  printf("gg%d %d %lld\n",tot,mx,ret);
  return ret;
}
int main(){
  REP(i,1005){
    ll x; if(i==0) x=1; else x=fac[i-1][1]*i%mod;
    ll z=power(x,mod-2);
    ll y =1;
    REP(j,1005) fac[i][j]=y,y=y*x%mod;
    y=1;
    REP(j,1005) inv[i][j]=y,y=y*z%mod;
  }
  FILL(dp,-1);
  int n;
  scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
  ll ans=get(n,b);
  printf("%lld\n",ans);
  return 0;
}