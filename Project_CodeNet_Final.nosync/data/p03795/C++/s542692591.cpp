#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

int f(long long N)
{
  long long d = 2;
  long long ans = 0;
  while (1)
  {
    if (N % d <= d / 2 - 1)
    {
      ans += d / 2;
    }
  }
  return ans;
}
int main()
{
  int N;
  cin >> N;
  cout << N * 800 - (N / 15) * 200 << endl;
}