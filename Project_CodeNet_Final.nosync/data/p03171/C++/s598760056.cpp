#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
  int N;
  cin >> N;
  ll a[N];
  for(int i=0;i<N;i++) cin >> a[i];

  ll dp[N][N+1];
  for(int len = 1; len <= N; len++){
    for(int l = 0; l <= N - len; l++){
      int r = l + len;
      if(l + 1 == r){
        if((N - len) % 2 == 0) dp[l][r] = a[l];
        else dp[l][r] = -a[l];
      }
      else{
        if((N - len) % 2 == 0){
          dp[l][r] = max(dp[l+1][r] + a[l], dp[l][r-1] + a[r-1]);
        }
        else dp[l][r] = min(dp[l+1][r] - a[l], dp[l][r-1] - a[r-1]);
      }
    }
  }

  cout << dp[0][N] << endl;
  return 0;
}