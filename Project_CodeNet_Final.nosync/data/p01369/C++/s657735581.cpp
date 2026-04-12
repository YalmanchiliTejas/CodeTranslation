#include <iostream>
#include <string>
using namespace std;
int main() {
  string S, R = "yuiophjklnm";
  while (cin >> S, S != "#") {
    int ans = -1, s = 0, t, l;
    size_t m = -1;
    l = S.size();
    for (int i = 0; i < l; ++i) {
      if (R.find(S[i]) != m) t = 1;
      else t = -1;
      if (t != s) ++ans;
      s = t;
    }
    cout << ans << endl;
  }
}