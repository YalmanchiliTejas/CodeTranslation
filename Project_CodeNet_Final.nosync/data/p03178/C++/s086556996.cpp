#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int N = 100001;
string num;
int dp[10001][101][2];
int D;
int solve(int in, int rem, bool tight){
  if(in == num.size())
    return rem == 0 ? 1 : 0;
  int& res = dp[in][rem][tight];
  if(res != -1)
    return res;
  res = 0;

  for(int i = 0;i <= 9;i++){
    if(tight && i > num[in] - '0')
      break;

    res = (1ll * res + solve(in + 1, (rem + i) % D, tight && num[in] - '0' == i)) % MOD;
  }
  return res;
}

int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> num >> D;
  memset(dp, -1, sizeof(dp));
  cout << (solve(0, 0, 1) - 1 + MOD) % MOD;
  return 0;
}

