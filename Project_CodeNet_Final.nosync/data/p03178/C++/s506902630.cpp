#include<bits/stdc++.h>
using namespace std;

using ll = int_fast64_t;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define repr(i,n) for(int i{n};i-->0;)
template<class T>vector<T> vec(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto vec(size_t a, Ts... ts){return vector<decltype(vec<T>(ts...))>(a, vec<T>(ts...));}

signed main(){

  string s;
  int d;
  cin>>s>>d;
  int n = size(s);

  vector<int> a(n);
  rep(i,n)a[i] = s[i]-'0';

  auto dp = vec<ll>(2,n+1,d);
  dp[0][0][0] = 1;
  constexpr ll mod = 1e9+7;
  rep(i,n){
    rep(m,d){
      dp[0][i][m] %= mod;
      dp[1][i][m] %= mod;
      rep(dig,10){
        int nd = (dig+m)%d;
        dp[1][i+1][nd] += dp[1][i][m];
        if(dig==a[i])dp[0][i+1][nd] += dp[0][i][m];
        if(dig<a[i])dp[1][i+1][nd] += dp[0][i][m];
      }
    }
  }
  ll ans = dp[0][n][0]+dp[1][n][0]-1;
  ans %= mod;
  cout<<(ans)<<endl;

}