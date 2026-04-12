#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int mul(int x, int y) {
  return x * 1ll * y % mod;
}

int add(int x, int y) {
  return (x + y) % mod;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int sum = 0;
  int jsum = 0;
  for (int i = n-2; i >= 0; --i) {
    jsum = add(jsum, a[i+1]);
    sum = add(sum, mul(a[i], jsum));
  }
  cout << sum << '\n';
  return 0;
}
