#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

ll a[51], p[51];
ll d(int n, ll x)
{
  if (n == 0)
    return 1;
  else if (x == 1)
    return 0;
  else if (x <= a[n - 1] + 1)
    return d(n - 1, x - 1);
  else if (x == a[n - 1] + 2)
    return p[n - 1] + 1;
  else if (x <= 2 * a[n - 1] + 2)
    return p[n - 1] + 1 + d(n - 1, x - 2 - a[n - 1]);
  else
    return p[n];
}

int main()
{
  int N;
  ll X;
  cin >> N >> X;
  a[0] = p[0] = 1;
  rep(i, N)
  {
    a[i + 1] = 2 * a[i] + 3;
    p[i + 1] = 2 * p[i] + 1;
  }
  cout << d(N, X) << endl;
  return 0;
}
