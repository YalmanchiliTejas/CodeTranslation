#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
int d;
string s;
int dp[10005][105][2];

int add(int a, int b)
{
  return ( ((a + mod) % mod) + ((b + mod) % mod) )   % mod;
}

int solve(int idx, int rem, bool smaller)
{
  if(idx == s.size())
    return rem == 0;
  int &ans = dp[idx][rem][smaller];
  if(ans != -1)
    return ans;
  ans = 0;
  if(smaller)
  {
      for(int digit = 0; digit < 10; digit++)
        ans = add(ans, solve(idx + 1, (rem + digit) % d, 1));
      return ans;
  }
  else
  {
    for(int digit = 0; digit <= s[idx] - '0'; digit++)
    {
      if(digit < s[idx] - '0')
        ans = add(ans, solve(idx + 1, (rem + digit) % d, 1));
      else
        ans = add(ans, solve(idx + 1, (rem + digit) % d, 0));
    }
    return ans;
  }
}

int main()
{
    cin >> s >> d;
    memset(dp, -1, sizeof(dp));
    cout << add(solve(0, 0, 0), -1);
}
