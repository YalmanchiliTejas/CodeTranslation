#include <bits/stdc++.h>
using namespace std;

bool izryt(vector<int> &v) {
  int d = 0;
  bool res = true;
  for (int i = 0; i < v.size(); ++i) {
    if (i > d) {
      res = false;
      break;
    }

    d = max(d, i + v[i]);
  }

  return res;
}

int main() {
  int n;
  cin >> n;

  vector<int> d(n);
  for (auto &i : d) cin >> i;
  for (auto &i : d) i /= 10;

  bool ans = true;
  if (!izryt(d)) ans = false;
  reverse(d.begin(), d.end());
  if (!izryt(d)) ans = false;

  cout << (ans ? "yes" : "no") << endl;
}