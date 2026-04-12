#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = (ll)1e9 + 7;

bool check(string& t, string& s)
{
  int n = s.size();
  for (int i = 2; i < n; ++i) {
    if (t[i - 1] == 'W') {
      if (s[i - 1] == 'o') {
        t[i] = (t[i - 2] == 'W') ? 'S' : 'W';
      }
      else if (s[i - 1] == 'x') {
        t[i] = (t[i - 2] == 'W') ? 'W' : 'S';
      }
    }
    else if (t[i - 1] == 'S') {
      if (s[i - 1] == 'o') {
        t[i] = (t[i - 2] == 'W') ? 'W' : 'S';
      }
      else if (s[i - 1] == 'x') {
        t[i] = (t[i - 2] == 'W') ? 'S' : 'W';
      }
    }
  }

  bool ok = true;
  if (t[n - 1] == 'S') {
    if (s[n - 1] == 'o') {
      ok = ok and t[n - 2] == t[0];
    }
    else {
      ok = ok and t[n - 2] != t[0];
    }
  }
  else if (t[n - 1] == 'W') {
    if (s[n - 1] == 'o') {
      ok = ok and t[n - 2] != t[0];
    }
    else {
      ok = ok and t[n - 2] == t[0];
    }
  }

  if (t[0] == 'S') {
    if (s[0] == 'o') {
      return ok and t[n - 1] == t[1];
    }
    else {
      return ok and t[n - 1] != t[1];
    }
  }
  else if (t[0] == 'W') {
    if (s[0] == 'o') {
      return ok and t[n - 1] != t[1];
    }
    else {
      return ok and t[n - 1] == t[1];
    }
  }
  return false;
}

int main()
{
  int N; scanf("%d", &N);
  string s; cin >> s;

  vector<char> ws = { 'W', 'S' };
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      string t(N, 'Z');
      t[0] = ws[i];
      t[1] = ws[j];
      if (check(t, s)) {
        printf("%s\n", t.c_str());
        return 0;
      }
    }
  }
  printf("-1\n");
  return 0;
}
