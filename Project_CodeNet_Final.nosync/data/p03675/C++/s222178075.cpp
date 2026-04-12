#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  deque<int> q;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (i % 2 == n % 2) {
      q.push_back(a);
    } else {
      q.push_front(a);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << q.at(i);
    if (i == n - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
}
