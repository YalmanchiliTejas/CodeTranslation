#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int mod1 = 1000000007;
bool is_integer(double x)
{
  return floor(x) == ceil(x);
}
int main()
{
  int n;
  long long int a[200000];
  long long int b[200000] = {0};
  long long int sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = n - 2; i >= 0; i--)
  {
    b[i] = (b[i + 1] + a[i + 1]) % mod1;
  }
  for (int i = 0; i < n - 1; i++)
  {
    sum += (a[i] * b[i]) % mod1;
    sum %= mod1;
  }
  cout << sum << endl;
}
