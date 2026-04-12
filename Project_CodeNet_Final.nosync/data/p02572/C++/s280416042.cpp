#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  vector<uintmax_t> a;
  uintmax_t add_sum, r_sum = 0, divider = pow(10, 9) + 7;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    uintmax_t tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  sort(a.begin(), a.end());

  add_sum = a[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    r_sum += a[i] * add_sum % divider;
    add_sum += a[i];
    r_sum %= divider;
    add_sum %= divider;
  }

  cout << r_sum << endl;
}
