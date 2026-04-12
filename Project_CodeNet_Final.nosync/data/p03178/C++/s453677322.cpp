#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
int dp[10005][105][2];
string s;
int d;

int add(int a, int b)
{
  a = (a + mod) % mod;
  b = (b + mod) % mod;
  return (a + b) % mod;
}

int solve(int idx, int rem, bool smaller)
{
    if(idx == s.size())
      return rem == 0;
    int &ans = dp[idx][rem][smaller];
    if(~ans)
      return ans;
    ans = 0;
    for(int i = 0; i < 10; i++)
    {
      if(smaller || (s[idx] - '0' >= i))
      {
        ans = add(ans, solve(idx + 1, (rem + i) % d, smaller | (i < s[idx] - '0')));
      }
    }
    return ans;
}

int main()
{
  cin >> s >> d;
  memset(dp, -1, sizeof dp);
  cout << add(solve(0, 0, 0), -1);
  return 0;
}
