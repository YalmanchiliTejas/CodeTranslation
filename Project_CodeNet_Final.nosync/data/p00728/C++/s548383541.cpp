#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    
    int minimum = 1e3, maximum = 0, sum = 0;
    for (int i = 0; i < n; i++) {
      int s;
      cin >> s;
      sum += s;
      minimum = min(minimum, s);
      maximum = max(maximum, s);
    }
    
    cout << (sum - minimum - maximum) / (n - 2) << '\n';
  }
}
