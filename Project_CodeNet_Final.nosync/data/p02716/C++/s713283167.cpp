#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define fi first
#define se second
#define INF 1000000009
#define LLINF 1000000000000000009LL
#define chmax(a, b) a = max(a, b)
using ll = long long;

ll dp[200009][9];

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  int k=1+n%2;
  rep(i,n+1)rep(j,k+1)dp[i][j]=-LLINF;
  dp[0][0]=0;
  rep(i,n){
    rep(j,k+1){
      chmax(dp[i+1][j+1],dp[i][j]);
      ll now=dp[i][j];
      if((i+j)%2==0)now+=a[i];
      chmax(dp[i+1][j],now);
    }
  }
  cout<<dp[n][k]<<endl;
  return(0);
}
