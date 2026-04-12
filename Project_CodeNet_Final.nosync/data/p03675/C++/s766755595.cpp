#include <bits/stdc++.h>

using namespace std;

typedef long long int llint;

int n;
vector<llint> a;
deque<llint> b;

void input() {
  cin >> n;
  a = vector<llint>(n);
  //b = deque<llint>(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
}

void solve() {
  if (n & 1) {
    for (int i = 0; i < n; ++i) {
      if (i & 1) {
        b.push_back(a[i]);
      } else {
        b.push_front(a[i]);
      }
    }
  } else {
    for (int i = 0; i < n; ++i) {
      if (i & 1) {
        b.push_front(a[i]);
      } else {
        b.push_back(a[i]);
      }
    }
  }

  for (auto& it : b) {
    cout << it << " ";
  }
  cout << endl;
}

int main() {
  input();
  solve();
  return 0;
}