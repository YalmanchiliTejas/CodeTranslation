#include <iostream>
#include <vector>
using namespace std;

int N;
long X;
long p[51] = {};
long s[51] = {};

long f(int N, long X)
{
  if (N == 0)
    return 1;
  else if (X == 1)
    return 0;
  else if (X <= s[N - 1] + 1)
    return f(N - 1, X - 1);
  else if (X == s[N - 1] + 2)
    return f(N - 1, X - 2) + 1;
  else if (X <= 2 * s[N - 1] + 2)
    return p[N - 1] + 1 + f(N - 1, X - s[N - 1] - 2);
  else
    return p[N];
}

int main()
{
  cin >> N >> X;
  p[0] = 1;
  s[0] = 1;
  for (int i = 1; i <= N; i++)
  {
    p[i] = 2 * p[i - 1] + 1;
    s[i] = 2 * s[i - 1] + 3;
  }
  cout << f(N, X) << endl;
  return 0;
}