#include <iostream>

using namespace std;

int main() {
  int n, t, e;
  int x[100];
  cin >> n >> t >> e;
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  for (int i = 0; i < n; ++i) {
    if (((t - e) / x[i] + 1) * x[i] <= t + e) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}