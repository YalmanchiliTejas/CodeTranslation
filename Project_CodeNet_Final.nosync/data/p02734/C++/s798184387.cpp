#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=998244353;
template<class T> void chmin(T &a,const T &b){if(a>b) a=b;}
template<class T> void chmax(T &a,const T &b){if(a<b) a=b;}

void add(ll &a,ll b){
    a=(a+b)%MOD;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,S;
  cin>>N>>S;
  vector<int> A(N);
  rep(i,N) cin>>A[i];
  
  vector<vector<ll>> dp(N+1,vector<ll> (S+1,0));
  dp[0][0]=1;
  for(int i=0;i<N;i++){
      for(int j=0;j<=S;j++){
          add(dp[i+1][j],dp[i][j]);
          if(j+A[i]<=S){
              ll neco=1;
              if(j==0) neco=i+1;
              ll res=dp[i][j]*neco%MOD;
              add(dp[i+1][j+A[i]],res);
          }
      }
  }

  ll ans=0;
  for(int i=1;i<=N;i++) add(ans,dp[i][S]);
  cout<<ans<<endl;

  return 0;
}
