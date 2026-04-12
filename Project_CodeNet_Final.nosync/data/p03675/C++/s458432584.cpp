#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  list<int> b;
  if (n % 2 == 0) {
    for (int i = 0; i < n; i++) {
      if (i & 1) {
        b.push_front(a[i]);
      } else {
        b.push_back(a[i]);
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (i & 1) {
        b.push_back(a[i]);
      } else {
        b.push_front(a[i]);
      }
    }
  }

  for (list<int>::iterator it = b.begin(); it != b.end(); it++) {
    if (it != b.begin()) cout << " ";
    cout << *it;
  }
  cout << endl;

  return 0;
}