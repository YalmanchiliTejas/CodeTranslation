#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;

int main() {
  string s; cin >> s;
  if (s.at(0) != s.at(1) || s.at(1) != s.at(2)){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}
