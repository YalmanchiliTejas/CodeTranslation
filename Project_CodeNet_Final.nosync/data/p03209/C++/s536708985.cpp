#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
ll lay[51], pati[51];
ll d(int n, ll x)
{
  if (n == 0)
    return 1;
  else if (x == 1)
    return 0;
  else if (1 < x && x <= 1 + lay[n - 1])
    return d(n - 1, x - 1);
  else if (x == 1 + lay[n - 1] + 1)
    return pati[n - 1] + 1;
  else if (1 + lay[n - 1] + 1 < x && x <= 1 + lay[n - 1] + 1 + lay[n - 1])
    return pati[n - 1] + 1 + d(n - 1, x - 2 - lay[n - 1]);
  else
    return pati[n - 1] + 1 + pati[n - 1];
}

int main()
{
  int N;
  ll X;
  cin >> N >> X;
  lay[0] = pati[0] = 1;
  for (int i = 1; i <= N; i++)
  {
    lay[i] = 2 * lay[i - 1] + 3;
    pati[i] = 2 * pati[i - 1] + 1;
  }
  ll ans = d(N, X);
  cout << ans << endl;
  return 0;
}
