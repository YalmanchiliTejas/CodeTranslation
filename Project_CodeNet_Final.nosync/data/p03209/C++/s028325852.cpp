#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, n, X, x = 1, p = 1, ans = 0;
  cin >> N >> X;
  X--;
  stack<int64_t> A, P;
  for (int64_t i = 0; i <= N; i++)
  {
    A.push(x);
    x = 2 * x + 3;
    P.push(p);
    p = 2 * p + 1;
  }
  while (!A.empty())
  {
    n = A.top(), p = P.top();
    A.pop();
    P.pop();
    if (X == n / 2)
    {
      ans += p / 2 + 1;
      break;
    }
    else if (X > n / 2)
    {
      ans += p / 2 + 1;
      X = X - n / 2 - 1;
    }
    else
    {
      X--;
    }
  }
  cout << ans << endl;
}