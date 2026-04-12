#include <bits/stdc++.h>
using namespace std;

typedef long long int  ll;

const ll mod = 1e9+7;
const int N = 1e4+7, D = 111;

ll dp[N][D];

ll solve(string& s, int d)
{
  ll res = 0, curmod = 0;
  for(int i=0;i<(int)s.size();++i)
  {
    for(int j=0;j<s[i]-'0';++j)
    {
      res = (res  + dp[s.size() - i - 1][(0 + d - (curmod + j) % d) % d]) % mod;
    }
    curmod += s[i]-'0';
    curmod %= d;
  }
  if(curmod == 0) ++res;
  return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  
  
  string k; int d;
  cin >> k >> d;
  
  int n = k.size();
  dp[0][0] = 1;
  for(int i=0;i<n;++i)
  {
    for(int j=0;j<d;++j)
      for(int l=0;l<10;++l)
        dp[i+1][(j+l)%d] = (dp[i+1][(j+l)%d] + dp[i][j]) % mod;
  }
  
  
  cout << (solve(k, d) + mod - 1) % mod << endl;
  
  return 0;
}
