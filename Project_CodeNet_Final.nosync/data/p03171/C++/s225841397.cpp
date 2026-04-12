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
typedef pair<int,int> P;

ll dp[3333][3333];
ll n,a[3333];

ll dfs(ll l,ll r) {
  if(dp[l][r]!=MAXL) return dp[l][r];
  if(r<l) return 0;
  if((n-abs(l-r))%2) {
    ll x=dfs(l+1,r)+a[l];
    ll y=dfs(l,r-1)+a[r];
    dp[l][r]=max(x,y);
  } else {
    ll x=dfs(l+1,r)-a[l];
    ll y=dfs(l,r-1)-a[r];
    dp[l][r]=min(x,y);
  }
  return dp[l][r];
}

void Main() {
  rep(i,3333)rep(j,3333) dp[i][j]=MAXL;
  R n;
  rep(i,n) R a[i];
  pr(dfs(0,n-1));
}

int main(){ios::sync_with_stdio(0);cin.tie(0);Main();return 0;}
