#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int count = 0;
  for (int i = n-1; i > -1; i-=2) {
    cout << a[i] << " ";
  }
  if (a.size()%2 == 0) {
    for (int i = 0; i < n-1; i +=2) {
      if (i!=n-2) {
        cout << a[i] << " ";
      }
      else {
        cout << a[i];
      }
    }
  }
  else {
    for (int i = 1; i < n-1; i+=2) {
      if (i!=n-2) {
        cout << a[i] << " ";
      }
      else {
        cout << a[i];
      }
    }
  }
}