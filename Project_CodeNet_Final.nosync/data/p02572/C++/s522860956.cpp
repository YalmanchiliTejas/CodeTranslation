#include <iostream>

using namespace std;

const int MOD = 1000000007;

int main() {
  int n;
  cin >> n;

  long long sum = 0, res = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    res = (res + sum * a) % MOD;
    sum = (sum + a) % MOD;
  }

  cout << res << endl;
}
