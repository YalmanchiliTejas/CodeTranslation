#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<ll> a;

const int N = 3333;

ll dp[2][N][N];

ll f(int k, int i, int j)
{
  if(~dp[k][i][j]) return dp[k][i][j];
  
  ll& ans = dp[k][i][j];
  
  if(i == j)
  {
    if(k == 0) return ans = a[i];
    else return ans = 0;
  }
  
  if(k == 0)
    ans = max(a[i] + f(1, i+1, j), a[j] + f(1, i, j-1));
  else ans = min(f(0, i+1, j), f(0, i, j-1));
  
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  
  int n;
  cin >> n;
  a = vector<ll>(n);
  for(ll& i: a ) cin >> i;
  
  ll sum = 0; for(ll i: a) sum += i;
  memset(dp, -1, sizeof dp);
  cout << 2 * f(0, 0, n-1) - sum << endl;
  
  return 0;
}
