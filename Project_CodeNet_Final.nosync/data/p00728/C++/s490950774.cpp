#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n > 0) {
    int sum = 0;
    int mx = 0;
    int mn = 10000;
    int x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      sum += x;
      if (x > mx) mx = x;
      if (x < mn) mn = x;
    }
    cout << (sum - mx - mn) / (n - 2) << endl;
    cin >> n;
  }
  return 0;
}

