#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod = 998244353;

ll n,s;
ll a[3005];
ll ans;
ll dp[3005][3005][3];
int main() {

  cin >> n >> s;

  for(int i = 0; i < n; i++) cin >> a[i];

  dp[0][0][0] = 1;

  for(int i = 0; i < n; i++) {
    for(int j = s; j >= 0; j--) {
      if(j-a[i] >= 0) {
	dp[i+1][j][1] += dp[i][j-a[i]][0];
	dp[i+1][j][1] %= mod;
	dp[i+1][j][2] += dp[i][j-a[i]][1];
	dp[i+1][j][2] %= mod;
	dp[i+1][j][1] += dp[i][j-a[i]][1];
	dp[i+1][j][1] %= mod;
	dp[i+1][j][2] += dp[i][j-a[i]][0];
	dp[i+1][j][2] %= mod;
      }
      dp[i+1][j][0] += dp[i][j][0];
      dp[i+1][j][0] %= mod;
      dp[i+1][j][1] += dp[i][j][1];
      dp[i+1][j][1] %= mod;
      dp[i+1][j][2] += dp[i][j][1];
      dp[i+1][j][2] %= mod;
      dp[i+1][j][1] += dp[i][j][0];
      dp[i+1][j][1] %= mod;
      dp[i+1][j][2] += dp[i][j][2];
      dp[i+1][j][2] %= mod;
    }
  }

  

  /* for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= s; j++) {
      for(int k = 0; k < 3; k++) {
	cout << "dp["<<i<<"]["<<j<<"]["<<k<<"] = "<<dp[i][j][k] << endl;
      }
    }
    }*/
  cout << dp[n][s][2] % mod << endl;
}

  
