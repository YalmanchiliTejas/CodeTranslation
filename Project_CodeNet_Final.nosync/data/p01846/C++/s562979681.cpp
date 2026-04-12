#include <bits/stdc++.h>

using namespace std;

int main() {
  while (true) {
    string s;
    cin >> s;
    if (s == "#") break;

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;
    int h = 1, w = 0;
    vector<string> board;
    string t = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '/') {
        board.emplace_back(t);
        t = "";
        h++;
        w = 0;
      } else {
        if (s[i] == 'b') {
          t += 'b';
          w++;
        } else {
          for (int j = 0; j < s[i] - '0'; j++) {
            w++;
            t += '.';
          }
        }
      }
    }
    board.emplace_back(t);

    board[a][b] = '.';
    board[c][d] = 'b';

    string ans = "";
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (board[i][j] == 'b') {
          ans.push_back('b');
        } else {
          if (!isdigit(ans.back()))
            ans.push_back('1');
          else
            ans.back() += 1;
        }
      }
      ans += '/';
    }
    ans.pop_back();
    cout << ans << endl;
  }

  return 0;
}
