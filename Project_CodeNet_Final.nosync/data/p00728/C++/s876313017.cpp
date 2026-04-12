#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, s;
  int v[110];

  while (cin >> n && n > 0) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> s;
      sum += s;
      v[i] = s;
    }
    sort(v, v + n);
    sum -= v[0];
    sum -= v[n-1];
    cout << sum/(n-2) << endl;
  }

  return 0;
}
