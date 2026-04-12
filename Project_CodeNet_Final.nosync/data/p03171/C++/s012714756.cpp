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

Int dp[3240][3240];
Int a[3240];
Int n;

int main(){
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> a[i];
  }

  for(int i = 0;i <= n;i++){
    for(int j = 0;j+i <= n;j++){
      if(i == 0){
	dp[j][j+i] == 0;
      }
      else if((n-i)%2 == 0){
	dp[j][i+j] = max(dp[j+1][i+j] + a[j], dp[j][i+j-1] + a[i+j-1]);
      }
      else{
	dp[j][i+j] = min(dp[j+1][i+j] - a[j], dp[j][i+j-1] - a[i+j-1]);
      }
      //      cout << j << " " << i+j << " " << dp[i][i+j] << endl;
    }
  }
  cout << dp[0][n] << endl;
  return 0;
}