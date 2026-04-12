#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  deque<int> b;
  for(int i = 0; i < n; i++) {
    if((n % 2 == 0) == (i % 2 == 0)) {
      b.push_back(a[i]);
    }
    else {
      b.push_front(a[i]);
    }
  }

  string s;
  for(int i = 0; i < n; i++) {
    s += to_string(b[i]);
    s += " ";
  }
  s.pop_back();
  cout << s << endl;
}