#include <bits/stdc++.h>
using namespace std;

string s;
int a, b, c, d;

string solve();

int main() {
  while(1) {
    cin >> s;
    if(s == "#") break;
    cin >> a >> b >> c >> d;
    --a, --b, --c, --d;
    cout << solve() << endl;
  }
  return 0;
}

string solve() {
  int cntsls = 1, now = 0;
  vector<string> v;
  for(int i = 0; i < s.size(); ++i)
    if(s[i] == '/') ++cntsls;
  v.resize(cntsls);
  for(int i = 0; i < s.size(); ++i) {
    if(s[i] == 'b')
      v[now] += 'b';
    else if(s[i] == '/')
      ++now;
    else
      for(char j = '0'; j < s[i]; ++j) v[now] += '.';
  }
  swap(v[a][b], v[c][d]);
  string ans;
  for(int i = 0; i < cntsls; ++i) {
    int nowsize = v[i].size(), cnt = 0, id = 0;
    while(1) {
      if(id == nowsize) break;
      if(v[i][id] == 'b') {
        ans += 'b';
        ++id;
        continue;
      }
      cnt = 0;
      while(id < nowsize && v[i][id] != 'b') ++cnt, ++id;
      ans += '0' + cnt;
    }
    if(i != cntsls - 1) ans += '/';
  }
  return ans;
}
