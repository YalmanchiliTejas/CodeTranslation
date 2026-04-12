#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

long long power(int x, int y)
{
  if (!y)
    return 1;
  long long res = power(x, y / 2);
  res = res * res % BASE;
  if (y % 2)
    res = res * x % BASE;
  return res;
}

int main()
{
  int n;
  cin >> n;

  vector<long long> fact(n + 1), invFact(n + 1), p2(n + 1);
  fact[0] = p2[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    fact[i] = fact[i - 1] * i % BASE;
    p2[i] = p2[i - 1] * 2 % BASE;
  }
  invFact[n] = power(fact[n], BASE - 2);
  for (int i = n; i; i--)
    invFact[i - 1] = invFact[i] * i % BASE;

  long long ans = power(3, n);
  for (int i = n / 2 + 1; i <= n; i++)
  {
    long long ways = fact[n] * invFact[i] % BASE * invFact[n - i] % BASE;
    ans = (ans + BASE - ways * p2[n - i + 1] % BASE) % BASE;
  }
  cout << ans << endl;
}
