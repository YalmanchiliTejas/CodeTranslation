#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<uint64_t> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  uint64_t div = 1000000000 + 7;

  uint64_t sig = 0;
  for (int i = 0; i < n; i++)
  {
    sig += a[i];
  }

  vector<uint64_t> sig_(n);
  for (int i = 0; i < n; i++)
  {
    sig = sig - a[i];
    sig_[i] = sig % div;
    // cout << sig_[i] << endl;
  }

  uint64_t sum = 0;
  for (int i = 0; i < n - 1; i++)
  {
    uint64_t p = a[i] * sig_[i];

    sum += p % div;
    sum = sum % div;
  }

  cout << sum << endl;
  return 0;
}