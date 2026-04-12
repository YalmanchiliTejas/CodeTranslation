#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = (ll)1e9 + 7;

bool check(vector<int>& v, string s)
{
  int n = s.size();
  for (int i = 2; i < n; ++i) {
    if (s[i - 1] == 'o') {
      if (v[i - 1] == 0) { v[i] = v[i - 2]; }
      else { v[i] = 1 - v[i - 2]; }
    }
    else if (s[i - 1] == 'x') {
      if (v[i - 1] == 0) { v[i] = 1 - v[i - 2]; }
      else { v[i] = v[i - 2]; }
    }
  }

  vector<int> w = v;
  w.push_back(v[0]);
  w.push_back(v[1]);
  string t = s;
  t.push_back(s[0]);
  t.push_back(s[1]);
  for (int i = 1; i <= n; ++i) {
    if (t[i] == 'o') {
      if (w[i] == 0) {
        if (w[i - 1] != w[i + 1]) { return false; }
      }
      else {
        if (w[i - 1] == w[i + 1]) { return false; }
      }
    }
    else if (t[i] == 'x') {
      if (w[i] == 0) {
        if (w[i - 1] == w[i + 1]) { return false; }
      }
      else {
        if (w[i - 1] != w[i + 1]) { return false; }
      }
    }
  }
  return true;
}

int main()
{
  int N; scanf("%d", &N);
  string s; cin >> s;

  bool done = false;
  vector<int> ans;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      vector<int> tmp(N);
      tmp[0] = i; tmp[1] = j;
      if (check(tmp, s)) {
        ans = tmp;
        done = true;
        break;
      }
    }
    if (done) { break; }
  }

  if (not done) {
    printf("-1\n");
  }
  else {
    string sw = "SW";
    for (int i = 0; i < N; ++i) {
      printf("%c", sw[ans[i]]);
    }
    printf("\n");
  }
  return 0;
}
