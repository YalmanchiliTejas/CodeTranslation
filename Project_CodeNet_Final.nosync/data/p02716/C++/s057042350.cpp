#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  const Int INF = 1e18;

  Int n;
  cin>>n;
  vector<Int> as(n);
  for(Int i=0;i<n;i++) cin>>as[i];

  vector<map<Int, Int>> dp(2);
  auto touch=[&](auto &m,Int k){if(!m.count(k)) m[k]=-INF;};

  Int len=n;
  dp[0][0]=0;
  for(Int a:as){
    vector<map<Int, Int>> nx(2);
    for(Int u=0;u<2;u++){
      for(auto [k, v]:dp[u]){
        if(k+(len+1)/2<n/2) continue;
        // use
        if(u==0){
          touch(nx[1],k+1);
          chmax(nx[1][k+1],v+a);
        }
        // not
        touch(nx[0],k);
        chmax(nx[0][k],v);
      }
    }
    swap(dp,nx);
    len--;
  }

  touch(dp[0],n/2);
  touch(dp[1],n/2);
  cout<<max(dp[0][n/2],dp[1][n/2])<<endl;
  return 0;
}
