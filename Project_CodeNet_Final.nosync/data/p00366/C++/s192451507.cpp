#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> t(n);
  int i;
  for (i = 0; i < n; i++) {
    cin >> t[i];
  }
  sort(t.begin(), t.end());
  vector<int> divisor(n);
  int count = 0;
  for (i = 1; i <= t[n - 1]; i++) {
    if (t[n - 1] % i == 0) {
      divisor[count] = i;
      count++;
    }
  }
  int result = 0;
  count = 0;
  for (i = 0; i < n; i++) {
    while (t[i] > divisor[count]) {
      count++;
    }
    result += divisor[count] - t[i];
  }
  cout << result << endl;
  return 0;
}

