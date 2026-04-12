#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  auto a = [&]() -> V<lint> {
    const string t = "FESTIVA";
    string s;
    for (int i = 0; i < 8; ++i) {
      for (char c : t) {
        s += string(1 << i, c);
      }
    }
    V<lint> dp(8);
    dp[0] = 1;
    V<lint> res;
    for (int i = 0; i < (int)s.size(); ++i) {
      auto ndp = dp;
      int j = t.find(s[i]);
      ndp[j + 1] += dp[j];
      swap(dp, ndp);
      if (s[i] == 'A' and s[i + 1] != 'A') {
        res.push_back(dp.back());
      }
    }
    return res;
  }();

  lint k; cin >> k;
  string res;
  for (int i = 7; i >= 0; --i) {
    res += string(k / a[i], 'F');
    for (char c : "ESTIVAL"s) {
      res += string(1 << i, c);
    }
    k %= a[i];
  }
  cout << res << '\n';
}