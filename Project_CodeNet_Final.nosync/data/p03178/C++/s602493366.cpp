#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int mod = 1e9 + 7;

int dp[10005][101][2];
// 0 : white
int d;
int f(int idx, int sum_so_far, bool tight, string& s)
{
  if (idx == s.size())
    return (sum_so_far == 0);
  auto& ret = dp[idx][sum_so_far][tight];
  if (ret != -1)
    return ret;
  ret = 0;
  int ul = tight ? s[idx]-'0' : 9;
  for (int i = 0; i <= ul ; ++i) {
    ret += f(idx + 1,(sum_so_far + i) % d, tight & (i == ul), s);
    ret %= mod;
  }
  return ret;
}



int main()
{
  int n, k;
  string s;
  cin >> s;
  cin >> d;
  memset(dp, -1, sizeof dp);
  cout << (f (0, 0, 1, s) - 1 + mod) % mod << '\n';

  return 0;
}
