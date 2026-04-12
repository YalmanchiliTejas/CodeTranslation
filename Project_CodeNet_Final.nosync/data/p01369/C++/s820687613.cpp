#include <bits/stdc++.h>
using namespace std;

const string R = "yuiophjklnm";

int main() {
  for(string s; cin >> s && s != "#"; ) {
    int res = 0;
    for(int i = 1; i < s.size(); ++i) {
      res += (R.find(s[i-1]) == string::npos) ^ (R.find(s[i]) == string::npos );
    }
    cout << res << endl;
  }
  return 0;
}