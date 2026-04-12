#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];

  vector<int> b(n);
  if (n % 2 == 0) {
    int j = 0;
    for (int i = n - 1; i >= 0; i -= 2) {
      b[j] = a[i];
      j++;
    }
    for (int i = 0; i < n; i += 2) {
      b[j] = a[i];
      j++;
    }
  } else {
    int j = 0;
    for (int i = n - 1; i >= 0; i -= 2) {
      b[j] = a[i];
      j++;
    }
    for (int i = 1; i < n; i += 2) {
      b[j] = a[i];
      j++;
    }
  }

  for (int i = 0; i < b.size(); i++) {
    if (i == b.size() - 1) cout << b[i] << endl;
    else cout << b[i] << " ";
  }

  return 0;
}