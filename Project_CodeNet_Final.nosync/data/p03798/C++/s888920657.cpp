#include <bits/stdc++.h>
using namespace std;

// SW配列とox配列に矛盾があればfalse, 無ければtrue
bool check(string s, string t) {
  int n = s.size();
  for (int i = 0; i < n; i++) {
    int l = i - 1;
    if (l < 0) l = n - 1;
    int r = i + 1;
    if (r >= n) r = 0;
    if (s.at(i) == 'S' && t.at(i) == 'o') if (s.at(l) != s.at(r)) return false;
    if (s.at(i) == 'S' && t.at(i) == 'x') if (s.at(l) == s.at(r)) return false;
    if (s.at(i) == 'W' && t.at(i) == 'o') if (s.at(l) == s.at(r)) return false;
    if (s.at(i) == 'W' && t.at(i) == 'x') if (s.at(l) != s.at(r)) return false;
  }
  return true;
}

// 決め打ちされた1番2番を元にSW配列を生成
string make(string s, string t) {
  int n = t.size();
  for (int i = 1; i < n - 1; i++) {
    char pre = s.at(i - 1);
    if (s.at(i) == 'S' && t.at(i) == 'o') s += pre;
    if (s.at(i) == 'S' && t.at(i) == 'x') s += char('S' ^ 'W' ^ pre);
    if (s.at(i) == 'W' && t.at(i) == 'o') s += char('S' ^ 'W' ^ pre);
    if (s.at(i) == 'W' && t.at(i) == 'x') s += pre;
  }
  return s;
}

int main() {
  int N;
  string S;
  cin >> N >> S;
  for (auto s : {"SS", "SW", "WS", "WW"}) { // 1番2番を決め打ち
    string ans = make(s, S);
    if (check(ans, S)) return cout << ans << "\n", 0;
  }
  cout << -1 << "\n";
}