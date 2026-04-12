#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
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
#define rrep(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
template<Z A>void pr(A a){cout<<a;ln;}
template<Z A,Z B>void pr(A a,B b){cout<<a<<' ';pr(b);}
template<Z A,Z B,Z C>void pr(A a,B b,C c){cout<<a<<' ';pr(b,c);}
template<Z A,Z B,Z C,Z D>void pr(A a,B b,C c,D d){cout<<a<<' ';pr(b,c,d);}
template<Z A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}ln;}
ll check(ll n,ll m,ll x,ll y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1e9+7,MAXL=1LL<<61,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<ll,ll> P;

void Main() {
  ll n;
  R n;
  ll a[n];
  rep(i,n) R a[i];
  ll dp[n+1][3];
  rep(i,n+1)rep(j,3) dp[i][j]=-MAXL;
  if(n%2) {
    rep(i,3) dp[i+1][2-i]=a[i];
  } else {
    rep(i,2) dp[i+1][1-i]=a[i];
  }
  REP(i,1,n) {
    rep(j,3) {
      rep(k,j+1) {
        if(i+1+k<n) {
          dp[i+2+k][j-k]=max(dp[i+2+k][j-k],dp[i][j]+a[i+1+k]);
        }
      }
    }
  }
  ll ans=-MAXL;
  if(n%2) {
    rep(i,3) ans=max(ans,dp[n-i][i]);
  } else {
    rep(i,2) ans=max(ans,dp[n-i][i]);
  }
  pr(ans);
}

int main(){ios::sync_with_stdio(0);cin.tie(0);Main();return 0;}
