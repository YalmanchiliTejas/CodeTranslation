#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = (ll)1e9 + 7;

void cal(vector<int>& pat, string& s)
{
  int N = s.size();
  for (int i = 1; i < N - 1; ++i) {
    if (pat[i] == 0) {
      // sheep
      if (s[i] == 'o') {
        pat[i + 1] = pat[i - 1];
      }
      else {
        pat[i + 1] = 1 - pat[i - 1];
      }
    }
    else {
      // wolf
      if (s[i] == 'o') {
        pat[i + 1] = 1 - pat[i - 1];
      }
      else {
        pat[i + 1] = pat[i - 1];
      }
    }
  }
}

bool is_ok(string& s, vector<int>& pat)
{
  int N = s.size();
  for (int i = 0; i < N; ++i) {
    int prev = (i - 1 + N) % N;
    int next  = (i + 1) % N;
    if (s[i] == 'o') {
      if (pat[i] == 0 and pat[prev] != pat[next]) {
        return false;
      }
      else if (pat[i] == 1 and pat[prev] == pat[next]) {
        return false;
      }
    }
    else if (s[i] == 'x') {
      if (pat[i] == 0 and pat[prev] == pat[next]) {
        return false;
      }
      else if (pat[i] == 1 and pat[prev] != pat[next]) {
        return false;
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
  vector<int> pat(N, -1);
  for (int i = 0; not done and i <= 1; ++i) {
    pat[0] = i;
    for (int j = 0; not done and j <= 1; ++j) {
      pat[1] = j;
      cal(pat, s);
      if (is_ok(s, pat)) {
        done = true;
        break;
      }
    }
  }
  if (not done) {
    printf("-1\n");
    return 0;
  }
  for_each(pat.begin(), pat.end(), [](const int& val) -> void {
      printf("%c", (val == 0) ? 'S' : 'W');
    });
  printf("\n");
  return 0;
}
