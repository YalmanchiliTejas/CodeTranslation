#define REPI(i, n) for (int i = 0; i < n; i++)
#define REPD(i, n) for (int i = n; i > 0; i--)

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int x[n], X[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    X[i] = x[i];
  }
  sort(X, X + n);
  int a = X[n / 2 - 1], b = X[n / 2];
  for (int i = 0; i < n; i++) {
    if (x[i] < b)
      cout << b << endl;
    else
      cout << a << endl;
  }
  return 0;
}
