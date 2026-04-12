#include <iostream>
#include <algorithm>
using namespace std;
char sorw(char c) {
  if (c == 'S') {
    return 'W';
  } else {
    return 'S';
  }
}
string zoo(int n, string s1, string s2) {
  for ( ; n < s1.size(); n++) {
    if ((s1[n] == 'o' && s2[n] == 'S') || (s1[n] == 'x' && s2[n] == 'W')) {
      s2.push_back(s2[n - 1]);
    } else {
      s2.push_back(sorw(s2[n - 1]));
    }
  }
  return s2;
}

bool check(string s) {
  return (s[0] == s[s.size() - 2] && s[1] == s[s.size()  - 1]);
}
int main(void) {
  int n;
  string s;
  cin >> n >> s;
  s.push_back(s[0]);
  string ss = zoo(1, s, "SS");
  string sw = zoo(1, s, "SW");
  string ws = zoo(1, s, "WS");
  string ww = zoo(1, s, "WW");
  if (check(ss)) {
    cout << ss.erase(ss.size() - 2) << endl;
  } else if (check(sw)) {
    cout << sw.erase(sw.size() - 2) << endl;
  } else if (check(ws)) {
    cout << ws.erase(ws.size() - 2) << endl;
  } else if (check(ww)) {
    cout << ww.erase(ww.size() - 2) << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}