#include <bits/stdc++.h>

using namespace std;

long long a[55];
long long res;
long long n;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  while (1) {
    long long mx = -1, idx = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] > mx) {
        mx = a[i];
        idx = i;
      }
    }
    if (mx < n) break; 
    long long tmp = a[idx] / n;
    res += tmp;
    a[idx] -= tmp * n;
    for (int i = 0; i < n; i++) {
      if (i == idx) continue;
      a[i] += tmp;
    }  
  }
  cout << res << "\n";
  return 0;
}