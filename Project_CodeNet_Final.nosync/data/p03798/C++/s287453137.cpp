#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  string s;
  cin >> n >> s;

  vector<char> ans(n, '\0');
  auto solve = [&]() -> bool {
    bool ok = true;
    for (int i = 0; i < s.size() && ok; ++i) {
      int a = i != 0 ? i - 1 : s.size() - 1;
      int b = i != s.size() - 1 ? i + 1 : 0;
      if (a > b) {
        swap(a, b);
      }

      bool same =
          (ans[i] == 'S' && s[i] == 'o') || (ans[i] == 'W' && s[i] == 'x');
      char ans_b;
      if (same) {
        ans_b = ans[a];
      } else {
        ans_b = ans[a] == 'S' ? 'W' : 'S';
      }

      if (s.size() - i <= 2) {
        ok = ans[b] == ans_b;
      } else {
        ans[b] = ans_b;
      }
    }

    return ok;
  };

  vector<array<char, 2>> pat{{'S', 'S'}, {'W', 'W'}, {'S', 'W'}, {'W', 'S'}};
  for (auto p : pat) {
    fill(ans.begin(), ans.end(), '\0');
    ans[0] = p[0];
    ans[1] = p[1];

    if (solve()) {
      cout << string(ans.begin(), ans.end()) << '\n';
      return 0;
    }
  }

  cout << -1 << '\n';
  return 0;
}