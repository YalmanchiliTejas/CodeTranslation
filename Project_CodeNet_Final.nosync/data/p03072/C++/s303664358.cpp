// Created by martinezdiego on 23/4/19

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> mountains(n);
  for (auto & i: mountains) {
    cin >> i;
  }
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    bool ok = true;
    for (int j = 0; j < i; j++) {
      if (mountains[j] > mountains[i]) {
        ok = false;
        break;
      }
    }
    if (ok) cnt++;
  }
  cout << cnt + 1 << '\n';
}