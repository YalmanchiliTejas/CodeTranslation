#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main()
{
  int n, k;
  cin >> n >> k;
  ll cnt = 0;
  for (int b = 1; b <= n; ++b)
  {
    int p = n / b;
    if (b > k)
    {
      cnt += p * (b - k);
      int r = n % b;
      if (r >= k)
        cnt += r - k + 1;
      if (k == 0)
        cnt--;
    }
  }
  cout << cnt << endl;

  return 0;
}
