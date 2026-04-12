#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long int N, X, L[60] = {1}, P[60] = {1};

unsigned long int p_calc(unsigned long long N, unsigned long long X)
{
  if (X < 1)
  {
    return 0;
  }
  else if (N == 0)
  {
    return 1;
  }
  else if (X <= 1 + L[N - 1])
  {
    return p_calc(N - 1, X - 1);
  }
  // else if (X == 2 + L[N - 1])
  // {
  //   return P[N - 1] + 1;
  // }
  else // if (X <= 2 + 2 * L[N - 1])
  {
    return P[N - 1] + 1 + p_calc(N - 1, X - 1 - L[N - 1] - 1);
  }
  // else if (X == 3 + 2 * L[N - 1])
  // {
  //   return 2 * P[N - 1] + 1;
  // }
}

int main()
{
  unsigned int a, b, c, sum, count = 0, temp = 0;
  cin >> N >> X;
  // N = 2, X = 7;
  // N = 50, X = 4321098765432109;

  for (int i = 1; i <= N; i++)
  {
    L[i] = 2 * L[i - 1] + 3;
    P[i] = 2 * P[i - 1] + 1;
  }
  // cout << L[N] << endl;
  // cout << P[N] << endl;
  cout << p_calc(N, X) << endl;

  return 0;
}