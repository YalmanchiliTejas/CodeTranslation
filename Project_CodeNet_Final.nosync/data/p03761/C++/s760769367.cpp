#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<int> alpha(26,51);
  for (int  i = 0; i < n; i++) {
    vector<int> tmp(26);
    for (char c : s[i]) {
      tmp[c - '0' - 49]++;
    }
   for(int j = 0; j < 26; j++) {
      alpha[j] = min(tmp[j], alpha[j]);
    }
  }
  for (int i = 0; i < 26; i++) {
    for(int j = 0; j < alpha[i]; j++){
      char r = (i + 49) + '0';
      cout << r;
    }
  }

}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
