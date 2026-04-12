#include <iostream>


using namespace std;

typedef long long ll;

const ll INF = -1e17;

ll n;
ll a[200005];
ll dp[200005][3];
int main() {
  cin >> n;

  for(int i = n; i > 0; i--) {
    cin >> a[i];
  }

  for(int i = 0; i <= n; i++) {
    for(int j = 0; j < 3; j++) {
      dp[i][j] = INF;
    }
  }

  dp[0][0] = dp[0][1] = dp[0][2] = 0;
  dp[1][2] = a[1];
  dp[1][0] = 0;

  dp[2][0] = max(a[2],a[1]);
 

  for(int i = 3; i <= n; i++) {
    if(i & 1) {
      dp[i][0] = max(a[i]+dp[i-2][0],dp[i-1][0]);
      dp[i][2] = a[i] + dp[i-2][2];
    }
    else {
      dp[i][0] = max(a[i]+dp[i-2][0],a[i-1]+dp[i-3][2]);
    }
  }

  /*    for(int i = 0; i <= n; i++) {
    for(int j = 0; j < 3; j++) {
      cout <<" dp["<<i<<"]["<<j<<"] = "<<dp[i][j] <<  endl;
    }
    }*/
  
  if(n & 1) {
    cout << max(dp[n][0],max(dp[n-1][0],dp[n-2][2])) << endl;
  }
  else {
    cout << max(dp[n][0],dp[n-1][2]) << endl;
  }
  
}


  
  
  
