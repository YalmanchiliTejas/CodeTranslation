#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> v;
  rep(i,h)
  {
    string s;
    cin >> s;
    int f = 0;
    rep(j,s.size())
    {
      if (s[j] == '#') {
        f = 1;
        break;
      }
    }
    if (f)
      v.push_back(s);
  }
  for (int i = w - 1; i >= 0; i--) {
    int f = 0;
    rep(j,v.size())
    {
      if (v[j][i] == '#') {
        f = 1;
        break;
      }
    }
    if (!f)
      rep(j,v.size())
        v[j].erase(i, 1);
  }
  rep(i,v.size())
    cout << v[i] << endl;
  return 0;
}