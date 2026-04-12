#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<string> a({"SS", "WW", "SW", "WS"});
  bool yes = false;
  string res;
  for(int i=0;i<a.size();i++) {
    string ans = a[i];
    for(int i=1;i<n-1;i++) {
      if(ans[i] == 'S') {
        if(s[i] == 'o') ans += ans[i-1];
        else if(ans[i-1] == 'S') ans += 'W';
        else ans += 'S';
      }
      else {
        if(s[i] == 'x') ans += ans[i-1];
        else if(ans[i-1] == 'S') ans += 'W';
        else ans += 'S';
      }
    }
    if(ans[n-1] == 'W') {
      if(s[n-1] == 'x' && ans[n-2] != ans[0]) continue;
      else if(s[n-1] == 'o' && ans[n-2] == ans[0]) continue;
    }
    else if(ans[n-1] == 'S') {
      if(s[n-1] == 'o' && ans[n-2] != ans[0]) continue;
      else if(s[n-1] == 'x' && ans[n-2] == ans[0]) continue;
    }

    if(ans[0] == 'W') {
      if(s[0] == 'x' && ans[1] != ans[n-1]) continue;
      else if(s[0] == 'o' && ans[1] == ans[n-1]) continue;
    }
    else if(ans[0] == 'S') {
      if(s[0] == 'o' && ans[1] != ans[n-1]) continue;
      else if(s[0] == 'x' && ans[1] == ans[n-1]) continue;
    }

    yes = true;
    res = ans;
    break;
  }
  if(yes) cout << res << endl;
  else cout << -1 << endl;
}
