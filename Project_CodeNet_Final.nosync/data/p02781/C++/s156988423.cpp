#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <numeric>
#include <string>
#include <cassert>
#include <bitset>

using namespace std;
typedef long long ll;

int dp[105][4][2];

int main() {
  string S;
  cin >> S;
  int KK;
  cin >> KK;
  int N = S.size();

  dp[0][0][0] = 1;
  
  for (int i = 0; i < N; ++i) {
    int nd = S[i] - '0';
    for (int j = 0; j <= KK; ++j) {
      for (int k = 0; k < 2; ++k) {
	for (int d = 0; d <= 9; ++d) {
	  int ni = i + 1;
	  int nj, nk;
	  
	  if (d == 0) {
	    nj = j;
	  } else {
	    nj = j + 1;
	    if (nj > KK) continue;
	  }

	  if (k == 0) {
	    if (d > nd) continue;
	    else if (d == nd) nk = 0;
	    else nk = 1;
	  } else {
	    nk = 1;
	  }
	  
	  dp[ni][nj][nk] += dp[i][j][k];
	}
      }
    }
  }

  cout << dp[N][KK][1] + dp[N][KK][0] << endl;
  
  return 0;
}
