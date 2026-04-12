#include <bits/stdc++.h>
using namespace std;using ll=int_fast64_t;using ld=long double;using pll=pair<ll,ll>;using pld=pair<ld,ld>;
const ll INF=1LL<<60;void solve();int main(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(10);solve();}
#define SELECTOR(_1,_2,_3,_4,SELECT,...) SELECT
#define rep(...) SELECTOR(__VA_ARGS__,_rep2,_rep1,_rep0)(__VA_ARGS__)
#define _rep0(i,n) for(ll i=0;i<n;++i)
#define _rep1(i,k,n) for(ll i=k;i<n;++i)
#define _rep2(i,k,n,d) for(ll i=k;d!=0&&d>0?i<n:i>n;i+=d)
template<class T> vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<class... Ts> auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<class T> inline bool chmax(T &a,const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a,const T &b){if(a>b){a=b; return 1;} return 0;}
template<class T> void contout(const T &v){for(auto it=v.begin();it!=v.end();++it,cout<<(it!=v.end()?" ":"\n"))cout<<*it;}

void solve(){
  ll n; cin>>n;
  vector<ll> A(n);
  rep(i,n) cin>>A[i];
  auto dp=make_v(n+1,n+1,(ll)-1);
  function<ll(ll,ll)> dfs=[&](ll L,ll R){
    if(L==R) return (ll)0;
    if(dp[L][R]!=-1) return dp[L][R];
    ll turn=n-(R-L);
    if(turn%2==0){
      return dp[L][R]=max(dfs(L+1,R)+A[L],dfs(L,R-1)+A[R-1]);
    }else{
      return dp[L][R]=min(dfs(L+1,R)-A[L],dfs(L,R-1)-A[R-1]);
    }
  };
  cout<<dfs(0,n)<<"\n";
}