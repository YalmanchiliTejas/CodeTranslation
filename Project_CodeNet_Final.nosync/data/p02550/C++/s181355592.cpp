#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t n, x, m;
  cin >> n >> x >> m;
  vector<int64_t> A(m, -1), S(m + 1, 0);
  int64_t ai = x;
  for (int i = 1; i <= m; i++)
  {
    if (A.at(ai) == -1)
    {
      A.at(ai) = i;
      S.at(i) = S.at(i - 1) + ai;
      ai = ai * ai % m;
      if (ai == 0 || i == n)
      {
        cout << S.at(i) << endl;
        return 0;
      }
    }
    else
    {
      int64_t ans = 0;
      ans += S.at(A.at(ai) - 1); // ループに入るまで
      n -= A.at(ai) - 1;
      ans += (S.at(i - 1) - S.at(A.at(ai) - 1)) * (n / (i - A.at(ai)));
      n %= (i - A.at(ai));
      ans += S.at(A.at(ai) - 1 + n) - S.at(A.at(ai) - 1);
      cout << ans << endl;
      return 0;
    }
  }
}