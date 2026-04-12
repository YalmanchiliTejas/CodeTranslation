#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

static const ll INF = 1e17;

ll dp[200005][4];

int main(){
  int N;
  cin >> N;
  vector<ll> v;
  rep(i,N){
    ll a;
    cin >> a;
    v.push_back(a);
  }

  rep(i,200005){
    rep(j,4){
      dp[i][j] = -INF;
    }
  }

  dp[0][0] = 0;

  int K = N%2 + 1;
  rep(i,N){
    rep(j,K+1){
      // xを1つ挿入
      dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
      // oまたはxを挿入
      if((i+j)%2 == 0){
        dp[i+1][j] = max(dp[i+1][j], dp[i][j] + v[i]);
      }else{
        dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
      }
    }
  }
  
  cout << dp[N][K] << endl;
  return 0;
}
