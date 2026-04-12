#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  int N; cin >> N;
  string s; cin >> s;
  s += s[0];
  string SSWWS("SSWWS");
  string ans;
  for(int i = 0; i < 4; ++i) {
    string res = SSWWS.substr(i, 2);
    for(int j = 1; j < N; ++j) {
      for(int k = 0; k < 4; ++k) {
        if(res.substr(j-1, 2) == SSWWS.substr(k, 2)) res += (s[j] == 'o') ? "SW"[k%2] : "WS"[k%2];
      }
    }
    if(res.back() != res.front()) continue;

    bool ok = false;
    for(int k = 0; k < 4; ++k) {
      if(res.substr(N-1, 2) == SSWWS.substr(k, 2)) {
        if((s[0] == 'o' && res[1] == "SW"[k%2]) || (s[0] == 'x' && res[1] == "WS"[k%2])) ok = true;
      }
    }
    if(ok) ans = res.substr(0, N);
  }

  cout << ((ans.empty()) ? "-1" : ans) << endl;

  return 0;
}
