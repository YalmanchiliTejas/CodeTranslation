#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;
ll dp[200005][4];

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n)cin >> a[i];
  int k = 1+n%2;
  rep(i,n+1)rep(j,k+1)dp[i][j]=-LINF;
  dp[0][0]=0;
  for(int i=1;i<=n;i++){
    rep(j,k+1){
      if(j>0)chmax(dp[i][j],dp[i-1][j-1]);
      ll now = dp[i-1][j];
      if((i+j)%2==1)now+=a[i-1];
      chmax(dp[i][j],now);
    }
  }
  cout << dp[n][k] << endl;
}