#include <iostream>
#include <set>
using namespace std;

set<char> r{'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm'};
string s;

void solve() {
  bool st = (r.find(s[0]) != r.end() ? 1 : 0);
  int cnt = 0;

  for(int i = 0; i < s.length(); ++i) {
    if(r.find(s[i]) != r.end()) {
      if(!st) cnt++;
      st = 1;
    }
    else {
      if(st) cnt++;
      st = 0;
    }
  }
  cout << cnt << endl;
}

int main() {
  while(cin >> s) {
    if(s == "#") break;
    solve();
  }
  return 0;
}

