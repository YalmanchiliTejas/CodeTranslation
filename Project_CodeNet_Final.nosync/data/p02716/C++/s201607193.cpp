#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll n = 0;
  cin >> n;
  ll k = 0;
  k = n % 2 + 1;
  vector<ll> num(n);
  for(int i = 0;i < n;i++)cin >> num[i];
  vector<vector<ll>> dp(n + 1,vector<ll>(k + 2));
  for(int i = 0;i < n + 1;i++)for(int j = 0;j < k + 2;j++)dp[i][j] = -1000000000000000000;
  dp[0][0] = 0;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < k + 1;j++){
      if(dp[i + 1][j + 1] < dp[i][j])dp[i + 1][j + 1] = dp[i][j];
      ll add = 0;
      add = dp[i][j];
      if((i + j) % 2 == 0)add += num[i];
      if(dp[i + 1][j] < add)dp[i + 1][j] = add;
    }
  }
  ll res = 0;
  //cout << n << " " << k << endl;
  res = dp[n][k];
  cout << res << endl;
  return 0;
}


