#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pi M_PI
#define R cin>>
#define Z class
#define ll long long
#define ln cout<<'\n'
#define in(a) insert(a)
#define pb(a) push_back(a)
#define pd(a) printf("%.10f\n",a)
#define mem(a) memset(a,0,sizeof(a))
#define all(c) (c).begin(),(c).end()
#define iter(c) __typeof((c).begin())
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
template<Z A>void pr(A a){cout<<a;ln;}
template<Z A,Z B>void pr(A a,B b){cout<<a<<' ';pr(b);}
template<Z A,Z B,Z C>void pr(A a,B b,C c){cout<<a<<' ';pr(b,c);}
template<Z A,Z B,Z C,Z D>void pr(A a,B b,C c,D d){cout<<a<<' ';pr(b,c,d);}
template<Z A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}ln;}
ll check(ll n,ll m,ll x,ll y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1000000007,MAXL=1LL<<61,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<int,int> P;

void Main() {
  int n;
  R n;
  P a[n];
  rep(i,n) cin >> a[i].F >> a[i].S;
  string s[4];
  rep(i,4) R s[i];
  int dp[1<<16];
  rep(i,1<<16) dp[i]=MAX;
  dp[0]=0;
  rep(t,1<<16) {
    if(dp[t]==MAX) continue;
    rep(k,n)REP(l,-a[k].F+1,4)REP(r,-a[k].S+1,4) {
      int z=0,e=0;
      REP(x,max(0,l),min(4,l+a[k].F)) {
        REP(y,max(0,r),min(4,r+a[k].S)) {
          z|=1<<(x*4+y);
          if(!(t&(1<<x*4+y))) {
            if(s[x][y]=='R') e|=1<<0;
            if(s[x][y]=='G') e|=1<<1;
            if(s[x][y]=='B') e|=1<<2;
          }
          if(!(e==0||e==1||e==2||e==4)) goto next;
        }
      }
      if(e==1||e==2||e==4) dp[t|z]=min(dp[t|z],dp[t]+1);
    next:;
    }
  }
  pr(dp[(1<<16)-1]);
}

int main(){ios::sync_with_stdio(0);cin.tie(0);Main();return 0;}
