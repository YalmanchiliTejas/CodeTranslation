#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  int alpha[26] = {};
  rep(i, n) {
    string s;
    cin >> s;
    if (i == 0) {
      for (char c : s) alpha[c - 'a']++;
    } else {
      int tmp_alpha[26] = {};
      for (char c : s) tmp_alpha[c - 'a']++;
      rep(i, 26) {
        if (alpha[i] > tmp_alpha[i]) alpha[i] = tmp_alpha[i];
      }
    }
  }
  int sum = 0;
  string ans = {};
  rep(i, 26) sum += alpha[i];
  if (sum == 0) {
    cout << ans << endl;
  } else {
    rep(i, 26) ans += string(alpha[i], 'a' + i);
    cout << ans << endl;
  }
  return 0;
}