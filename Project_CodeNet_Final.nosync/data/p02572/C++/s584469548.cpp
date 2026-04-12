#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n;
  cin >> n;
  long long kMod = 1e9+7;
  long long res = 0;
  long long total = 0;
  cin >> total;
  for (long long i = 1; i < n; i++) {
    long long tmp;
    cin >> tmp;
    res += tmp * total;
    res %= kMod;
    total += tmp;
    total %= kMod;
  }
  cout << res << '\n';
  return 0;
}
