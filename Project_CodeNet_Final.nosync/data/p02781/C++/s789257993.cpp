#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;
string n;
ll K;
ll dp[105][2][5];
ll ans;

int main() {
  cin >> n;
  cin >> K;
  int tt = n[0] - '0';
  dp[0][1][1] = 1;
  dp[0][0][1] = tt - 1;
  dp[0][0][0] = 1;
  
  
 
  for(int i = 1; i < n.size(); i++) {
    ll tmp = n[i] - '0';
    for(int j = 0; j < 2; j++) {
      if(j == 0) {
	for(int k = 0; k < 4; k++) {
	  dp[i][j][k+1] += dp[i-1][j][k] * 9;
	  dp[i][j][k] += dp[i-1][j][k];
	}
      }
      else {
	for(int k = 0; k < 4; k++) {
	if(n[i] == '0') {
	  dp[i][j][k] += dp[i-1][j][k];
	}
	else if(n[i] == '1') {
	  dp[i][j][k+1] += dp[i-1][j][k];
	  dp[i][j-1][k] += dp[i-1][j][k];
	}
	else {
	  dp[i][j][k+1] += dp[i-1][j][k];
	  dp[i][j-1][k+1] += dp[i-1][j][k] * (tmp - 1);
	  dp[i][j-1][k] += dp[i-1][j][k];
	}
	}
      }
    }
  }

  /* for(int i = 0; i < n.size(); i++) {
    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < 4; k++) {
	cout << "dp["<<i<<"]["<<j<<"]["<<k<<"] = "<<dp[i][j][k] << endl;
      }
    }
    }*/
  


  //  cout << dp[n.size()-1][0][K] <<"   "<<dp[n.size()-1][1][K] << endl;
  cout << dp[n.size()-1][0][K] + dp[n.size()-1][1][K] << endl;
}
	  
	  
  
  
