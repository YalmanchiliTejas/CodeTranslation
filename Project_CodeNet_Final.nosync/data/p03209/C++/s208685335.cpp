#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i < m; i++)
#define ll long long int

using namespace std;

ll s[51], c[51];

ll solve(ll x, int n) {
  if (n == 0 && x >= 1) return 1LL;
  if (x <= 1) return 0LL;
  if (x < s[n-1] + 2LL) return solve(x - 1LL, n-1);
  if (x == s[n-1] + 2LL) return c[n-1] + 1LL;
  if (x < 2LL*s[n-1] + 2LL) return c[n-1] + 1LL + solve(x - (s[n-1] + 2LL), n-1);
  return c[n];
}

int main()
{
  ll n,x;
  cin >> n >> x;
  s[0] = 1;
  c[0] = 1;

  FOR(i,1,n+1) {
    s[i] = 3 + 2*s[i-1];
    c[i] = 1 + 2*c[i-1];
  }

  cout << solve(x, n) << endl;
}
