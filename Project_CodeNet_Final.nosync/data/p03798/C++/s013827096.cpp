#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
string s, ans = "-1";

char rev(char c) {
  return c == 'S' ? 'W' : 'S';
}

void f(string t) {
  string w = s;
  w[0] = t[0];
  w[1] = t[1];
  for (int i = 1; i < n - 1; i++) {
    if (w[i] == 'S') {
      if (s[i] == 'o') w[i + 1] = w[i - 1];
      else w[i + 1] = rev(w[i - 1]);
    } else {
      if (s[i] == 'o') w[i + 1] = rev(w[i - 1]);
      else w[i + 1] = w[i - 1];
    }
  }
  
  bool ok = true;
  for (int i = 0; i < n; i++) {
    int l = (i - 1 + n) % n, r = (i + 1) % n;
    if (w[i] == 'S') {
      if (s[i] == 'o' && w[l] != w[r]) ok = false;
      if (s[i] == 'x' && w[l] == w[r]) ok = false;
    } else {
      if (s[i] == 'o' && w[l] == w[r]) ok = false;
      if (s[i] == 'x' && w[l] != w[r]) ok = false;
    }
  }
  if (ok) ans = w;
}

int main() {
  cin >> n >> s;

  f("SS");
  f("SW");
  f("WS");
  f("WW");
  cout << ans << endl;

  return 0;
}