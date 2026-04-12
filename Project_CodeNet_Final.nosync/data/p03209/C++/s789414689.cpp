#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <typeinfo>
//#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

long long numburger(int n)
{
  if (n == 0)
  {
    return 1;
  }
  else
  {
    return 2 * numburger(n - 1) + 3;
  }
}

long long numpatty(int n)
{
  if (n == 0)
  {
    return 1;
  }
  else
  {
    return 1 + numpatty(n - 1) * 2;
  }
}

long long answer(int n, long long x)
{
  if (n == 0)
  {
    if (x <= 0)
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }
  if (x == 1)
  {
    return 0;
  }
  long long numB = numburger(n - 1);
  if (1 < x && x <= 1 + numB)
  {
    return answer(n - 1, x - 1);
  }
  else if (x == 2 + numB)
  {
    return numpatty(n - 1) + 1;
  }
  else if (2 + numB < x && x <= 2 + 2 * numB)
  {
    return numpatty(n - 1) + 1 + answer(n - 1, x - 2 - numB);
  }
  else if (x == 3 + 2 * numB)
  {
    return 2 * numpatty(n - 1) + 1;
  }
}

int main()
{
  int n;
  long long x;
  cin >> n >> x;

  cout << answer(n, x) << endl;

  return 0;
}