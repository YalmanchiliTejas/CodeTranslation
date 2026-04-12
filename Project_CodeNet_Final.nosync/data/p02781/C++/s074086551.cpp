#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using Graph = vector<vector<int>>;
ll dp[110][10][2];
int main(){
  string n;
  cin >> n;
  int k;
  cin >> k;
  dp[0][0][0] = 1;
  rep(i,(int)n.size())rep(j,4)rep(K,2){
    int nx = n[i] - '0';
    rep(d,10){
      int ni = i + 1,nj = j,nk = K;
      if(d != 0)nj++;
      if(nj > k)continue;
      if(K == 0){
        if(d > nx)continue;
        if(d < nx)nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][K];
    }
  }
  ll ans = dp[n.size()][k][0] + dp[n.size()][k][1];
  cout << ans << endl;
  return 0;
}
