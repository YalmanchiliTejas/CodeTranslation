#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

Int dp[10800][2][108];
string k;
Int d;

int main(){
  cin >> k >> d;
  dp[0][1][0] = 1;
  for(int i = 0;i < k.size();i++){
    int now = (int)(k[i] - '0');
    for(int j = 0;j < d;j++){
      (dp[i+1][1][(j + now) % d] += dp[i][1][j]) %= MOD;
      for(int l = 0;l < 10;l++){
	(dp[i+1][0][(j+l) % d] += dp[i][0][j]) %= MOD;
	if(l < now){
	  (dp[i+1][0][(j+l) %d] += dp[i][1][j]) %= MOD;
	}
      }
    }
  }
  cout << (dp[k.size()][0][0] + dp[k.size()][1][0] + MOD - 1) % MOD << endl;
  return 0;
}