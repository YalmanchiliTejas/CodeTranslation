#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int, string> P;
int n;
string s;

int main() {
  cin >> n;
  P p[n];
  for (int i=0; i<n; i++) {
    cin >> s;
    p[i] = P((int)s.size(), s);
  }
  // 全部の文字列に共通する文字を追加していって、最後に昇順に並び替えて出力
  sort(p, p+n);
  string ans = "";
  bool flag;
  for (int i=0; i<p[0].first; i++) {
    flag = true;
    for (int j=1; j<n; j++) {
      int cnt = 0;
      for (int k=0; k<p[j].first; k++) {
        if (p[j].second[k] != p[0].second[i]) {
          cnt++;
        } else {
          p[j].second.erase(p[j].second.begin() + k);
          break;
        }
      }
      if (cnt == p[j].first) {
        flag = false;
        break;
      }
    }
    if (flag) ans += p[0].second[i];
  }
  sort(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
