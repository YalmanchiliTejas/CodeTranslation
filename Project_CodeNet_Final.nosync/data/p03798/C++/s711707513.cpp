#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll n; cin >> n;
  string s; cin >> s;
  vector <ll> x = {1, 1, -1, -1};
  vector <ll> y = {1, -1, 1, -1};
  bool flag = 1;
  rep(i, 4) {
    vector <ll> v(n);
    v.at(0) = x.at(i), v.at(1) = y.at(i);
    for (ll j = 1; j < n-1; j++) {
      if (v.at(j) > 0) {
        if (s.at(j) == 'o') v.at(j+1) = v.at(j-1);
        else v.at(j+1) = -v.at(j-1);
      } else {
        if (s.at(j) == 'o') v.at(j+1) = -v.at(j-1);
        else v.at(j+1) = v.at(j-1);
      }
    }
    bool sub_flag = 1;
    if (v.at(n-1) > 0) {
      if (s.at(n-1) == 'o') {
        if (v.at(n-2) == v.at(0)) sub_flag = 0;
      } else {
        if (v.at(n-2) != v.at(0)) sub_flag = 0;
      }
    } else {
      if (s.at(n-1) == 'o') {
        if (v.at(n-2) != v.at(0)) sub_flag = 0;
      } else {
        if (v.at(n-2) == v.at(0)) sub_flag = 0;
      }
    }
    if (!sub_flag) {
      if (v.at(0) > 0) {
        if (s.at(0) == 'o') {
          if (v.at(n-1) == v.at(1)) flag = 0;
        } else {
          if (v.at(n-1) != v.at(1)) flag = 0;
        }
      } else {
        if (s.at(0) == 'o') {
          if (v.at(n-1) != v.at(1)) flag = 0;
        } else {
          if (v.at(n-1) == v.at(1)) flag = 0;
        }
      }
    }
    if (!flag) {
      rep(i, n) {
        if (v.at(i) > 0) cout << 'S';
        else cout << 'W';
      }
      cout << endl;
      break;
    }
  }
  if (flag) cout << -1 << endl;
}