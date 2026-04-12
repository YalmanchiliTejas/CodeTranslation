#include <bits/stdc++.h>

using namespace std;


int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> b;

  for (int i = n - 1; i >= 0; i -= 2) {
    b.push_back(a[i]);
  }
  
  for (int i = (n % 2 == 0)? 0 : 1; i < n; i += 2) {
    b.push_back(a[i]);
  }

  for (int i = 0; i < n; i++) {
    cout << b[i] << " \n"[i == n - 1];
  }


  return 0;
}

/*
  1
  2 1
  3 1 2
  4 2 1 3
  5 3 1 2 4
  6 4 2 1 3 5
 */
