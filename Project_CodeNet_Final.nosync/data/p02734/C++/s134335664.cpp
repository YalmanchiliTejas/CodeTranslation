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

ll dp[3003][3003][3];

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

  dp[0][0][0]=1;
  for(int i=0;i<N;i++){
      for(int j=0;j<=S;j++){
          add(dp[i+1][j][0],dp[i][j][0]);
          add(dp[i+1][j][1],dp[i][j][0]+dp[i][j][1]);
          add(dp[i+1][j][2],dp[i][j][0]+dp[i][j][1]+dp[i][j][2]);
          if(j+A[i]<=S){
              add(dp[i+1][j+A[i]][1],dp[i][j][0]+dp[i][j][1]);
              add(dp[i+1][j+A[i]][2],dp[i][j][0]+dp[i][j][1]);
          }
      }
  }

  cout<<dp[N][S][2]<<endl;

  return 0;
}
