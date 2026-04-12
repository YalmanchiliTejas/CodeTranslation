#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifdef LOCAL
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;
#else
#define debug(x) ;
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

ll dp[3010][3010][2];

int main(){
  int n, a[SIZE];

  scanf("%d", &n);

  for(int i=0;i<n;i++){
    for(int j=0;j<=n;j++){
      dp[i][j][0] = dp[i][j][1] = -LLINF;
    }
  }

  for(int i=0;i<n;i++){
    scanf("%d", a+i);
    dp[i][i][n%2] = 0;
  }

  for(int i=1;i<=n;i++){
    for(int j=0;j+i<=n;j++){
      for(int k=0;k<2;k++){
        dp[j][i+j][k] = max(dp[j][i+j][k], -dp[j+1][i+j][!k] + a[j]);
        dp[j][i+j][k] = max(dp[j][i+j][k], -dp[j][i+j-1][!k] + a[i+j-1]);
      }
    }
  }

  cout << dp[0][n][0] << endl;

  return 0;
}
