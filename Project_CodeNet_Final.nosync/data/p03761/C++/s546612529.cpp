#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s[55];

int main() {
  // 入力
  cin >> n;
  for (int i=0; i<n; i++) cin >> s[i];
  // aから順に全部の文字列に共通してある個数を数えて、それを結合したものが答え
  string ans = "";
  for (char c='a'; c<='z'; c++) {
    int mini = 100;
    for (int i=0; i<n; i++) {
      int cnt = 0;
      for (int j=0; j<s[i].size(); j++) {
        if (s[i][j] == c) cnt++;
      }
      mini = min(mini, cnt);
    }
    for (int i=0; i<mini; i++) {
      ans += c;
    }
  }
  // 解答
  cout << ans << endl;
  return 0;
}
