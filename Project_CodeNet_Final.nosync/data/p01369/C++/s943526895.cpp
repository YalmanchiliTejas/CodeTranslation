#include <bits/stdc++.h>
using namespace std;

set<char> l, r;

void init() {
  string ls = "qwertasdfgzxcvb";
  string rs = "yuiophjklnm";
  for (auto c : ls) l.insert(c);
  for (auto c : rs) r.insert(c);
}
int solve(const string& s) {
  auto iter = s.begin();
  bool left;
  if (l.find(*iter) != l.end()) left = true;
  else                          left = false;

  int cnt = 0;
  iter++;
  while(iter != s.end()) {
    if (left & (r.find(*iter) != r.end())) {
      left = false;
      cnt++;
    }
    else if (!left & (l.find(*iter) != l.end())) {
      left = true;
      cnt++;
    }
    iter++;
  }
  return cnt;
}

int main() {
  init();
  
  string s;
  while(cin >> s, s != "#") {
    cout << solve(s) << endl;
  }
  return 0;
}
