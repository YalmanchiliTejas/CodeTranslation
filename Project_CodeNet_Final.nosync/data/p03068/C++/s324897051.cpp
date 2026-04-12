#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  string s;
  cin >> n >> s >> k;
  char c = s[k - 1];
  rep(i, n) {
    if (s[i] != c) {
      s[i] = '*';
    }
  }
  cout << s;
  return 0;
}
