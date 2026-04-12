#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> v) {
  int d = v[0];
  for (int i = 1; i < v.size(); i++) {
    if (d >= 10)  d = max(v[i], d - 10);
    else return false;
  }
  return true;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> d(n);
  for (auto& e : d) cin >> e;
  vector<int> rd(d);
  reverse(rd.begin(), rd.end());
  cout << (solve(d) && solve(rd) ? "yes\n" : "no\n");
}
