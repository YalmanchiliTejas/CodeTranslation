#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
string k;
int d;
const ll mod = 1e9 + 7;
ll dp[10005][2][105];
int main() {
  cin >> k >> d;

  dp[0][1][0] = 1;
  int n = k.size();

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 2; j++) {
      int x =  j ? (k[i] - '0') : 9;
      for(int m = 0; m <= x; m++) {
	for(int l = 0; l < d; l++) {
	  (dp[i+1][(j && (m == x))][((l + m) % d)] += dp[i][j][l]) %= mod;
	}
      }
    }
  }
  /* for(int i = 0; i <= n; i++) {
    for(int j = 0; j < 2; j++) {
      for(int m = 0; m < d; m++) {
	cout <<"dp["<<i<<"]["<<j<<"]["<<m<<"] = "<< dp[i][j][m] << endl;
      }
    }
    }*/
  

  cout << (dp[n][0][0] + dp[n][1][0] + mod- 1) % mod;
}

  
