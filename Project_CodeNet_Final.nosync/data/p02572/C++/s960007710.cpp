// Problem URL: https://atcoder.jp/contests/abc177/tasks/abc177_c
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  long long product = 0;
  vector<long long> a(n, 0);
  long long sum = 0;
  long long mod = 1000000007;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    sum %= mod;
  }
  for (long long i = 0; i < n; i++) {
    sum -= a[i];
    if(sum < 0) sum += mod;
    product += a[i] * sum;
    product %= mod;
  }
  cout << product;
  return 0;
}
